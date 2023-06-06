# Arduino x ESP8266-01 WiFi relay
## Driver code for a fully designed ___product___ complete with documentation and schematics.

  This code is the result of about a days worth of research into the ESP8266; out-the-box it allows
for complete control of the Arduino GPIO via implementation of the concepts of flagging and pre-
defined command sets.

  We use the <ESP8266WiFi.h> and the <ESP8266HTTPClient.h> libraries to establish a connection from
the esper to the command server and await commands on a loop; when something is recieved it's then
printed to the serial line where Arduino is listening.

  Arduino is pre-configured with a function that accepts the command as an argument and compares it
to it's own list of commands; if the command is validated then the command is executed. Otherwise
an error message is printed back to the serial line.


## Alexa-Integration

  What good's the ability to make a smart-X without a smart assistant to do our bidding?
For a cheap and easy sprint motion I'm just gonna use my stock Alexa for now, but there ARE
efforts into a custom built and fully offline smart assistant based on the SPHINX voice-recognition
model.


## Notes on using the Arduino IDE:

  > If UDEV rules aren't configured, you must change either ownership or permission of the serial
  > port you're interfacing with the board from.

  > ESP8266 uses a lot of the same API calls as the UNO does, but it pulls from an ESP8266 specific
  > library.

  > HTTPClient.get(HOST) is depreciated from a lot of tutorials time of writing; it now requires 
  > the HTTPClient.get(CLIENT, HOST) syntax.
