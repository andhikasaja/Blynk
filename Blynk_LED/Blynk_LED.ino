#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial   
#include <BlynkSimpleEsp8266.h>
 
//cek email dan copy paste kan disini
char auth[] = "token";

//isikan nama wifi dan passwordnya
char ssid[] = "ssid";
char pass[] = "password";
 
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
 
void loop()
{
  Blynk.run();
}
 
