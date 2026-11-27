#include "oled.h"
#include "config/config.h"
#include <Adafruit_SSD1306.h>
#include <Wire.h>

Adafruit_SSD1306 display(oled0ScreenWidth, oled0ScreenHeight, &Wire,
                         OLED_RESET);

void initializeOLED() {
  Wire.begin(oled0PinSDA, oled0PinSCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.display();
}
