#include<Servo.h>
#include "Param.h"

//=====BEGIN Channel CLASS=====
class Shooting {

  public:
  Servo esc;
  Servo servo;
  int escPin, relayPin, servoPin ; 
  int prevTime;  
  
  Shooting (int esc_, int relay, int servo_) : escPin(esc_), relayPin(relay), servoPin(servo_) {
    esc.attach(escPin);
    pinMode (relayPin, OUTPUT);
    servo.attach(servoPin);
    }

void Shooting_Initiate(int pwmIn6 ) {
  
 if (pwmIn6 >= 1000 && pwmIn6 <= 1500){
          digitalWrite(relayPin,LOW);
          esc.writeMicroseconds(1000);
          servo.write(SRVSTOP);
          Serial.println("Lalalala");
          

  } else if(pwmIn6 >= 1500 && pwmIn6 <= 2000) {
          digitalWrite(relayPin,HIGH);
         // esc.writeMicroseconds(1000);
          //delay(100);
          Serial.println("calling me");
          servo.write(SRVSTOP);
          esc.writeMicroseconds(1700);
       
  }else { 
    esc.writeMicroseconds(1700);
    servo.write(70);
  }
}

};
//=====END CLASS======
