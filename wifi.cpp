// Include Libraries
#include "wifi.h"

// WLAN-Zugangsdaten
const char *ssid = "Tinkizone";
const char *password = "85542723146383472327";

// Port für Webserver
WiFiServer serverWiFi(80);

// Function to connect to wifi
void connectWiFi(void *parameter) {

  WiFi.begin(ssid, password);
  Serial.print("Verbindung zum WLAN...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" verbunden!");
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());
  Serial.println("Starte Wifi-Server!");
  serverWiFi.begin();

  vTaskDelete(NULL);  // Beendet die Task nach erfolgreicher Verbindung
}
