const int boton1Pin = 2;
const int boton2Pin = 3;

int ultimoEstadoBoton1 = HIGH;
int ultimoEstadoBoton2 = HIGH;

void setup() {
  pinMode(boton1Pin, INPUT_PULLUP);
  pinMode(boton2Pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int estadoBoton1 = digitalRead(boton1Pin);
  int estadoBoton2 = digitalRead(boton2Pin);

  if (estadoBoton1 != ultimoEstadoBoton1) {
    if (estadoBoton1 == LOW) {
      Serial.println("B1_ON");
    } else {
      Serial.println("B1_OFF");
    }
    ultimoEstadoBoton1 = estadoBoton1;
    delay(50);
  }

  if (estadoBoton2 != ultimoEstadoBoton2) {
    if (estadoBoton2 == LOW) {
      Serial.println("B2_ON");
    } else {
      Serial.println("B2_OFF");
    }
    ultimoEstadoBoton2 = estadoBoton2;
    delay(50);
  }
}