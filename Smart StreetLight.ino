#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS devicec:\Users\Subramani\Downloads\ldr_and_firebase.ino
SoftwareSerial GPS(RXPin, TXPin);
int ldr_pin=A0;
void setup(){
  Serial.begin(9600);
  GPS.begin(GPSBaud);

}

void loop(){
 
  while (GPS.available() > 0){
    gps.encode(GPS.read());
    if (gps.location.isUpdated()){
       int ldr_value=analogRead(A0);
      Serial.println(ldr_value);
      delay(1000);
      if(ldr_value<500){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
      }
    }
}
    
    }
     /*int ldr_value=analogRead(ldr_pin);
  Serial.println(ldr_value);
  delay(1500);
   if(ldr_value<500){*/

   /*int ldr_value=analogRead(ldr_pin);
  delay(1500);
  
  Serial.println(ldr_value);
  delay(2000);
  
    if(ldr_value<500)
  {Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);

  }}
*/  
