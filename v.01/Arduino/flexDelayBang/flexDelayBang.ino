/*
 Flex sensor - turns on LCD screen for 10 seconds, then turn off
 adjust interval to adjust the time LCD stays on
 adjust threshold for flex sensor sensitivity

 The circuit:

 Flex sensor - 
   silver leg goes to 5v
   other leg goes to point A
   point A goes to 1M ohm resistor, which then goes to ground
   point A goes to Arduino Analog Input pin 0
 
 LCD screen - 
   TIP 120 with label facing you is BCE
   B goes to 2.2k ohm resistor, which then goes to Arduino D7
   C goes to "negative" end of LCD
   "positive" end of LCD goes to 12v
   E goes to common ground (ground Arduino and ground LCD)
 when D7 triggers Base, Collector allows 12v to drop through LCD screen

 Flex sensor triggers LCD to turn on for 10 seconds
 
 */

// constants won't change. They're used here to 
// set pin numbers:
const int flexPin = 0;      // flex sensor
const int ledPin =  13;      // the number of the LED pin
const int outPin = 7;

// variables for flex sensor
int flexReading = 0;
int buttonState = 0;         // variable for reading the pushbutton status
int previousState = 0;
int startTime;
int elapsedTime;
int interval = 20000;
int threshold = 500;

void setup() {
  Serial.begin(9600);

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);    
  pinMode(outPin, OUTPUT);  
  // initialize the flex sensor pin as an input:
  pinMode(flexPin, INPUT);     
}

void loop(){
  flexReading = analogRead(flexPin);
  // read the state of the pushbutton value:
  if (flexReading > threshold) {
    buttonState = HIGH;
  } else {
    buttonState = LOW;
  }

  // check if the flex sensor is triggered
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH && previousState == LOW) {  
    startTime = millis(); 
    // turn LED on:    
    digitalWrite(ledPin, HIGH);
    digitalWrite(outPin, HIGH);
    previousState = HIGH;    
  } 
  else if (previousState == HIGH) {
    elapsedTime = millis() - startTime;
    Serial.println(elapsedTime);
    if (elapsedTime >= interval) {
      digitalWrite(ledPin, LOW);
      digitalWrite(outPin, LOW); 
      previousState = LOW;     
    } else {
       previousState = HIGH;
    }
  } else {
    previousState = LOW;
  }
}
