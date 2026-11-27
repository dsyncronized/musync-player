/* Credit goes to:
    MoThunderz for the rotary encoder implementation
*/

#include "input/input.h"
#include "oled/oled.h"
#include <Adafruit_GFX.h>
#include <Arduino.h>

void setup() {
  initializeOLED();
  initializeRotaryEncoder();

  Serial.begin(115200);
  Serial.println("start");
}

void loop() {
  static int lastCounter = 0;

  if (counter != lastCounter) {
    Serial.println(counter);
    lastCounter = counter;
  }

  display.display();
}
