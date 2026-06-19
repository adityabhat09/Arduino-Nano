//how to make any digital pin as gnd(d2 here),  by giving it low signal
//cathode of both leds are connected to d2

void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT); //I1  led1
  pinMode(6,OUTPUT); //i2   led2

  pinMode(2,OUTPUT);  //gnd pin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,LOW);   //d2 is gnd pin now

  //case1
  digitalWrite(5,HIGH); //led1   on
  digitalWrite(6,LOW); //led2   off
  delay(2000);

  //case2
  digitalWrite(5,LOW);   
  digitalWrite(6,HIGH);    //led2 is on
  delay(2000);

  //case3
  digitalWrite(5,HIGH);   //both led 1 and 2 are on
  digitalWrite(6,HIGH);
  delay(2000);

  //case4
  digitalWrite(5,LOW);  //both led 1 and 2 are off
  digitalWrite(6,LOW);
  delay(2000);
}
