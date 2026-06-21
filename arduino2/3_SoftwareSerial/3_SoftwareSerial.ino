
 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX     //means my serial(wifi mod) se communication ke liye we will use pins 10 and 11 or arduino

//my serial means Wifi module-----------------
//serial means Arduino------------------------

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world");    //ye jeyaga wifi mod ko,    iske neeche output me neeche error aayega , cuz its not AT command,,,  Wifi mod only replies ok to AT commands
  delay(1000);
  mySerial.println("AT");   // this is an AT command,     iske neeche output me Ok aayega,  
}

void loop() { // run over and over
  if (mySerial.available()) {   //AGAR wifi mod me kuch hai, then serial(serial monitor )  me print karo
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {   //Agar serial monitor me kuch hai,   then myserial(wifi mod) usko read karega, and ok bhejega
    mySerial.write(Serial.read());
  }
}
