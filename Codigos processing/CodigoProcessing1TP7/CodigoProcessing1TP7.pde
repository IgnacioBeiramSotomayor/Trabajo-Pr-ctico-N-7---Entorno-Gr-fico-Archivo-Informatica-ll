import processing.serial.*;

Serial myPort;
boolean ledState = false;

void setup() {
  size(400, 400);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  background(220);
  
  if (ledState) {
    fill(0, 255, 0);
  } else {
    fill(100);
  }
  
  rect(150, 150, 100, 100);
  fill(0);
  textSize(14);
  text("LED 1", 180, 205);
}

void mousePressed() {
  if (mouseX > 150 && mouseX < 250 && mouseY > 150 && mouseY < 250) {
    ledState = !ledState;
    if (ledState) {
      myPort.write('1');
    } else {
      myPort.write('0');
    }
  }
}
