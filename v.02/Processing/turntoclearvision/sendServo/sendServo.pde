import processing.serial.*;

Serial myPort;

void setup() 
{
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[4], 9600);
}

void draw() {
  myPort.write("180+180=");
}
