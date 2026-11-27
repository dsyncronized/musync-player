#include "rotary.h"
#include "config/config.h"
#include <Arduino.h>
#include <stdint.h>

static unsigned long _lastIncReadTime = micros();
static unsigned long _lastDecReadTime = micros();
static unsigned long _pauseLength = 25000UL;
static int _fastIncrement = 4;

volatile int counter = 0;

void initializeRotaryEncoder() {
  pinMode(encoder0PinA, INPUT_PULLUP);
  pinMode(encoder0PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoder0PinA), read_encoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder0PinB), read_encoder, CHANGE);
  pinMode(encoder0Switch, INPUT);
}

void read_encoder() {
  static uint8_t old_AB = 3;
  static int8_t encval = 0;
  static const int8_t enc_states[] = {0,  -1, 1, 0, 1, 0, 0,  -1,
                                      -1, 0,  0, 1, 0, 1, -1, 0};

  old_AB <<= 2;
  if (digitalRead(encoder0PinA))
    old_AB |= 0x02; // Add current state of pin A
  if (digitalRead(encoder0PinB))
    old_AB |= 0x01; // Add current state of pin B

  encval += enc_states[(old_AB & 0x0f)];

  if (encval > 3) {
    int changevalue = 1;
    if ((micros() - _lastIncReadTime) < _pauseLength) {
      changevalue = _fastIncrement * changevalue;
    }
    _lastIncReadTime = micros();
    counter = counter + changevalue;
    encval = 0;
  } else if (encval < -3) {
    int changevalue = -1;
    if ((micros() - _lastDecReadTime) < _pauseLength) {
      changevalue = _fastIncrement * changevalue;
    }
    _lastDecReadTime = micros();
    counter = counter + changevalue;
    encval = 0;
  }
}
