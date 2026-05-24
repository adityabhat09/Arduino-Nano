int prevIR = 0;
int IR = 1;
int state =0;
// state = 0 motor off
// 1 case 1
// 2 case2
// 3 case3
// case4

void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT); //IR SENSOR
  pinMode(5,OUTPUT); //MOTOR
  pinMode(6,OUTPUT); //MOTOR
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  IR = digitalRead(4);

  if(prevIR==0 && IR==1){
    state++;

    if(state>3){
      state=0; // motor off
    }

    else if(state=1){
      Serial.println("I1=0 , I2=1");
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
    }
    else if(state=2){
      Serial.println("I1=1 , I2=0");
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
    }
    else if(state=3){
      Serial.println("I1=0 , I2=0");
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }
    else if(state=4){
      Serial.println("I1=1 , I2=1");
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
    }
  }

  prevIR=IR;
  delay(200);
}
