#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); 

const int relay1 = 2;
const int relay2 = 3;
const int relay3 = 4;
const int relay4 = 5;

void setup() {
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  
  BTSerial.begin(9600); 
  Serial.begin(9600);   

  // Initially turn off all relays
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);

  Serial.println("Bluetooth Home Automation Ready");
}

void loop() {
 
  if (BTSerial.available()) {
    char receivedChar = BTSerial.read(); 
    Serial.print("Received: ");
    Serial.println(receivedChar);

   
    switch (receivedChar) {
      case '1':
        digitalWrite(relay1, HIGH); 
        Serial.println("Relay 1 ON");
        break;
      case '2':
        digitalWrite(relay1, LOW); 
        Serial.println("Relay 1 OFF");
        break;
      case '3':
        digitalWrite(relay2, HIGH); 
        Serial.println("Relay 2 ON");
        break;
      case '4':
        digitalWrite(relay2, LOW); 
        Serial.println("Relay 2 OFF");
        break;
      case '5':
        digitalWrite(relay3, HIGH); 
        Serial.println("Relay 3 ON");
        break;
      case '6':
        digitalWrite(relay3, LOW); 
        Serial.println("Relay 3 OFF");
        break;
      case '7':
        digitalWrite(relay4, HIGH); 
        Serial.println("Relay 4 ON");
        break;
      case '8':
        digitalWrite(relay4, LOW); 
        Serial.println("Relay 4 OFF");
        break;
      default:
        Serial.println("Invalid command");
        break;
    }
  }
}
