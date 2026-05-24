void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("I1=0 , I2=1");
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(2000);

  Serial.println("I1=1 , I2=0");
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  delay(2000);

    Serial.println("I1=0 , I2=0");
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(2000);

    Serial.println("I1=1 , I2=1");
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  delay(2000);
}
