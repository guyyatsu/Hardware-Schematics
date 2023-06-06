#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

char SSID[] = "YourSSID";
const char PASSWD[] = "YourPASSWD";
const char* HOST = "YourHOST"

void setup() {

  Serial.begin(115200);
  Serial.println();

  WiFi.begin(SSID, PASSWD);

  Serial.print("Connecting to the network");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("CONNECTED! IP Address:");
  Serial.println(WiFi.localIP());

}


void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    WiFiClient CLIENT;
    HTTPClient http;

    int request = http.GET();

    http.begin(CLIENT, HOST);

    if (request > 0) {
      String CMD = http.getString();
      Serial.println(CMD);
    }

    else {
      Serial.println("Couldn't contact the network... Sorry.");
    }

    http.end();

  }

  else {
    setup();
  }

}
