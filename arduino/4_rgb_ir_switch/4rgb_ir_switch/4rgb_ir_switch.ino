int prevIR =1;
int color=0;
// color 0 means off
// color 1 means red
// color 2 means green
// color 3 means blue

//IR gives 0 when object detected,   1 when no object

void setup() {
  // put your setup code here, to run once:
  pinMode(5,INPUT); //ir sensor
  pinMode(6,OUTPUT); //red led
  pinMode(7, OUTPUT);//BLUE 
  pinMode(8, OUTPUT); //GREEN

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int IR = digitalRead(5);

  //when is led on condition
  if(prevIR==0 && IR==1){
    
    color++;

    if(color > 3){ 
      color =0 ; //after blue 3 , led becomes off 0
    }

    if(color == 1){
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
    }
    else if (color==2){
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(8,LOW);
    }
    else if (color == 3){
      digitalWrite(8,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
    else if (color == 0){ //led off
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
    }

  }

  prevIR = IR;
  delay(200);
}
