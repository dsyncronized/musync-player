#include "menu.h"
#include "oled/oled.h"
#include "rotary/rotary.h"

void printArray(const char *a[], int size) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Back");

  for (int i = 0; i < size; i++) {
    display.println(a[i]);
  }
  display.display();
}

void printPage() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(counter);
  display.display();
}
