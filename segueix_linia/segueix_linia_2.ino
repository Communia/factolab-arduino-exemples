

/**
* **********************************
* *** /// PRINTBOT RENACUAJO /// ***
* **********************************
* Aquest programa fa que el robot segueixi una línia negra de 2cm amb sensors IR
* - Si no trobo linia negra fa marxa enrrera amb una mica de gir
* *****************************************************************
* * Basat en codi de BQ de Alberto Valero - Generado con Bitbloq Mail :diy@bq.com Licencia: GNU General Public License v3 or later *
* * Modificat per factolab.net
**  http://arduino.cc/es/Reference/HomePage
/******************************************************************/

#include <Servo.h>

//declara variables
int ir_dret;
int ir_esquerra;
int NEGRE;
int BLANC;
int sentit;
Servo motor_dret;
Servo motor_esquerra;

//Definir variables, establir el estat dels pins, inicializar llibrerías, etc... http://arduino.cc/es/Reference/Setup
void setup()
{
  // configura el pin digital 2 i 3 com a input http://arduino.cc/en/Reference/PinMode
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  //defineix blanc i negre de la mateixa manero que ho faran els IR (0 i 1)
  NEGRE = 0;
  BLANC = 1;
  sentit = 1;
  //configura els motors servos als pins 6 i 9 http://arduino.cc/es/Reference/ServoAttach
  motor_dret.attach(9);
  motor_esquerra.attach(6);
}

//Programa que s'ejecuta consecutivament http://arduino.cc/es/Reference/loop
void loop()
{
  //Llegir i assignar el valor dels pins 2 i 3 a variables 
  ir_dret = digitalRead(2);
  ir_esquerra = digitalRead(3);
  //quant el robot trepitja negre
  if (ir_dret == NEGRE || ir_esquerra == NEGRE) {
    //Al llegir ir dret igual que el negre (1), gira amb sentit anti-horari el motor esquerra (endavant), si no llegueix negre para el motor dret per poder girar
    if (ir_dret == NEGRE) {
      motor_esquerra.write(0);
      delay((20));
      sentit = 0;
    } else {
      motor_esquerra.write(90);
      delay((20));
    }
    //Al llegir ir esquerra igual que el negre (1), gira amb sentit horari el motor dret (endavant), si no llegueix negre para el motor esquerra per poder girar
    if (ir_esquerra == NEGRE) {
      motor_dret.write(180);
      delay((20));
      sentit = 0;
    } else {
      motor_dret.write(90);
      delay((20));
    }
  }
  //quant el robot trepitja blanc
  if (ir_esquerra == BLANC && ir_dret == BLANC) {
  //si els dos sensors llegeixen blanc i el sentit esta configurat a 1, mou endavant
    if (sentit == 1) {
      motor_esquerra.write(0);    
      motor_dret.write(180);
      delay((20));
    }
  //si els dos sensors llegeixen blanc i ja havies trepitjat negre fes marxa enrrera amb una mica de gir
    else {
      motor_esquerra.write(180);
      motor_dret.write(0);
      delay((600)); 
      motor_esquerra.write(90);
      motor_dret.write(0);
      delay((1000));
      sentit = 1;
    } 
  }
}