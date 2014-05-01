/**  
 *
 *     ********************************************************
 *     ********************************************************
 *     ***                                                  ***
 *     ***      ///      PRINTBOT RENACUAJO       ///       ***
 *     ***                                                  ***
 *     ******************************************************** 
 *     ********************************************************
 *
 *    ///  Este programa permite que el Printbot Renacuajo siga 
 *    ///  la pista negra del circuito. 
 *     
 *   ****************************************************
 *   * Fecha:04/03/2014                                 *
 *   * Autor: Alberto Valero - Generado con Bitbloq     *
 *   * Mail :diy@bq.com                                 *
 *   * Licencia: GNU General Public License v3 or later *
 *   ****************************************************
 */
/******************************************************************/
/******************************************************************/

#include <Servo.h>

int ir_derecho;

int ir_izquierdo;

int NEGRO;

int BLANCO;

Servo servo_6;

Servo servo_9;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  NEGRO = 0;

  BLANCO = 1;

  servo_6.attach(6);

  servo_9.attach(9);

}


void loop()
{
  ir_derecho = digitalRead(2);
  ir_izquierdo = digitalRead(3);
  if (ir_derecho == NEGRO) {
    servo_6.write(0);
    delay((20));

  } else {
    servo_6.write(90);
    delay((20));

  }
  if (ir_izquierdo == NEGRO) {
    servo_9.write(180);
    delay((20));

  } else {
    servo_9.write(90);
    delay((20));

  }
}