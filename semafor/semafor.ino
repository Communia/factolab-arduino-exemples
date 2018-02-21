/***   Included libraries  ***/
#include <Servo.h>


/***   Global variables and function definition  ***/
const int Boton_1 = 12;
int redPin = 2; //per RGB
int greenPin = 3; // per RGB
Servo Servo_1;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE



/***   Setup  ***/
void setup() {
    //pinMode(Boton_1, INPUT);
    pinMode(Boton_1, INPUT_PULLUP); // ! PULLUP de pulsador
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    Servo_1.attach(10);

}


/***   Loop  ***/
void loop() {
    if (digitalRead(Boton_1) == 1) {
        Servo_1.write(0);
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin,LOW);
    } else {
        Servo_1.write(90);
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin,HIGH);
    }
}
