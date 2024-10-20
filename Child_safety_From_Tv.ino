const int trigPin = 9;   // Ultrasonic sensor trigger pin
const int echoPin = 10;  // Ultrasonic sensor echo pin
const int buzzerPin = 8; // Buzzer pin
const int ledPin = 6;    // LED pin (optional for warning)

const int safeDistance = 100;  // Safe distance in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  long duration, distance;

  // Send a 10us pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo and calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to distance in cm

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // If the child is too close (below the safe distance)
  if (distance < safeDistance) {
    digitalWrite(buzzerPin, HIGH);  // Sound the buzzer (or turn off TV)
    digitalWrite(ledPin, HIGH);     // Turn on the warning LED
    Serial.println("Warning! Child is too close to the TV!");
  } else {
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
    digitalWrite(ledPin, LOW);      // Turn off the warning LED
  }

  delay(500);  // Small delay before next measurement
}
