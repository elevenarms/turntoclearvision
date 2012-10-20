#include <Servo.h>

byte byteRead;
long num1, num2,answer;
boolean mySwitch=false;
Servo servoTilt, servoPan;
void setup() {                
  Serial.begin(9600);
  num1=0;
  num2=0;
  servoTilt.attach(2);  //The Tilt servo is attached to pin 2.
  servoPan.attach(3);   //The Pan servo is attached to pin 3.
  servoTilt.write(90);  //Initially put the servos both
  servoPan.write(90);      //at 90 degress.
}

void loop() {
  while (Serial.available()) {
    byteRead = Serial.read();
    
    if(byteRead>47 && byteRead<58){
       if(!mySwitch){
         num1=(num1*10)+(byteRead-48);
       }else{
         num2=(num2*10)+(byteRead-48);
       }
    }
    
    /*Listen for an equal sign (byte code 61) 
      to calculate the answer and send it back to the
      serial monitor screen*/
    if(byteRead==61){
      
      servoTilt.write(num1);
      servoPan.write(num2);

      num1=0;
      num2=0;
      mySwitch=false;
      
    /* Listen for the addition sign (byte code 43). This is
       used as a delimiter to help define num1 from num2 */  
    }else if (byteRead==43){
      mySwitch=true;
    }
  }
}
