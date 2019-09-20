#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial   
#include <BlynkSimpleEsp8266.h>
 
//cek email dan copy paste kan disini
char auth[] = "8d7f25327d664974b78cfb30a3c21aa7";

//isikan nama wifi dan passwordnya
char ssid[] = "WINNO";
char pass[] = "opoyoenake";
 
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,"iot.radnet.id",8080);
}
 
void loop()
{
  Blynk.run();
}
