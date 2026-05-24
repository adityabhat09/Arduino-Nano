//turn led on if distance less than 20cm

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

long duration;
int distanceCm;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT );
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  //it always needs to be 2 microseconds, if u write in milliseconds it wont work


  //creating pulse wave
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);   
  distanceCm = duration * 0.034 / 2;
  //we didnt use dugutal read on echo pin as , digital read only gives 1 or 0 (high/low) as answer , we need distance value
  //echo pin stays high, after it receives the sent wave back, it becomes low. that duration btwn high and low is given as answer

  if(distanceCm < 20){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }

  delay(100);


}
