// Task : ultrasonic and motor , 
// If distance < 20 car(motor) should stop moving


const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //motor
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //making a wave
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = 0.034 * duration / 2;

  Serial.print("Distance:  ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  if(distanceCm <= 20){
    //motor is not working
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    Serial.println("motor off");
    
  }
  else{ 
    //motor is on
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
  }

  delay(100);
}
