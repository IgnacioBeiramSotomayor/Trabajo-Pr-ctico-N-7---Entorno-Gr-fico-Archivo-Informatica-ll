const int button1Pin = 2;
const int button2Pin = 3;
const int led1Pin = 8;
const int led2Pin = 9;

void setup() {
  Serial.begin(9600);
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);

  if (button1State == LOW) {
    digitalWrite(led1Pin, HIGH);
  } else {
    digitalWrite(led1Pin, LOW);
  }

  if (button2State == LOW) {
    digitalWrite(led2Pin, HIGH);
  } else {
    digitalWrite(led2Pin, LOW);
  }

  Serial.print("B1:");
  Serial.print(button1State);
  Serial.print(",B2:");
  Serial.println(button2State);

  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    
    if (incomingChar == '1') {
      digitalWrite(led1Pin, HIGH);
    } else if (incomingChar == '0') {
      digitalWrite(led1Pin, LOW);
    } else if (incomingChar == '3') {
      digitalWrite(led2Pin, HIGH);
    } else if (incomingChar == '4') {
      digitalWrite(led2Pin, LOW);
    }
  }

  delay(50);
}