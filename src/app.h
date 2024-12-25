#pragma once

#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL4JypE_Scz"
#define BLYNK_TEMPLATE_NAME "Nixie Clock"
#define BLYNK_AUTH_TOKEN "rvuXBOxn8lWYgScmSlzyxWgQ7gbPc4zd"
#define WIFI_SSID "TP-Link_7EC6"
#define WIFI_PASS "bazoka1224"
#include <BlynkSimpleEsp32.h> 

BlynkConnection blynkConnection;


class BlynkConnection {
    public:
      void connectToBlynk()
      {
          Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
      }

      void runBlynk()
      {
          Blynk.run();
      }
};


  BLYNK_WRITE(20){
  int value = param.asInt(); // Get the value from the app (0 or 1)
  digitalWrite(23, value); // Set GPIO 23 to HIGH or LOW
  }