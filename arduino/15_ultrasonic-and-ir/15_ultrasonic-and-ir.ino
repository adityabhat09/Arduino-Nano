//ultrasonic is  used to measure the distance between sensor and the object
//IR sensor is used to detect if there is any object in front of you

const int trigPin = 9;
const int echoPin =10;
const int ultraLedPin = 8;

long duration;
int distanceCm;

const int irPin = 5;
const int irLedPin = 6;




void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT );
  pinMode(ultraLedPin, OUTPUT);

  pinMode(irPin, INPUT);
  pinMode(irLedPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IR = digitalRead(5);  //if ir=0 obj detected
  Serial.print("IR val = ");
  Serial.println(IR);

  digitalWrite(trigPin, LOW);
  delay(100);

  //creating pulsewave
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  Serial.print("Distance = ");
  Serial.println(distanceCm);
  

  if(IR == 0 || distanceCm<20){
    digitalWrite(ultraLedPin, HIGH);
    Serial.println("car stop");
    delay(1000);
  }
  else{
    digitalWrite(ultraLedPin, LOW);
  }

  delay(500);
  
  


}
