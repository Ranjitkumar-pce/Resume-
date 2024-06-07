// C++ code
//
#include<Servo.h>
float distance,duration;
int tp=9,ep=10;
Servo ms;
int pos;
void setup()
{
 pinMode(tp,OUTPUT);
 pinMode(ep,INPUT);
 Serial.begin(9600);
 ms.attach(4) ;

}

void loop()
{
 digitalWrite(tp,0);
 delayMicroseconds(2);
 digitalWrite(tp,1);//send waves for 10 micro second 
 delayMicroseconds(10);
 duration=pulseIn(ep,HIGH);//receive reflected waves
 distance=duration/60;//convert to distance

 if(distance<=25)
 {
     //for opening of dustbin
      ms.write(0);
      delay(20);
   }
  
 
 //if(distance>=26&&distance<=50)
 else if(distance>=26 && distance!=0)
 {                                      //for closing of dustbin
          ms.write(90);
          delay(2000);
      }
   
 
 
     
 //delay(10);

Serial.println(distance);
}