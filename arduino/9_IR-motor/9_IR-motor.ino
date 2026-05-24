// when ir detects object motor turns on otherwise off

int IR = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);  //I1 motor
  pinMode(10,OUTPUT);  //I2

  pinMode(2,INPUT); //ir sensor
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  IR = digitalRead(2);

  if(IR==0){  //MOTOR WILL GO CLOCKWISE
    Serial.println("CLOCKWISE");
    digitalWrite(9,HIGH);    
    digitalWrite(10,LOW);
  }
  else{  //motor go anticlockwise
    Serial.begin("ANTICLOCKWISE");
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH)
  }

  delay(200);
}
