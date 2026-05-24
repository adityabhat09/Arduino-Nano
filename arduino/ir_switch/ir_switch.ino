int prevIR = 1;
int s = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(5,INPUT); //IR sensor , val dega arduino ko hence , arduino will take input
  pinMode(6,OUTPUT); //led
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IR = digitalRead(5);
  
  if (prevIR == 0 && IR == 1) {
    s = !s;
    Serial.print("Value changed to ");
    Serial.println(s);
  }

  if (s == 1) {
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  
 
  prevIR = IR;
  delay(100);
}


// obj detect led on 
// obj not detect led stays on

// obj detect led off
// obj
