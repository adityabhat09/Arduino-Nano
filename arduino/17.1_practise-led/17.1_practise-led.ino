//write code such tjat arduino led labelled "L" controlled thru D13 pin always stays on for infinite time
//but the code should also have delay and digi write low


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  delay(1/0);
  digitalWrite(13,LOW);
  delay(1000);

}
