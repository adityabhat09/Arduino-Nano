// using ldr, when sunlight increases , bringtness of led should increase (like mobile phone)
//in ldr more light means less resistance hence more current, more brightness


//ldr range = 0 to 1023
//convert it to pwm -> o to 255 , using map
  int ldrPin = A1;
  int ledPin = 9; //D9 pin supports PWM
  int ldrValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ldrValue = analogRead(ldrPin);   //ldr pin means it changes resistance absed on how much sunlight it receives, more sunlight = less resistance
  Serial.print("LDR VALUE : ");
  Serial.println(ldrValue);

  int pwmVal = map(ldrValue, 0,1023,  0,255);
  Serial.println(pwmVal);

  analogWrite(ledPin, pwmVal);

  delay(500);



}
