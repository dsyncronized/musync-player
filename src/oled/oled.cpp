#include "oled/oled.h"
#include "config/config.h"
#include <Adafruit_SSD1306.h>
#include <Wire.h>

Adafruit_SSD1306 initializeOLED() {
  Wire.begin(oled0PinSDA, oled0PinSCL);
  Adafruit_SSD1306 display(oled0ScreenWidth, oled0ScreenHeight, &Wire,
                           OLED_RESET);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ;
  }
  display.clearDisplay();
  return display;
}
