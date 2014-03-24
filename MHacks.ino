#include <Servo.h>  
Servo myservo;

#define ERROR 10
int pX = 0, pY = 0; 

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  myservo.attach(11);
  myservo.write(90); 
}

void loop(){
  int pulseX=0, pulseY=0;
  int accelerationX, accelerationY;
  int deltaX, deltaY;
  
  readKeyboard();
  
  pulseX = pulseIn(2, HIGH);
  pulseY = pulseIn(3, HIGH);
  
  accelerationX = ((pulseX /10) - 500) * 8;
  accelerationY = ((pulseY /10) - 500) * 8;
  
  deltaX = accelerationX - pX;
  if(deltaX < ERROR && deltaX > -ERROR)
    deltaX = 0;
    
  deltaY = accelerationY - pY;
  if(deltaY < ERROR && deltaY > -ERROR)
    deltaY = 0;
  
  
  /*if(deltaX > 0)
    Serial.print(accelerationX);
  else
    Serial.print(deltaX);
    
  Serial.print(",");
  if(deltaY > 0)
    Serial.print(accelerationY);
  else
    Serial.print(deltaY);
  
  Serial.println(",");*/
 // delay(100);
  pX = accelerationX;
  pY = accelerationY;
}


