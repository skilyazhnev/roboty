#include <MCP3008.h>


#define CS_PIN1 5
#define CS_PIN2 3
#define CS_PIN3 4
#define CLOCK_PIN 6
#define MOSI_PIN 10
#define MISO_PIN 7


MCP3008 adc1(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN1);
MCP3008 adc2(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN2);
MCP3008 adc3(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN3);


Servo myservo;

unsigned char crc8mm(unsigned char *pcBlock, unsigned int len)
{
    unsigned char crc = 0x0;
    unsigned int i;

    while (len--)
    {
        crc ^= *pcBlock++;

        for (i = 0; i < 8; i++)
            crc = crc & 0x80 ? (crc << 1) ^ 0x7 : crc << 1;
    }

    return crc;
}



void send_package(int *data, int len, byte command)
{
   //  unsigned char crc8s[2] = {1, 2} ;
    byte crc8s; 
    crc8s = crc8mm((unsigned char *)data, len);
    
    // отправлем начало пакета 
    Serial.write(0x0c);
    // отправляем длину пакета
    Serial.write(len+1);
    // отправляем контрольную сумму от данных 
    Serial.write(crc8s);
    // байт команды  
    Serial.write(command);
    // поток данных
    Serial.write((byte *)data, len);
}

  unsigned int hop = 0;
  int circle = 0;


void setup() {
  Serial.begin(115200);
  pinMode(CS_PIN2, OUTPUT);
  digitalWrite(CS_PIN2, HIGH);
  pinMode(CS_PIN3, OUTPUT);
  digitalWrite(CS_PIN3, HIGH);
  pinMode(CS_PIN1, OUTPUT);
  digitalWrite(CS_PIN1, HIGH);

}

void loop() {


  int out[24];
  int s = 0;


  for (int i=0; i <= 7; i++){
      int val = adc1.readADC(i);
      out[s] = val;
      s++ ;
    }
  
  for (int i=0; i <= 7; i++){
      int val = adc2.readADC(i); 
      out[s] = val;
      s++ ;
    }
  
  for (int i=0; i <= 7; i++){
      int val = adc3.readADC(i); 
      out[s] = val;
      s++ ;
    }

  byte command = 1; 
  send_package(out, sizeof(out),command) ; 

  }
