import processing.serial.*;

Serial myPort;

void setup() 
{
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[4], 57600);
}

void draw() {
  // Expand array size to the number of bytes you expect
  byte[] inBuffer = new byte[2];
  while (myPort.available() > 0) {
    inBuffer = myPort.readBytes();
    myPort.readBytes(inBuffer);
    if (inBuffer != null) {
      String myString = new String(inBuffer);
      println(myString);
    }
  }
}
