#include <Servo.h>

Servo namlu;
Servo tetik;  

const int potpin = A0; 
const int button = 2;
 
int val;
    
void setup() 
{
  namlu.attach(3);
  tetik.attach(4); 
  Serial.begin(9600);
}
void loop() 
{
  val = analogRead(potpin);
  val = map(val,0,1023,0,180);            
  Serial.println(val);
  namlu.write(val);
  if (digitalRead(button) == HIGH)
  {
    tetik.write(125);
    delay(15);
  }  
  else
  {
    tetik.write(85);
    delay(15);                 
  }
}
