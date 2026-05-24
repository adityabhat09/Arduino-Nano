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
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  //creating pulse wave
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;

  if(distanceCm < 20){
    digitalWrite(ledPin, HIGH);
    Serial.println(distanceCm);
  }
  else{
    digitalWrite(ledPin, LOW);
    Serial.println(distanceCm);
  }

  delay(100);


}
