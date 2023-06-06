# How to use ESP8266-01 with Arduino UNO
## Because nobody just TELLS you this...

There are three phases of configuration the ESPxUNO binding must undertake in order to run:

1. Serial Debugging
2. EEPROM Flashing
3. The final intended configuration

-------------------------------------------------------------------------------------------------------------------------------
Phase One gets you a direct interface to the boards I/O; where you can send AT commands or,
more importantly, get a readout of what went wrong when it goes wrong.

Note that for Phases One and Two the Tx | Rx pins on both devices are directly linked, and the UNO
has it's RESET pin pulled down to enable pass-through communication between your computer and the ESP.

    It's also worth mentioning(for my own sake) that CP_EN == ChiP ENable, and must be pulled up in order
    to start the ESP board.

![Arduino UNO to EP8266-01 Serial debug bridge](https://raw.githubusercontent.com/guyyatsu/C/main/LabExtensions/WiFi-Relay/SCHEMATICS/ESP8266-DEBUGGER.png)

    I've included a voltage divider between the Rx | Rx connection to protect the ESP from any 
    high-voltage miscommunications... Not a MAJOR concern 4999/5000 times but the UNO's serial
    pins count 3v3 as LOW and 5v as HIGH, which is too high for ESP.


-------------------------------------------------------------------------------------------------------------------------------
Phase Two is how you get the code for your intended configuration onto the board.
Almost exactly the same as Phase One, only the GPIO0(FLASH) pin is pulled down too.

![Arduino UNO to ESP8266-0 EEPROM bridge](https://raw.githubusercontent.com/guyyatsu/C/main/LabExtensions/WiFi-Relay/SCHEMATICS/ESP8266-FLASH.png)

    FLASH gets pulled to GND to enable UPLOAD mode on the board

-------------------------------------------------------------------------------------------------------------------------------
Phase Three can really be anything you can do regularly with our brave friend,
only now the Tx:Rx::Rx:Tx connection is standardized with the Arduino's Tx pin
being fed through the voltage divider on the way to the ESP's Rx pin.

![Arduino UNO to ESP8266-01 Production Configuration](https://raw.githubusercontent.com/guyyatsu/C/main/LabExtensions/WiFi-Relay/SCHEMATICS/UNOxESP-2xRelayModule.png)
