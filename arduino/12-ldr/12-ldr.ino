  int ldrPin = A0;
  int ldrValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  ldrValue = analogRead(ldrPin);   //ldr pin means it changes resistance absed on how much sunlight it receives, more sunlight = less resistance
  Serial.print("LDR VALUE : ");
  Serial.println(ldrValue);
  delay(500);

}
