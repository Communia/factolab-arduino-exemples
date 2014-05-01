/*
HC-SR04 

Circuit:
  VCC to arduino 5v 
  GND to arduino GND
  Echo to Arduino pin 11 
  Trig to Arduino pin 12

Based on code from http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/step3/Upload-the-sketch/
*/

#include <Servo.h>

int ir_derecho;

int ir_izquierdo;

int NEGRO;

int BLANCO;

Servo servo_6;

Servo servo_9;




const int trigPin = 11;
const int echoPin = 12;
void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  NEGRO = 0;
  BLANCO = 1;
  servo_6.attach(6);
  servo_9.attach(9);
  
}
void loop() {
  long duration, distance;

  // send the pulse
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo
  distance = (duration/2) / 29.1;  // calculate the distance in cm
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range; reading invalid");
    
  }
  else {
    
    Serial.print(distance);
    Serial.println(" cm");
  }
//  if (distance >= 3) {
//    servo_6.write(0);
//    delay((20));      
//    servo_9.write(180);
//    delay((20));  
//  }else{
//    servo_6.write(90);
//    delay((20));      
//    servo_9.write(90);
//    delay((20));  
//  }
   
  delay(500); 
}
