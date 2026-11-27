#include <Adafruit_SSD1306.h>
#include <stdint.h>

constexpr uint8_t oled0ScreenWidth = 128;
constexpr uint8_t oled0ScreenHeight = 64;
constexpr int8_t OLED_RESET = -1;

extern Adafruit_SSD1306 display;
void initializeOLED();
