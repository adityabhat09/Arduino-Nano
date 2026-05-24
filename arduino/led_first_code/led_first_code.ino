void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);
  delay(4000);
  digitalWrite(12, LOW);
  delay(3000);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(2500);
}
