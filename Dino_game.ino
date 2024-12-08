#include <Servo.h>

Servo serv; //adding the servo
int light; //amount of light we collect from the sensor
int ang; //angle of the servo
const int sens = A7; 
const int limit = 870; //a number little bit less than the amount of a whith light.
// you should measure the limit by yourself. It changes as the resistor you use' I use 10K.
const int G = 2; //pin for green light in RGB
const int B = 3; //pin for blue light in RGB 
int loopCounter = 0; //counter to know if the Arduino is restarting
//beacuse of voltage issues, the Arduino may restart.

void setup() {
  Serial.begin(9600);                                                                
  serv.attach(A2);
  serv.write(0); //the firs angle of the arduino, for the SPACE BAR is free.
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.println("Arduino is starting up!"); // to know if the Arduino is restarting
}

void loop() {                                                                 
  light = analogRead(sens);
  if (light > limit) {  //dino is running, no jump
    ang = 0;
    digitalWrite(G,125);
    digitalWrite(B, LOW);
    }                                                                              
  else {//dino needs to jump       
    ang = 30; //angle of the servo to press the SPACE BAR                                          
    digitalWrite(B, 125);
    digitalWrite(G, LOW);                                                      
    } 

  serv.write(ang);
  delay(15); //small delay to make sure the servo has time to change the angle
  digitalWrite(B, LOW);
  digitalWrite(G, LOW);
  Serial.println(light); //print on the screen the amount of light we collect from the sensor
  loopCounter++;
  Serial.print("Loop counter: ");
  Serial.println(loopCounter);
  }