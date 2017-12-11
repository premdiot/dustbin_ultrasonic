#include "UbidotsMicroESP8266.h"

#include <SoftwareSerial.h> 

//#include <ESP8266WiFi.h>

#define TOKEN  "jZFDCmBhexehmDepUEXsujZw64xTt8"
#define distance_c "5a2ecd7fc03f9707849488b8"
#define current_height_c "5a2ecde2c03f97076539f5c3"

#define TRIGGERPIN D6
#define ECHOPIN    D7

#define WIFISSID "Anandn"
#define PASSWORD "9791150922" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
    
    pinMode(TRIGGERPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);
}


void loop()
{

  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(2); 
    
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  
  distance = (duration / 2) * 0.0344;
  Serial.print("Distance: ");
  Serial.println(distance);
 
  client.add(distance_c,distance);
  client.sendAll();

  delay(3500);

}

