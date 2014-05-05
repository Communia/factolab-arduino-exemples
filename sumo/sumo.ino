/**
* **********************************
* *** /// PRINTBOT RENACUAJO /// ***
* **********************************
* sumo
* *****************************************************************
* * Basat en codi de BQ de Alberto Valero - Generado con Bitbloq Mail :diy@bq.com Licencia: GNU General Public License v3 or later *
* * Modificat per factolab.net
/******************************************************************/

#include <Servo.h>

//declara variables
int ir_dret;
int ir_esquerra;
int NEGRE;
int BLANC;
Servo motor_dret;
Servo motor_esquerra;
const int trigPin = 11;
const int echoPin = 12;

//Definir variables, establir el estat dels pins, inicializar llibrerías, etc... http://arduino.cc/es/Reference/Setup
void setup()
{
  // configura el pin digital 2 i 3 com a input http://arduino.cc/en/Reference/PinMode
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  //defineix blanc i negre de la mateixa manero que ho faran els IR (0 i 1)
  NEGRE = 0;
  BLANC = 1;
  //configura els motors servos als pins 6 i 9 http://arduino.cc/es/Reference/ServoAttach
  motor_dret.attach(9);
  motor_esquerra.attach(6);
  //configura HC-SR04
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

//Programa que s'ejecuta consecutivament http://arduino.cc/es/Reference/loop
void loop()
{
  //Llegir i assignar el valor dels pins 2 i 3 a variables 
  ir_dret = digitalRead(2);
  ir_esquerra = digitalRead(3);
  //  send the pulse
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo
  distance = (duration/2) / 02.91; // calculate the distance in cm
  if (ir_esquerra == BLANC && ir_dret == BLANC){
    if ( distance > 0 && distance < 150 ){
      motor_dret.write(180);
      motor_esquerra.write(0);
      delay((60));
    }
    if ( distance >= 150 && distance < 400 ){
      motor_dret.write(180);
      motor_esquerra.write(0);
      delay((20));
    }
    if (distance >= 400){
      motor_esquerra.write(0);
      motor_dret.write(90);
      delay((20)); 
    }
  }
  if (ir_dret == NEGRE || ir_esquerra == NEGRE) {
    //Al llegir ir dret igual que el negre (1), gira amb sentit anti-horari el motor esquerra (endavant), si no llegueix negre para el motor dret per poder girar
      motor_esquerra.write(180);
      motor_dret.write(0);
      delay((600)); 
  }
    Serial.print(distance);
    Serial.println(" mm"); 
}