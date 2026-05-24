void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT); //I1
  pinMode(6,OUTPUT); //i2

  pinMode(2,OUTPUT);  //gnd pin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,LOW);

  //case1
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  delay(2000);

  //case2
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(2000);

  //case3
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  delay(2000);

  //case4
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(2000);
}
