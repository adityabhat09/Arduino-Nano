void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  pinMode(2, OUTPUT); //GND PIN
  digitalWrite(2,LOW); //GND PIN

}

void loop() {


  

  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW); //GROUND PIN
  delay(1000);

//  
//void loop() {
//
//
//  
//  // put your main code here, to run repeatedly:
//  digitalWrite(5,HIGH);
//  digitalWrite(2,LOW); //GROUND PIN
//  delay(1000);
//  digitalWrite(5,LOW);
//  digitalWrite(2,LOW); //GROUND PIN
//  delay(1000);
//  



}
