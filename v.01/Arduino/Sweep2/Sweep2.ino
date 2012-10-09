// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.
// Modified by Rio Akasaka et. al for UP Makeathon 

#include <Servo.h> 
 
Servo tiltServo; 
Servo panServo; 

int pos = 0;    // variable to store the servo position 
int val = 0;
int tiltpin = 0;
int panpin = 1;
int pan = 0;

void setup() 
{ 
  tiltServo.attach(9);  // attaches the servo on pin 9 to the servo object 
  panServo.attach(10); // 
} 
 
void loop() 
{              
    val = analogRead(tiltpin); // read input pin
    val = map(val, 0, 1023, 0, 179); // map it to the same range
    pan = analogRead(panpin); // read input pin
    pan = map(pan, 0, 1023, 0, 179); // map it to the same range
    tiltServo.write(val); // write it to servo  
    delay(10);
    panServo.write(pan); // write it to servo     
    
   delay(10);
} 
