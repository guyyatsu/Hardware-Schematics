int CMD = 0;
const int RELAY0 = 2;
const int RELAY1 = 3;

int RelayConductor(int CMD){

  if (CMD == 00) {
    digitalWrite(RELAY0, LOW);
    delay(500);
    Serial.print("00-30A6");
  }

  else if (CMD == 01) {
    digitalWrite(RELAY0, HIGH);
    delay(500);
    Serial.print("01-30A6");
  }

  else if (CMD == 10) {
    digitalWrite(RELAY1, LOW);
    delay(500);
    Serial.print("01-30A6");
  }

  else if (CMD == 11) {
    digitalWrite(RELAY1, HIGH);
    delay(500);
    Serial.print("11-30A6");
  }

  else {
    delay(500);
    Serial.print("An unallocable CMD was recieved... ignoring...");
    delay(500);
  }
}


void setup() {  

  pinMode(RELAY0, OUTPUT);
  digitalWrite(RELAY0, LOW);

  pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1, LOW);

  Serial.begin(115200);

}


void loop() {

  if (Serial.available() > 0) {

    CMD = Serial.read();
    RelayConductor(CMD);

  }
}
