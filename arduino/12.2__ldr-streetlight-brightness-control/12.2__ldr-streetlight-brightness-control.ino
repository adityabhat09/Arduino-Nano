// using ldr, when it becomes night, turn the led on like a streetlight. when its morning(more sunlight) led has less brightness
//in ldr more light means less resistance hence more current, more brightness


//this is reverse of 12.1 code, just invert the map function
//insted of 0,255, write 255,0

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

  int pwmVal = map(ldrValue, 0,1023,  255,0);
  Serial.println(pwmVal);

  analogWrite(ledPin, pwmVal);

  delay(500);



}
