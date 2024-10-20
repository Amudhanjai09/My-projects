int irSensor1 = 2;  // IR sensor for parking spot 1
int irSensor2 = 3;  // IR sensor for parking spot 2
int led1 = 8;       // LED to indicate spot 1 availability
int led2 = 9;       // LED to indicate spot 2 availability

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int status1 = digitalRead(irSensor1); // Read status of sensor 1
  int status2 = digitalRead(irSensor2); // Read status of sensor 2

  if (status1 == LOW) {  // If object detected in spot 1
    digitalWrite(led1, HIGH);  // Turn on LED to indicate spot is taken
  } else {
    digitalWrite(led1, LOW);   // Turn off LED to indicate spot is free
  }

  if (status2 == LOW) {  // If object detected in spot 2
    digitalWrite(led2, HIGH);  // Turn on LED to indicate spot is taken
  } else {
    digitalWrite(led2, LOW);   // Turn off LED to indicate spot is free
  }
}
