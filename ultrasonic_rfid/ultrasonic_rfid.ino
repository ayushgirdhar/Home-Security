#include <OneWire.h>
#include <SPI.h>
#include <RFID.h>
#define utrigger 3 
#define uecho 2
#define buzzer 4
#define threshold 10
long duration,dis, cm;
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
RFID rfid(10,5); 

void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  pinMode(utrigger, OUTPUT);
  pinMode(uecho, INPUT);
  pinMode(11, INPUT);
  digitalWrite(11,HIGH);
  pinMode(buzzer,OUTPUT);  
}

void loop()
{
    if (rfid.isCard()) 
       Serial.println("IS CARD");
    else
    {
      digitalWrite(utrigger, LOW);
      delayMicroseconds(2);
      digitalWrite(utrigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(utrigger, LOW);
      duration = pulseIn(uecho, HIGH);
      cm = microsecondsToCentimeters(duration);
      if(cm>=200)
        {}
       else
       {
         dis=cm;
         Serial.println(dis);
         if(dis<=threshold)
         {
            digitalWrite(buzzer, HIGH);       
            delay(5000);
            digitalWrite(buzzer, LOW);
            delay(200);
         }
       }
      
    }   
}
