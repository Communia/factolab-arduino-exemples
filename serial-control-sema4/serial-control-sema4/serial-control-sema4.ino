/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

 
void blink() {   
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
}
void apaga() {
    digitalWrite(13, LOW);
    delay(2000);
}
void blink_slow() {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
}
int do_blink = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.flush();
}

// the loop function runs over and over again forever
void loop() {
  String input = "";
  while (Serial.available() > 0){
    input +=(char) Serial.read();
    delay(5);
  }
  if (input == "on" ){
    do_blink=1;
  }
  else if ( input == "off"){
    do_blink = 2;
  }
  else if ( input == "w"){
    do_blink = 0;
  }  
  if ( do_blink == 1 ){
    blink();
  }else if ( do_blink == 2 ) {
    apaga();
  }else if ( do_blink == 0 ){
    blink_slow();
  }

}
