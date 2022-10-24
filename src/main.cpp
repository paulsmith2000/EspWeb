/* made by Kusnh13
For refrence watch YouTube video:-https://youtu.be/Hgq2KX5w-_o   */

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "web.h"

AsyncWebServer aserver(80); 

byte level = LOW;
const byte cPinLed = 15;


void setup()
{
  Serial.begin(9600);
  analogRead(A0);
  pinMode(cPinLed, OUTPUT);
  digitalWrite(cPinLed, level);

  SetupWifiWebServer("ESP32-1", "password");

  SetupWebCommand(aserver, "toggle", [](){
    level = 1 - level;
    digitalWrite(cPinLed, level);
  });
  
  /*
  SetupWebCommand(aserver, "toggle", [](AsyncWebServerRequest *request){
    level = 1 - level;
    digitalWrite(cPinLed, level);
    request->send(200, "text/plain", "toggle command(iii)");
  });
  */

  aserver.begin();
}

void loop()
{     
}
