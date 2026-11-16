const int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();
    if (comando == '1') {
      digitalWrite(ledPin, HIGH);
    } else if (comando == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
}