int leftIR  = 2;
int rightIR = 3;

// Left motor pins
int leftMotorPin1 = 5;
int leftMotorPin2 = 6;

// Right motor pins
 int rightMotorPin1 = 7;
 int rightMotorPin2 = 8;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
}

void loop() {
  int leftSensor  = digitalRead(leftIR);
  int rightSensor = digitalRead(rightIR);

  // Left motor
  if (leftSensor == HIGH) {
    // move forward
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    // stop
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  // Right motor
  if (rightSensor == HIGH) {
    // move forward
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    // stop
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
}
```
