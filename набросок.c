#include <Servo.h>

Servo servo1;
int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(5);
  Serial.begin(9600);
}

void loop() {
  int rawReading = analogRead(analogPin);
  float volts = rawReading / 204.6;

  servo1.write(0);
  delay(1500);

  servo1.write(180);
  delay(1500);
  Serial.println(volts);
  delay(1000);
}



60: 0
377: 180



#define potent_pin 0 
#include <Servo.h>


Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.attach(5);
  
}

void loop() { 
  servo1.write(90); 
  Serial.println( analogRead(potent_pin) );
  delay(1000);
  servo1.write(0);
  Serial.println( analogRead(potent_pin) );
  delay(1000);
  servo1.write(180); 
  Serial.println( analogRead(potent_pin) );
  delay(1000);
} 




#define potent_pin 0
#include <Servo.h>


Servo servo1;

void setup() {
  Serial.begin(9600);

  
}

void loop() { 
  Serial.println( analogRead(potent_pin) );
  delay(30);
  
} 
