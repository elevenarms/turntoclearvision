int potPin = 0;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor

void setup() {
  Serial.begin(57600);

}

void loop() {
  // Goes from 0 - 1024
  val = analogRead(potPin);    // read the value from the sensor
  Serial.println(val);
}
