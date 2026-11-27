#include "interface/menu/menu.h"
#include "oled/oled.h"
#include "rotary/rotary.h"
#include <Adafruit_GFX.h>
#include <Arduino.h>

int layer = 0;

void setup() {
  initializeOLED();
  initializeRotaryEncoder();

  Serial.begin(115200);
  Serial.println("start");

  display.println("initialized");
  display.display();
}

void loop() {
  static int lastCounter = 0;

  if (counter != lastCounter) {
    Serial.println(counter);
    lastCounter = counter;
  }

  const char *menu_a[3] = {
      "Settings",
      "wowie",
      "wowie",
  };

  if (layer == 0 && buttonPressed == 1) {
    layer = 1;
    printArray(menu_a, 2);
  }
}
