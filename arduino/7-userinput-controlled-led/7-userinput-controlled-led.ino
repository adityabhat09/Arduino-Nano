char x;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Serial.println("START");  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()>0){
    x=Serial.read();
    if(x=='A' || x=='a'){
      Serial.println("LED HIGH");
      digitalWrite(13,HIGH);
      delay(1000);
    }
    else{
      Serial.println("LED LOW");
      digitalWrite(13,LOW);
      delay(1000);
    }
  }
}
