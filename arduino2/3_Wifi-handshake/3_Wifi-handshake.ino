#include "SoftwareSerial.h"

#define DEBUG true

SoftwareSerial esp8266(2,3);   //pin2 is rx ,  pin3 is tx

void setup(){

  Serial.begin(9600);
  esp8266.begin(9600);   //instead of writing myserial, we write this

  pinMode(4,OUTPUT);  //led
  pinMode(5,OUTPUT);  //buzzer
  pinMode(6,OUTPUT);  //motor 1
  pinMode(7,OUTPUT);  //motor 1

  pinMode(9,OUTPUT);     //intializing all pins to low, keep everything low so that they are off initially
  digitalWrite(9,LOW);

  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);

  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);

  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);

  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

  sendData("AT+RST\r\n",2000,DEBUG);        // reset module
  sendData("AT+CWMODE=2\r\n",1000,DEBUG);   // set esp8266 to access point, i.e it provides wifi
  sendData("AT+CIFSR\r\n",1000,DEBUG);      // get ip address of esp8266
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG);   // configure for multiple connections
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // Starts a web server on port 80.
}

void loop(){

  if(esp8266.available()){ // check if the esp has sent data to arduino

    if(esp8266.find("+IPD,")){  //looks for +ipd, ipd means neew data received from web client

      delay(1000); // wait for the serial buffer to fill up

      // get the connection id so that we can then disconnect
      int connectionId = esp8266.read()-48;

      // subtract 48 because read() returns ASCII value
      esp8266.find("pin="); // advance cursor to "pin="

      int pinNumber = (esp8266.read()-48)*10;

      // get first digit
      pinNumber += (esp8266.read()-48);

      // get second digit

      switch(pinNumber){

        case 9: // LED

          digitalWrite(4,HIGH);
          digitalWrite(13,HIGH);

          Serial.println("LED IS ON");
          break;

        case 10: // Buzzer

          digitalWrite(5,HIGH);

          Serial.println("BUZZER IS ON");
          break;

        case 11: // Forward Motor

          digitalWrite(6,HIGH);
          digitalWrite(7,LOW);

          Serial.println("Forward");
          break;

        case 12: // Backward Motor

          digitalWrite(6,LOW);
          digitalWrite(7,HIGH);

          Serial.println("Backward");
          break;

        case 13: // Stop

          digitalWrite(13,LOW);
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);

          Serial.println("Stop");
          break;

        default:
          break;
      }

      // digitalWrite(pinNumber,!digitalRead(pinNumber)); // toggle pin

      // make close command
      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId;
      closeCommand += "\r\n";

      sendData(closeCommand,1000,DEBUG); // close connection
    }
  }
}

/*
 * Name: sendData
 * Description: Function used to send data to ESP8266.
 * Params:
 *   command - data/command to send
 *   timeout - time to wait for response
 *   debug   - print to Serial window
 * Returns:
 *   Response from ESP8266
 */

String sendData(String command,const int timeout,boolean debug){

  String response = "";

  esp8266.print(command); // send command to ESP8266

  long int time = millis();

  while((time + timeout) > millis()){

    while(esp8266.available()){

      // ESP has data, read it

      char c = esp8266.read();
      response += c;
    }
  }

  if(debug){
    Serial.print(response);
  }

  return response;
}