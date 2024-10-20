/*
  Make sure your Firebase project's '.read' and '.write' rules are set to 'true'. 
  Ignoring this will prevent the MCU from communicating with the database. 
  For more details- https://github.com/Rupakpoddar/ESP32Firebase 
*/

#include <ESP32Firebase.h>

#define LDR 6
#define LED 33
#define LED_WAR 26
#define _SSID "Subu_Nothing"          // Your WiFi SSID
#define _PASSWORD "subu_nothing"      // Your WiFi Password
#define REFERENCE_URL "https://basicstring-52874-default-rtdb.firebaseio.com/"  // Your Firebase project reference url

Firebase firebase(REFERENCE_URL);

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  // digitalWrite(LED_BUILTIN, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Connect to WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  // digitalWrite(LED_BUILTIN, HIGH);

//================================================================//
//================================================================//

  
}

void loop() {
 /* // Examples of setting String, integer and float values.
  firebase.setString("Example/setString", "It's Working");
  firebase.setInt("Example/setInt", 123333);
  firebase.setFloat("Example/setFloat", 45.32);

  // Examples of pushing String, integer and float values.
  firebase.pushString("push", "Hello");
  firebase.pushInt("push", 789);
  firebase.pushFloat("push", 89.54);

  // Example of getting a String.
  String data1 = firebase.getString("Example/setString");
  Serial.print("Received String:\t");
  Serial.println(data1);

  // Example of getting an int.
  int data2 = firebase.getInt("Example/setInt");
  Serial.print("Received Int:\t\t");
  Serial.println(data2);

  // Example of getting a float.
  float data3 = firebase.getFloat("Example/setFloat");
  Serial.print("Received Float:\t\t");
  Serial.println(data3);

  // Example of data deletion.
  firebase.deleteData("Example");
  // Nothing */

//firebase.deleteData("Example");
float ldr_value=analogRead(LDR);
//Serial.println(ldr_value); 
if(ldr_value<500)
{
  firebase.pushString("Warning","Light's intensity is low in light 1,Please check!!!");
  firebase.pushString("Warning","Value:");
  firebase.pushFloat("Warning",ldr_value);
  digitalWrite(LED_WAR,HIGH);
}
delay(2000);
  


}
