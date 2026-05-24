

const int trigPin = 9;
const int echoPin = 10;
const int RedPin = 2;
const int GreenPin = 3;
const int BluePin = 4;

long duration;
int distanceCm;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT );
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);

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
    digitalWrite(RedPin, HIGH);
    Serial.println("Red");
    Serial.println(distanceCm);

    digitalWrite(GreenPin, LOW);
    digitalWrite(BluePin, LOW);
    delay(500);
  }
  else if(distanceCm >= 20 && distanceCm <= 40){
    digitalWrite(GreenPin, HIGH);
    Serial.println("Green");
    Serial.println(distanceCm);

    digitalWrite(RedPin, LOW);
    digitalWrite(BluePin, LOW);
    delay(500);
  }
  else{
    digitalWrite(BluePin, HIGH);
    Serial.println("Blue");
    Serial.println(distanceCm);

    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, LOW);
    delay(500);
  }

  delay(100);


}