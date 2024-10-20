const int sensorPin = A0;  // MQ-2 analog output connected to A0
const int buzzerPin = 8;   // Buzzer connected to pin 8 (optional)
int sensorValue = 0;       // Variable to store sensor reading
int threshold = 300;       // Threshold value for CO2 alarm

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
  // Read the analog value from the MQ-2 sensor
  sensorValue = analogRead(sensorPin);
  Serial.print("CO2 level: ");
  Serial.println(sensorValue);  // Print sensor value for debugging
  
  // Check if the sensor value exceeds the threshold (indicating high CO2)
  if (sensorValue > threshold) {
    digitalWrite(buzzerPin, HIGH);  // Sound the alarm
    Serial.println("Warning! High CO2 level detected!");
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off alarm
  }
  
  delay(1000);  // Wait for 1 second before next reading
}
