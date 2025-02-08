// Hartmut Fichte 08.02.2025

//Bibliotheken
#include <Arduino.h>
#include <driver/rtc_io.h>
#include "driver/ledc.h"
#include <driver/gpio.h>

//Funktionsprototypen:
void fireup();

#define GLOW_PIN 21
#define LEDC_CHANNEL_GLOW LEDC_CHANNEL_1  // LEDC-Kanal
#define LEDC_TIMER_GLOW LEDC_TIMER_1      // LEDC-Timer
#define LEDC_MODE_GLOW LEDC_LOW_SPEED_MODE
#define LEDC_RESOLUTION_GLOW LEDC_TIMER_8_BIT  // 8-Bit PWM-Auflösung
#define LEDC_FREQUENCY_GLOW 50               // PWM-Frequenz in Hz

const int GLOW_VALUE = 40;  // Duty Cycle für Glühkerze max 4,5V

#define TOUCH_ONOFF 12


// Funktion zur Einstellung des Glow_PWM-Signals
void setGlowPWM(int glowValue) {
  // Duty Cycle für Glühkerze setzen
  ledc_set_duty(LEDC_MODE_GLOW, LEDC_CHANNEL_GLOW, glowValue);
  ledc_update_duty(LEDC_MODE_GLOW, LEDC_CHANNEL_GLOW);  // Werte anwenden
}

void setup() {
  Serial.begin(115200);
  pinMode(GLOW_PIN, OUTPUT);
  ledcWrite(LEDC_CHANNEL_GLOW, 0);

  // LEDC-Channel für die Glühkerze
  ledc_timer_config_t ledc_glow_timer = {
    .speed_mode = LEDC_MODE_GLOW,
    .duty_resolution = LEDC_RESOLUTION_GLOW,
    .timer_num = LEDC_TIMER_GLOW,
    .freq_hz = LEDC_FREQUENCY_GLOW,
    .clk_cfg = LEDC_AUTO_CLK
  };
  ledc_timer_config(&ledc_glow_timer);

  // Konfiguration des LEDC-Kanals für die Glühkerze
  ledc_channel_config_t ledc_glow_channel = {
    .gpio_num = GLOW_PIN,
    .speed_mode = LEDC_MODE_GLOW,
    .channel = LEDC_CHANNEL_GLOW,
    .intr_type = LEDC_INTR_DISABLE,
    .timer_sel = LEDC_TIMER_GLOW,
    .duty = 0,  // Initiale Duty-Cycle
    .hpoint = 0
  };
  ledc_channel_config(&ledc_glow_channel);
}

void loop() {
  fireup();
}

void fireup() {
  setGlowPWM(GLOW_VALUE);
  delay(30000);
}

