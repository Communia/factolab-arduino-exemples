#include <Servo.h>

Servo servos[13];
#include <SoftwareSerial.h>

/***   Global variables   ***/
int Inicializacion=1;
String MODO_Control="Manual";SoftwareSerial blueToothSerial(0,1);

/***   Function declaration   ***/
void Avanza ();
void Stop ();
void GiraIzquierda ();
void Retrocede ();
void GiraDerecha ();
void Sigue_Lineas ();
// Equivalencia en Ascii de los comandos enviados por Robopad:
// 'S' = 83
// 'U' = 85
// D = 68
// 'L' = 76
// 'R' = 82
// 'M' = 77
// 'I' = 73
void Ejecuta_instruccion (int dato);

void setup()
{
  servos[6].attach(6);

  servos[9].attach(9);




  pinMode(0,INPUT);
  pinMode(1, OUTPUT);
  blueToothSerial.begin(38400);
  blueToothSerial.flush();

  pinMode( 2 , INPUT);

  pinMode( 3 , INPUT);

}


void loop()
{
  // Nada más conectar el PrintBot le diremos que se detengan los servomotores. Ésto lo hará sólo al principio.
  if (Inicializacion == 1) {
    Stop();
    Inicializacion=0;
   }else {
    if (blueToothSerial.available()>0){
      int lectura=blueToothSerial.read();
      Ejecuta_instruccion(lectura);

    }
    if (MODO_Control == "SigueLineas") {
      Sigue_Lineas();
     }
   }

}

/***   Function definition   ***/
void Avanza () {
  servos[6].write(180);
  delay(10);
  servos[9].write(0);
  delay(10);
 }
void Stop () {
  servos[6].write(90);
  delay(10);
  servos[9].write(90);
  delay(10);
 }
void GiraIzquierda () {
  servos[6].write(90);
  delay(10);
  servos[9].write(0);
  delay(10);
 }
void Retrocede () {
  servos[6].write(0);
  delay(10);
  servos[9].write(180);
  delay(10);
 }
void GiraDerecha () {
  servos[6].write(180);
  delay(10);
  servos[9].write(90);
  delay(10);
 }
void Sigue_Lineas () {
  int ir_derecho=digitalRead(2);
  int ir_izquierdo=digitalRead(3);
  int NEGRO=0;
  if (ir_izquierdo == NEGRO) {
    servos[6].write(180);
    delay(10);
   }else {
    servos[6].write(90);
    delay(10);
   }
  if (ir_derecho == NEGRO) {
    servos[9].write(0);
    delay(10);
   }else {
    servos[9].write(90);
    delay(10);
   }
 }
// Equivalencia en Ascii de los comandos enviados por Robopad:
// 'S' = 83
// 'U' = 85
// D = 68
// 'L' = 76
// 'R' = 82
// 'M' = 77
// 'I' = 73
void Ejecuta_instruccion (int dato) {
  switch (dato)
  {
    case 83:
    {
      Stop();
      break;
    }
    case 85:
    {
      Avanza();
      break;
    }
    case 68:
    {
      Retrocede();
      break;
    }
    case 76:
    {
      GiraIzquierda();
      break;
    }
    case 82:
    {
      GiraDerecha();
      break;
    }
    case 77:
    {
      MODO_Control="Manual";
      Stop();
      break;
    }
    case 73:
    {
      MODO_Control="SigueLineas";
      break;
    }
    default:
    {
      Stop();
    }
  }
  delay(300);
 }

