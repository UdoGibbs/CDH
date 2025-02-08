// Include libraries
#include "displays.h"

// Display-Initialisierung
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SDA 17
#define SCL 16
#define i2c_Address 0x3c
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Funktionsdeklaration
void initDisplay() {
  Wire.begin(17, 16);
  display.setTextColor(SH110X_WHITE);
  if (!display.begin(i2c_Address, true)) {
    Serial.println("Fehler: Display nicht gefunden!");
    while (1)
      ;  // Stoppt den Code, falls Display nicht initialisiert wird
  }
  display.clearDisplay();
  display.display();
}

void showHomescreen() {
  display.clearDisplay();
  display.setTextSize(1);
  const char* text = "Homescreen!";
  int16_t x, y;
  uint16_t width, height;

  // Textbreite berechnen
  display.getTextBounds(text, 0, 0, &x, &y, &width, &height);

  // Zentrieren
  int x_pos = (SCREEN_WIDTH - width) / 2;
  
  display.setCursor(x_pos, 0);
  display.print(text);
  display.display();
}

void standbyDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Standby");
  display.display();
}

void fireupDisplay() {
  return;
}
void heizbetriebDisplay() {
  return;
}

void cooldownDisplay() {
  return;
}

void updateDisplay(int target_temp, int room_temp, int stage) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  const char* text = "Heizbetrieb";
  int16_t x, y;
  uint16_t width, height;

  // Textbreite berechnen
  display.getTextBounds(text, 0, 0, &x, &y, &width, &height);

  // Zentrieren
  int x_pos = (SCREEN_WIDTH - width) / 2;
  
  display.setCursor(x_pos, 0);
  display.println(text);
  display.setCursor(0, 0);
  display.println("");
  display.println("Zieltemperatur: " + String(target_temp) + " C");
  display.println("raumtemperatur: " + String(room_temp) + " C");
  display.println("Heizstufe: " + String(stage));
  display.display();
  delay(500);
}
