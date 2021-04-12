

const int enablePin1 = 9; // H-bridge enable pin for motor 1
const int motorLeft = 3; // arduino pin that controls 1A
const int motorRight = 4; // arduino pin that controls 2A

const int enablePin2 = 10; // H-bridge enable pin for motor 2
const int motor2Left = 5; // arduino pin that controls 3A
const int motor2Right = 6; // arduino pin that controls 4A


void setup()
{
 	pinMode(enablePin1,OUTPUT);
  	pinMode(motorLeft,OUTPUT);
	pinMode(motorRight,OUTPUT);
 
  	pinMode(enablePin2,OUTPUT);
  	pinMode(motor2Left,OUTPUT);
	pinMode(motor2Right,OUTPUT);
  
  	digitalWrite(enablePin1,HIGH);
    digitalWrite(enablePin2,HIGH);
  // Turns both motors left
  /*
  	digitalWrite(enablePin1,HIGH);
  	digitalWrite(motorLeft,HIGH);
  	digitalWrite(motorRight,LOW);
  
   	digitalWrite(enablePin2,HIGH);
  	digitalWrite(motor2Left,HIGH);
  	digitalWrite(motor2Right,LOW);
  */
	
  	Serial.begin(9600);
	Serial.print("WHYYYY");

}

void loop(){
	
}

void changeDir(){
	digitalWrite(motorLeft,!digitalRead(motorLeft));
  	digitalWrite(motorRight,!digitalRead(motorRight)); 
	digitalWrite(motor2Left,!digitalRead(motor2Left));
  	digitalWrite(motor2Right,!digitalRead(motor2Right));
  	// Serial.println("CHANGED DIRECTION");
}
