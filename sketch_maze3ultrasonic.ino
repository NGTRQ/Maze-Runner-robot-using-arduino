
#include <AFMotor.h>

long detection(int trigPin,int echoPin);
long duration, distance;
int trigPinL = A0;
int echoPinL = A1;
int trigPinM = A2;
int echoPinM = A3;
int trigPinR = A4;
int echoPinR = A5;

AF_DCMotor motorL2 (1);
AF_DCMotor motorL (2);
AF_DCMotor motorR2(3);
AF_DCMotor motorR(4);
long dleft;
long dmiddle;
long dright;

void setup() {
 Serial.begin(9600);
pinMode(trigPinL, OUTPUT);
pinMode(echoPinL, INPUT);
pinMode(trigPinM, OUTPUT);
pinMode(echoPinM, INPUT);
pinMode(trigPinR, OUTPUT);
pinMode(echoPinR, INPUT);



}

void loop() {
dleft=detection(trigPinL,echoPinL);
Serial.print("Distancem: ");
Serial.println(dleft);
dmiddle=detection(trigPinM,echoPinM);
Serial.print("Distancem: ");
Serial.println(dmiddle);
dright=detection(trigPinR,echoPinR);
Serial.print("Distancem: ");
Serial.println(dright);


if(dmiddle>15){
moveForward();
}
else if(dmiddle<=15){ moveStop();
dright=detection(trigPinR,echoPinR);
dleft=detection(trigPinL,echoPinL);

if(dleft>dright&&dleft>10){ turnLeft();
}
else if(dright>dleft&&dright>10){
turnRight();
}

 
}
} 

long detection(int trigPin,int echoPin){

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;
return distance;
}
void turnRight() {
motorR.setSpeed(130);
motorL.setSpeed (165);
motorR.run(BACKWARD);
motorL.run(FORWARD); 
motorL2.setSpeed(165);
motorR2.setSpeed (130); 
motorL2.run(FORWARD); 
motorR2.run(BACKWARD); 

}
void turnLeft() {
motorR.setSpeed(130);
motorL.setSpeed (165);
motorR.run(FORWARD);
motorL.run(BACKWARD); 
motorL2.setSpeed(165);
motorR2.setSpeed (130); 
motorL2.run(BACKWARD); 
motorR2.run(FORWARD); 

}
void moveForward(){
motorR.setSpeed(120);
motorL.setSpeed (120);
motorR.run(FORWARD);
motorL.run(FORWARD); 
motorL2.setSpeed(120);
motorR2.setSpeed (120); 
motorL2.run(FORWARD); 
motorR2.run(FORWARD); 
}
void moveBackward(){
motorR.setSpeed(165);
motorL.setSpeed (165);
motorR.run(FORWARD);
motorL.run(FORWARD); 
motorL2.setSpeed(165);
motorR2.setSpeed (165); 
motorL2.run(FORWARD); 
motorR2.run(FORWARD); 
}
void moveStop(){
motorR.setSpeed(0);
motorL.setSpeed (0);
motorL2.setSpeed(0); 
motorR2.setSpeed (0); 
motorR.run(RELEASE);
motorL.run(RELEASE); 
motorL2.run(RELEASE); 
motorR2.run(RELEASE); 
  }

  
  
  
  
