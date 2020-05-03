#include <Servo.h>
#include <C:\Users\vaskily1\Documents\Arduino\libraries\MCP3008.h>

#define CS_PIN 5
#define CLOCK_PIN 6
#define MOSI_PIN 10
#define MISO_PIN 7

MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);
MCP3008 adc2(CLOCK_PIN, MOSI_PIN, MISO_PIN, 3);
MCP3008 adc3(CLOCK_PIN, MOSI_PIN, MISO_PIN, 4);
//Servo servo1;
//int analogPin = A0;

void setup() {
//  servo1.attach(8);
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);

}

void loop() {

// Поворачиваем движок
 // servo1.write(0);
 // delay(1500);

// чиатаем с АЦП
     delay(2000);
Serial.println("************");
  
 for (int i=0; i <= 7; i++){
      int val = adc.readADC(i); 
      Serial.println(val);
   }

Serial.println("_____");

 for (int i=0; i <= 7; i++){
      int val = adc2.readADC(i); 
      Serial.println(val);
   }

Serial.println("_____");

 for (int i=0; i <= 7; i++){
      int val = adc3.readADC(i); 
      Serial.println(val);
   }
   
// Поворачиваем движок
 // servo1.write(180);
 // delay(1500);

}
