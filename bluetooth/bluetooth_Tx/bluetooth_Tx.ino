//////////////////////////////////////////////////////////////////////////////////
// REMIXED BY: TECHBITAR (HAZIM BITAR)
// LICENSE: PUBLIC DOMAIN
// DATE: MAY 2, 2012
// CONTACT: techbitar at gmail dot com

int counter =0;

void setup() {
  Serial.begin(115200); 
  delay(50);
}

void loop() {
  counter++;
  Serial.print("Arduino counter: ");
  Serial.println(counter);
  delay(500); // wait half a sec
}



//void setup()
//{
//Serial.begin(9600);
//pinMode(2,INPUT);
//}
//
//void loop()
//{
//Serial.print("¡Proyectosarduino.com.ar! \n");
//delay(1);
//}




//connect: rfcomm connect hci0 00:14:01:14:80:CE
// disconnect: rfcomm release hci0
// query:  sudo sdptool records 00:14:01:14:80:CE
// terminal serial: moserial

//bms:
//http://techversat.com/projects/ledi/working-with-bluetooth-module/
//http://fuenteabierta.teubi.co/2013/07/utilizando-el-modulo-serie-bluetooth-en.html
//http://www.instructables.com/id/Modify-The-HC-05-Bluetooth-Module-Defaults-Using-A/?ALLSTEPS
//https://wiki.debian.org/BluetoothUser



//
//char inByte;
//int  LED = 12; // LED on pin 13
//
//void setup() {
//  // El baud rate debe ser el mismo que en el monitor serial y 
//
//  // que el mobulo bluetooth. 
//
//  // para cambiar el baud rate debe entrar en modo AT
//  Serial.begin(9600);
//}
//
//void loop() {
//      digitalWrite(LED, HIGH);
//     delay(1000); 
//      
//
//}
//
//// Se activa cuando se detecta escritura en el puerto serial
//void serialEvent() {  
//  
//  while (Serial.available()) {
//    inByte = Serial.read();        
//    // Si detecta el caracter '0' entonces apaga el led
//    if( inByte == '0' ){
//      digitalWrite(LED, LOW);  
//      Serial.println("LOW");
//    }
//    
//    // Si detecta el caracter '1' entonces enciende el led
//    if( inByte == '1' ){
//      digitalWrite(LED, HIGH); 
//      Serial.println("HIGH");
//    }  
//  }
//}



/*
* BlinkOnCommand - turns an LED on or off
*/
//
//#include <string.h>
//
//char buffer[255];
//int i = 0;
//int pinVal = 0;
//
//
//void setup() {
//  Serial.begin(9600);
//  
//  pinMode(13,OUTPUT);
//  digitalWrite(13,pinVal);
//}
//
//
//void loop() {
//  while(Serial.available()>0) {
//    char c = Serial.read();
//    append_buffer(c);
//    
//    if(c=='\n') {
//       if(strstr(buffer,"led")!=0) {
//         digitalWrite(13,pinVal^=1);
//         if(pinVal==1) {
//           Serial.write("Led ON\r\n");
//         } else {
//           Serial.write("Led OFF\r\n");
//         }
//       }
//      flush_buffer();
//    }
//  }
//}
//
//
//
//void flush_buffer() {
//  Serial.write((const uint8_t*)buffer,i);
//  for(int j=0;j<=i;j++) {
//    buffer[j] = 0;
//  }
//  i = 0;
//}
//
//void append_buffer(char c) {
//  if(i<255) {
//    buffer[i++] = c;
//  } else {
//    flush_buffer();
//  }
//}
