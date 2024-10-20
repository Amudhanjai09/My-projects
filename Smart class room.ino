#include<Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int smokepin=A0;
int redled=7;
int greenled=8;
int servo=9;
int buzzerPin = 6;
int smokevalue;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
pinMode(smokepin,INPUT);
pinMode(greenled,OUTPUT);
pinMode(redled,OUTPUT);
pinMode(servo,OUTPUT);
pinMode(buzzerPin, OUTPUT);
Serial.begin(9600);
myservo.attach(servo);
lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
smokevalue=analogRead(smokepin);
Serial.print("CO2 Value:");
Serial.println(smokevalue);
lcd.setCursor(0,0);
   lcd.print("Co2 Value:");
lcd.setCursor(0,1);
   lcd.print(smokevalue);
   lcd.print("ppm");

if(smokevalue>=750){
  digitalWrite(redled, HIGH);
  digitalWrite(greenled, LOW);
  myservo.write(0);
  delay(3);
  delay(1000);
  tone(buzzerPin, 5000);  // 1000 Hz frequency
  delay(1000);            // Sound for 1 second

  // Stop the sound
  noTone(buzzerPin);
 
}
else{
  digitalWrite(redled, LOW);
  digitalWrite(greenled, HIGH);
  myservo.write(70);
  delay(1000);
}
delay(1000);
}
