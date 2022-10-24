

void SetupWifiWebServer(const char* netName,const char* netPass) {
   WiFi.mode(WIFI_AP); 
   WiFi.softAPConfig(IPAddress(192,168,1,100), IPAddress(192,168,1,10), IPAddress(255,255,255,0)); 
   WiFi.softAP(netName, netPass);
}
   
void SetupWebCommand(AsyncWebServer& server, const char* commandName, void func()) {
   String uri = (String)"/" + (String)commandName;
   String responseMsg = (String)commandName + (String)" executed";
   server.on(uri.c_str(), HTTP_GET, [responseMsg,func](AsyncWebServerRequest *request){
      func();
      request->send(200, "text/plain", responseMsg);
      Serial.println(responseMsg);
   });
}  

void SetupWebCommand(AsyncWebServer& server, const char* commandName, ArRequestHandlerFunction func) {
   String uri = (String)"/" + (String)commandName;
   server.on(uri.c_str(), HTTP_GET, func);
}

