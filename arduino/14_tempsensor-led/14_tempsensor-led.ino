int val;
int tempPin = 1;
int ledPin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tempPin, INPUT);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  digitalWrite(ledPin, LOW);


  // put your main code here, to run repeatedly:
  val = analogRead(tempPin);
  float mv = (val/1024.0)*5000;
  float cel = mv/10; //convert milivolt to celcius
  float farh = (cel*9)/5 + 32;

  Serial.print("TEMPERATURE = ");
  Serial.print(cel);
  Serial.print(" *C ");
  Serial.print(" , ");
  Serial.print(farh);
  Serial.print(" *f ");
  Serial.println();
  

  if(cel>20){
    digitalWrite(ledPin , HIGH);
    Serial.println("LED ON");
    delay(2000);
  }

}
