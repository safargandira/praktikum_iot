int ledPin1 = 14; // GPIO14---D5 of NodeMCU L1
int ledPin2 = 12;
int ledPin3 = 13;
int ledPin4 = 15;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
}
void loop() {
digitalWrite(ledPin1, HIGH); //menyalakan LED
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, HIGH);
digitalWrite(ledPin4, HIGH);
}