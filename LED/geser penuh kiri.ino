int ledPin1 = 14; // GPIO14---D5 of NodeMCU L1
int ledPin2 = 12; // L2
int ledPin3 = 13; // L3
int ledPin4 = 15; // L4
int a = 1000;
void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
}
void loop() {
digitalWrite(ledPin1, HIGH);
delay(a); // 1 s
digitalWrite(ledPin2, HIGH);
delay(a); // 1 s
digitalWrite(ledPin3, HIGH);
delay(a); // 1 s
digitalWrite(ledPin4, HIGH);
delay(a); // 1 s
digitalWrite(ledPin4, LOW);
delay(a); // 1 s
digitalWrite(ledPin3, LOW);
delay(a); // 1 s
digitalWrite(ledPin2, LOW);
delay(a); // 1 s
digitalWrite(ledPin1, LOW);
delay(a); // 1 s
}