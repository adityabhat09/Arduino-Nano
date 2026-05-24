void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(A1);
  int pwmVal = map(potVal,0,1023,  0,255);
  analogWrite(9, pwmVal); 
  Serial.print(potVal);
  Serial.print(" /t ");
  Serial.println(pwmVal);
  delay(10);
  
}
