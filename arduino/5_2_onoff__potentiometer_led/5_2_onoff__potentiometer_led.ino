//take input from user for led on or off like a switch
//operating led with potentiometer should only work if the led is "on"

int X;

void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT);
  pinMode(9,OUTPUT); //LED
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available()>0){
    if(X==1){
      Serial.println("LED ON");
      analogWrite(9,pwmVal);
      Serial.println(pwmVal);
    }
    else{
      Serial.println("led off");
      digitalWrite(9,LOW);
    }
  }

  // put your main code here, to run repeatedly:
  int potVal = analogRead(A1);  //reading value of a1(potentio) and storing it in potval
  //converting it to pwm
  int pwmVal = map(potVal,0,1023,  0,255);
  // Serial.print(potVal);
 
  X = Serial.parseInt();
    // if(Serial.peek()== '\n' || Serial.peek()== '\r'){
    //   Serial.read();
    // }
    Serial.print("enter val: ");
    Serial.println(X);

  
  delay(1000);
}
