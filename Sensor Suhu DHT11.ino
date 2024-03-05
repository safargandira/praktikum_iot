#include "DHT.h" //library sensor yang telah diimportkan; inisiasi library sensor
#define DHTPIN 5 //(D1) //Pin apa yang digunakan; define untuk variabel tetap
#define DHTTYPE DHT11 // DHT 11

int ledPin1 = 14; //mendeklarasikan pin LED
int ledPin2 = 12;
int ledPin3 = 13;
int ledPin4 = 15;
DHT dht(DHTPIN, DHTTYPE); //membuat object dht dengan parameternya variabel DHTPIN dan DHTTYPE

void setup() {
  Serial.begin(9600); //baud komunikasi serial
  Serial.println("Pengujian DHT11!"); //penulisan di serial monitor
  dht.begin(); //prosedur memulai pembacaan module sensor
  pinMode(ledPin1, OUTPUT); //mendefinisikan pin LED sebagai output
  pinMode(ledPin2, OUTPUT); //mendefinisikan pin LED sebagai output
  pinMode(ledPin3, OUTPUT); //mendefinisikan pin LED sebagai output
  pinMode(ledPin4, OUTPUT); //mendefinisikan pin LED sebagai output
}

void loop() {
  delay(2000); //menunggu beberapa detik untuk pembacaan
  //pembacaan sensor membutuhkan waktu 250ms

  digitalWrite(ledPin1, LOW); //mematikan LED
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);

  //Pembacaan untuk data kelembaban
  float humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
  float celcius_1 = dht.readTemperature();
  //pembacaan dalam format Fahrenheit
  float fahrenheit_1 = dht.readTemperature(true); //isFarenheit = true

  //mengecek pembacaan apakah terjadi kegagalan atau tidak
  if (isnan(humidity_1) || isnan(celcius_1) || isnan(fahrenheit_1)) {
    Serial.println("Pembacaan data dari module sensor gagal!");
    digitalWrite(ledPin1, HIGH); //menyalakan LED 1
    digitalWrite(ledPin2, HIGH); //menyalakan LED 2
    digitalWrite(ledPin3, HIGH); //menyalakan LED 3
    digitalWrite(ledPin4, HIGH); //menyalakan LED 4
    delay(1000); //delay 1 detik
    return;
  }

  float htof = dht.computeHeatIndex(fahrenheit_1, humidity_1);
  //Prosedur pembacaaan data indeks panas dalam bentuk fahreheit
  float htoc = dht.computeHeatIndex(celcius_1, humidity_1, false);
  //Prosedur pembacaaan data indeks panas dalam bentuk celcius

  //pembacaan nilai pembacaan data kelembaban
  Serial.print("Kelembaban: ");
  Serial.print(humidity_1);
  Serial.print(" %\t");

  //pembacaan nilai pembacaan data suhu
  Serial.print("Suhu : ");
  Serial.print(celcius_1); //format derajat celcius
  Serial.print("°"); //simbol derajat
  Serial.print("C / ");
  Serial.print(fahrenheit_1); //format derajat fahrenheit
  Serial.print("°");
  Serial.print("F\t");

  Serial.print("Indeks Panas: ");
  Serial.print(htof);
  Serial.print("°");
  Serial.print("F / ");
  Serial.print(htoc);
  Serial.print("°");
  Serial.println("C ");

  if (humidity_1 <= 47.50){ //jika kelembaban kurang dari atau sama dengan 47.50
    digitalWrite(ledPin1, HIGH); //menyalakan LED 1
    digitalWrite(ledPin2, HIGH); //menyalakan LED 2
    delay(1000); //delay 1 detik
    return;
  } else if (humidity_1 > 47.50){ //jika kelembaban lebih dari 47.50
    digitalWrite(ledPin3, HIGH); //menyalakan LED 3
    digitalWrite(ledPin4, HIGH); //menyalakan LED 4
    delay(1000); //delay 1 detik
    return;
  }

}