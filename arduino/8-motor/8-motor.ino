void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0){  //MEANS if serial input is not empty

    char c = Serial.read(); //take a char as input

    if(c=='f'){
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
    }
    else if(c=='l'){
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
    }
  }

}
