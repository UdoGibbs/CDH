#ifndef DISPLAYS_H
#define DISPLAYS_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// Variables
extern Adafruit_SH1106G display;

// Funktionsdeklaration
void initDisplay();
void showHomescreen();
void standbyDisplay();
void fireupDisplay();
void heizbetriebDisplay();
void cooldownDisplay();
void updateDisplay(int target_temp,int room_temp,int stage);

#endif  // DISPLAYS_H
