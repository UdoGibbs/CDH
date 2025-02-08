#ifndef SLEEP_H
#define SLEEP_H

void enterDeepSleep() {
  Serial.println("Energiesparmodus aktiv");
  preferences.begin("heater", false);
  preferences.putInt("target_temp", target_temp);
  preferences.putInt("stage", stage);
  preferences.end();
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_32, 1);
  esp_deep_sleep_start();
}

void wakeUp() {
  Serial.println("Aufwachen aus Deep Sleep");
}

#endif  // SLEEP_H