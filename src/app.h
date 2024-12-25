#pragma once
#include <WiFi.h>
#include <WiFiClient.h>
#include <config.h>
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL4JypE_Scz"
#define BLYNK_TEMPLATE_NAME "Nixie Clock"
#define BLYNK_AUTH_TOKEN std::getenv("BLYNK_AUTH")
#define WIFI_SSID std::getenv("WIFI_SSID")
#define WIFI_PASS std::getenv("WIFI_PASS")
#include <BlynkSimpleEsp32.h> 



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