

void setup() {
  // put your setup code here, to run once: 
  pinMode(0,OUTPUT); //RX0 pin  both are digital pins
  pinMode(1,OUTPUT); //TX1 pin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(0, HIGH);
  delay(2000);
  digitalWrite(0, LOW);

  digitalWrite(1,HIGH);
  delay(2000);
  digitalWrite(1,LOW);

  delay(2000);

}
