// simulate this:
// I1  I2  I3  I4  
// 1   0   1    0    forward
// 0    1   0   1     backward
// 0    0   0   0      not working
// 0    0   1   0     left drcn
// 1   0    0   0     rught drcn

void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT); //I1 MOTOR1
  pinMode(6,OUTPUT); //I2 MOTOR 1

  pinMode(9,OUTPUT); //I3 MOTOR2
  pinMode(10,OUTPUT);  //I4 MOTOR2

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Forward drcn");
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(2000);

  Serial.println("backward drcn");
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(2000);

  Serial.println("not working drcn");
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(2000);

  Serial.println("left drcn");
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(2000);

  Serial.println("right drcn");
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(2000);

}
