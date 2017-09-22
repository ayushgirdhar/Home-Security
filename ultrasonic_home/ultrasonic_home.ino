#define utrigger 13 
#define uecho 12
#define buzzer 10
#define threshold 20
const int ledPin = 6;
long duration,dis, cm;
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void setup()
{
  Serial.begin(9600);
  pinMode(utrigger, OUTPUT);
  pinMode(uecho, INPUT);
  pinMode(11, INPUT);
  digitalWrite(11,HIGH);
  pinMode(buzzer,OUTPUT);
  pinMode(ledPin,OUTPUT);
}
void loop()
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
     }
   }
}

