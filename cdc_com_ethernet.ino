#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
bool n1, n2, n3, n4;
IPAddress ip(192, 168, 1, 10);
EthernetServer server(23);


void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);

  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);

  pinMode(19, OUTPUT);
  digitalWrite(19, 0);
}

void loop() {

  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.println(c);
        if (c == '1') {
          digitalWrite(5, 0);
        }
        if (c == '3') {
          digitalWrite(6, 0);
        }
        if (c == '5') {
          digitalWrite(7, 0);
        }
        if (c == '7') {
          digitalWrite(8, 0);
        }

        if (c == '2') {
          digitalWrite(5, 1);
        }
        if (c == '4') {
          digitalWrite(6, 1);
        }
        if (c == '6') {
          digitalWrite(7, 1);
        }
        if (c == '8') {
          digitalWrite(8, 1);
        }

        //Para abrir e fechar o portão
        if (c == '9') {
          digitalWrite(19, 1);
        }
        if (c == '0') {
          digitalWrite(19, 0);
        }

        if (c == 'a') {
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          digitalWrite(7, 1);
          digitalWrite(8, 1);
        }
        if (c == 'b') {
          digitalWrite(5, 0);
          digitalWrite(6, 0);
          digitalWrite(7, 0);
          digitalWrite(8, 0);
        }

        if (c == 's') {
          if (digitalRead(5) == 0) {
            client.print("*Lamp1 OFF");
          }
          else {
            client.print("*Lamp1 ON");
          }

          if (digitalRead(6) == 0) {
            client.print("*Lamp2 OFF");
          }
          else {
            client.print("*Lamp2 ON");
          }

          if (digitalRead(7) == 0) {
            client.print("*Lamp3 OFF");
          }
          else {
            client.print("*Lamp3 ON");
          }

          if (digitalRead(8) == 0) {
            client.print("*Lamp4 OFF");
          }
          else {
            client.print("*Lamp4 ON");
          }

          //          muda isso para o pino que vais usar para controlar o motor do portão
          if (digitalRead(19) == 0) {
            client.print("*Pool OPEN");
          }
          else {
            client.print("*Pool CLOSE");
          }
          delay(1000);
        }       
      }
    if (digitalRead(15) == HIGH) {
          n1 = true;
        }
        if ( (digitalRead(15) == LOW) && (n1 == true) ) {
          digitalWrite(5, digitalRead(5) ^ 1);
          n1 = false;
        }

        if (digitalRead(16) == HIGH) {
          n2 = true;
        }
        if ( (digitalRead(16) == LOW) && (n2 == true) ) {
          digitalWrite(6, digitalRead(6) ^ 1);
          n2 = false;
        }

        if (digitalRead(17) == HIGH) {
          n3 = true;
        }
        if ( (digitalRead(17) == LOW) && (n3 == true) ) {
          digitalWrite(7, digitalRead(7) ^ 1);
          n3 = false;
        }

        if (digitalRead(18) == HIGH) {
          n4 = true;
        }
        if ( (digitalRead(18) == LOW) && (n4 == true) ) {
          digitalWrite(8, digitalRead(8) ^ 1);
          n4 = false;
        }
    }
  }

  if (digitalRead(15) == HIGH) {
          n1 = true;
        }
        if ( (digitalRead(15) == LOW) && (n1 == true) ) {
          digitalWrite(5, digitalRead(5) ^ 1);
          n1 = false;
        }

        if (digitalRead(16) == HIGH) {
          n2 = true;
        }
        if ( (digitalRead(16) == LOW) && (n2 == true) ) {
          digitalWrite(6, digitalRead(6) ^ 1);
          n2 = false;
        }

        if (digitalRead(17) == HIGH) {
          n3 = true;
        }
        if ( (digitalRead(17) == LOW) && (n3 == true) ) {
          digitalWrite(7, digitalRead(7) ^ 1);
          n3 = false;
        }

        if (digitalRead(18) == HIGH) {
          n4 = true;
        }
        if ( (digitalRead(18) == LOW) && (n4 == true) ) {
          digitalWrite(8, digitalRead(8) ^ 1);
          n4 = false;
        }

}
      
