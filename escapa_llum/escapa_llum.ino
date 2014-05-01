#include <Servo.h>

int luz_izquierda;

int luz_derecha;

Servo servo_6;

Servo servo_9;

void setup()
{
  servo_6.attach(6);

  servo_9.attach(9);

}


void loop()
{
  luz_izquierda = analogRead(A4);
  luz_derecha = analogRead(A5);
  if (luz_derecha > 300 && luz_izquierda > 300) {
    // Motor Derecha
    servo_6.write(180);
    delay((0));
    // Motor Izquierda
    servo_9.write(0);
    delay((1000));

  }
  if (luz_derecha > luz_izquierda) {
    // Motor derecha
    servo_6.write(180);
    delay((0));
    // Motor Izquierda
    servo_9.write(90);
    delay((100));

  }
  if (luz_izquierda > luz_derecha) {
    servo_6.write(90);
    delay((0));
    servo_9.write(0);
    delay((100));

  }

}