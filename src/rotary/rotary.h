#pragma once

extern volatile int counter;
extern volatile bool buttonPressed;
void initializeRotaryEncoder();
void readEncoder();
void readSwitch();
