int l;

void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT); //LED
  pinMode(3,INPUT); //IR SENSOR
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  l=digitalRead(3);

  if(l==LOW){ //OBJ DETECTED i.e = 0
    digitalWrite(10,HIGH);
    Serial.println("LED ON");
  }
  else{ //obj not detected i.e =1
    digitalWrite(10,LOW);
    Serial.println("LEAD OFF");
  }

}
