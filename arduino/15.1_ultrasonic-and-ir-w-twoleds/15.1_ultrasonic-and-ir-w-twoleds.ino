const int trigPin = 9;
const int echoPin =10;
const int ultraLed = 8;

long duration;
int distanceCm;

const int irPin = 5;
const int irLed = 6;
const int ultraLed = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT );
  pinMode(ultraLedPin, OUTPUT);

  pinMode(irPin, INPUT);
  pinMode(irLed, OUTPUT);
  pinMode(ultraLed, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int IR = digitalRead(irPin); //coz ir arduino ko input dega
  Serial.print("IR val = ");
  Serial.println(IR);


  //ultrasonic ka code
  digitalWrite(trigPin, LOW);
  delay(100);

  //creating pulsewave
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //echopin outputs the duration after which the pulsewave was received back
  distanceCm = duration * 0.034 / 2;
  Serial.print("Disrance = ");
  Serial.println(distanceCm);


  if(IR == 0){ //object dectected
    digitalWrite(irLed , HIGH);
    Serial.println("IR LED ON");
    digitalWrite(ultraLed, LOW);
    delay(1000);
  }
  else{
    digitalWrite(irLed , LOW);
  }
  if(distanceCm < 20){
    digitalWrite(ultraLed, HIGH);
    Serial.println("ULTRA LED ON");
    delay(1000);
  }
  else{
    digitalWrite(ultraLed, LOW);
  }
}
