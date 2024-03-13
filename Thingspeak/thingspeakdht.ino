#include <DHT.h> // Library DHT
#include <ESP8266WiFi.h> // Library ESP8266
String apiKey = "   "; // Masukkan Write API key dari ThingSpeak
const char *ssid = "   "; // Nama SSID
const char *pass = "   "; // Password SSID
const char* server = "api.thingspeak.com";
#define DHTPIN D3 // Pin D3 (pin OUT DHT)
DHT dht(DHTPIN, DHT11);
WiFiClient client; // membuat client pada jaringan ke ThingSpeak webServer

void setup()
{
  Serial.begin(9600);
  delay(10);
  dht.begin();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop()
{
  float h = dht.readHumidity(); // h = humidity (kelembaban)
  float t = dht.readTemperature(); // t = temperature (suhu)
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  if (client.connect(server,80)) // "184.106.153.149" or api.thingspeak.com
  {
    String postStr = apiKey;
    postStr +="&field5="; // Field 5 (sesuai konfigurasi channel thingspeak
    postStr += String(t); //suhu
    postStr +="&field6="; // Field 6 (sesuai konfigurasi channel thingspeak
    postStr += String(h); //kelembaban
    postStr += "\r\n\r\n";
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" degrees Celcius, Humidity: ");
    Serial.print(h);
    Serial.println("%. Send to Thingspeak.");
  }
  client.stop();
  Serial.println("Waiting...");
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
}