#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
#include <Adafruit_GPS.h>
#include <WiFiManager.h>


SoftwareSerial commline(3, 1); //  Establish comms with pins 1 & 3.
Adafruit_GPS GPS(&commline);//   Connect to GPS through comms.


void setup() {


  // Initialize Wi-Fi connection & manager;

  // Initialize the wifi manager.
  WiFiManager wifi;

  // Configure AP IP address.
  //wifi.setAPConfig(
  //IPAddress(10,0,1,1),
  //IPAddress(10,0,1,1),
  //IPAddress(255,255,255,0)
  //);

  // Set AP name.
  wifi.autoConnect(
    "Dosei-Ichi GPS Probe"
  );


  // Initialize GPS with preferences;

  //  Begin GPS communications.
  GPS.begin(9600);

  // Only send RMC & GGA sentences.
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);

  // Send reading every one second.
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);

  // Allow for querying if antenna is attached (lol).
  GPS.sendCommand(PGCMD_ANTENNA);

}


void loop() {

  float latitude  = GPS.latitudeDegrees;
  float longitude = GPS.longitudeDegrees;
  float speed     = GPS.speed;
  float angle     = GPS.angle;
  float altitude  = GPS.altitude;
  int satellites  = GPS.satellites;

  HTTPClient https;



  // Connect to the lab-server to post coordinates.
  https.begin(WIFI, "https://lab-93.guyyatsu.me/gps");
}
