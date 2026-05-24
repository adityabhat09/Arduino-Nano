int val;
int tempPin = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(tempPin);
  float mv = (val/1024.0)*5000; //sesnsor gives input in the form of current. we convert that to mili volt (mv)
  float cel = mv/10; //convert milivolt to celcius
  float farh = (cel*9)/5 + 32;  //convert celcius to farenheit

  Serial.print("TEMPERATURE = ");
  Serial.print(cel);
  Serial.print(" *C ");
  Serial.print(" , ");
  Serial.print(farh);
  Serial.print(" *f ");
  Serial.println();
  delay(1000);
}
