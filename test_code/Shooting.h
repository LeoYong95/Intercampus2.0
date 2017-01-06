//Auth:Leo Yong

//This is the calss controlling the ping pong ball shooting mechanism.
//There is no control of the BLDC motor here because the motor is directly controlled by the receiver via channel 3 (Throttle channel)

#include<Servo.h>
#include "Param.h"

//=====BEGIN Shooting CLASS=====
class Shooting {

  public:
  Servo servo;
  int escPin, relayPin, servoPin ; 
  int prevTime;  
  
  Shooting ( int relay, int servo_) :relayPin(relay), servoPin(servo_) {
    
    pinMode (relayPin, OUTPUT);
    servo.attach(servoPin);
    }

void Shooting_Initiate(int pwmIn6 ) {
  
 if (pwmIn6 >= 1000 && pwmIn6 <= 1500){
          digitalWrite(relayPin,LOW);
          

  } else if(pwmIn6 >= 1500 && pwmIn6 <= 2000) {
          digitalWrite(relayPin,HIGH);
          servo.write(SRVSTOP);
       
  }else { 
    servo.write(70);
  }
}

};
//=====END CLASS======
