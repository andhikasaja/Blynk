#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial   
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>



//cek email dan copy paste kan disini
char auth[] = "token";

//isikan nama wifi dan passwordnya
char ssid[] = "ssid";
char pass[] = "password";

#define DHTTYPE DHT11
#define DHTPIN 0
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 
// Fungsi ini berguna untuk mengirim data ke nodemcu di virtualpin 5
// pembacaan widget harus disetting ke push, jadi kita menentukan seberapa sering mengirim data ke apps blynk
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 //bisa mengirim berapapun nilai pada satu waktu, tetapi jangan mengirim lebih dari 10 nilai dalam 1 waktu (1 detik)
  Blynk.virtualWrite(V5, t); // temp
  Blynk.virtualWrite(V6, h); // humid
}
 
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,"blynk-cloud.com", 8442); //konfigurasi server
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
 
