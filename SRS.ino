#define trigPin 10
#define echoPin 12
#include <Servo.h>
Servo servoMain;

void setup() {
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
servoMain.attach(3);

}

void loop()
{

  float pos = 0;
 for (pos = 0; pos <=180; pos +=1) {  // servo rotation from 0 to 180 degree
        servoMain.write(pos);          //save the position in pos variable
        delay(15);
        float duration,distance;
     digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=(duration/2)*0.0344;
if (distance<=25) {
Serial.println("object detected");
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
  }
else {
  Serial.println("out of range");
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(15);
     }
}
  for(pos = 180; pos >=0; pos -=1) { // servo rotation from 180 to 0 degree
   servoMain.write(pos);             //save the position in pos variable
  delay(15);
        float duration,distance;
     digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=(duration/2)*0.0344;
if (distance<=25) {
Serial.println("object detected");
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
  }
else {
  Serial.println("out of range");
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(15);
     }
delay(10);
  }
} 
