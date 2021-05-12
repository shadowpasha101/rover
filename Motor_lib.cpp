#include "Motor_lib_H"
//Using same pins as raymonds motor library 
const int enablePin1 = 9; // H-bridge enable pin for motor 1 
const int motorLeft = 3; // arduino pin that controls 1A
const int motorRight = 4; // arduino pin that controls 2A

const int enablePin2 = 10; // H-bridge enable pin for motor 2
const int motor2Left = 5; // arduino pin that controls 3A
const int motor2Right = 6; // arduino pin that controls 4A

const int leeway_x_postive = 4; //in cm
const int leeway_y_postive = 4; //in cm
const int leeway_x_negative = 4; //in cm
const int leeway_y_negative = 4; //in cm

const int rover_length = 12; // in cm

const int 45_degree_turn_time = 1.5; // in seconds

const int 15_cm_time = 5; //in seconds

void forwardmotor(int enabler,int firstpin,int secondpin){
  digitalWrite(enabler,HIGH);
  analogWrite(firstpin,255);
  analogWrite(secondpin,0);
  //Using own variable names might need to changed.
}
void reversemotor(int enabler,int firstpin,int secondpin){
  digitalWrite(enabler,HIGH);
  analogWrite(firstpin,0);
  analogWrite(secondpin,255);
  //Using own variable names might need to changed.
}
void stopmotor(int enabler){
  digitalWrite(enabler,LOW);
 //Using own variable names might need to changed.

}

void setupmotor{// test for libaray
  Serial.begin(9600);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(motorLeft,OUTPUT);
  pinMode(motorRight,OUTPUT);
  pinMode(motor2Left,OUTPUT);
  pinMode(motor2Right,OUTPUT);
  
  digitalWrite(enablePin1,LOW);
  digitalWrite(enablePin2,LOW);
  digitalWrite(motorLeft,LOW);
  digitalWrite(motorRight,LOW);
  digitalWrite(motor2Left,LOW);
  digitalWrite(motor2Right,LOW);
}
  
void Go_Forward(){
  forwardmotor(enablePin1,motorLeft,motorRight);
  forwardmotor(enablePin2,motor2Left,motor2Right);
  delay(15_cm_time*1000);//not sure if delay needed
}
void Go_turn_45_left(){
  reversemotor(enablePin1,motorLeft,motorRight);
  forwardmotor(enablePin2,motor2Left,motor2Right);
  delay(45_degree_turn_time*1000);
}
void Go_turn_45_right(){
  forwardmotor(enablePin1,motorLeft,motorRight);
  reversemotor(enablePin2,motor2Left,motor2Right);
  delay(45_degree_turn_time*1000);
}

void motor_stop(){
  stopmotor(enablePin1);
  stopmotor(enablePin2);
}
void Go_turn_180(){
  forwardmotor(enablePin1,motorLeft,motorRight);
  reversemotor(enablePin2,motor2Left,motor2Right);
  delay(45_degree_turn_time*1000*4);
}
  

#endif
