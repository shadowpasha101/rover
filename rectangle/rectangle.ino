
const int enablePin1 = 4; // H-bridge enable pin for motor 1
const int motor1A = 3; // arduino pin that controls 1A
const int motor1B = 5; // arduino pin that controls 2A

const int enablePin2 = 7; // H-bridge enable pin for motor 2
const int motor2A = 6; // arduino pin that controls 3A
const int motor2B = 9; // arduino pin that controls 4A

const int moveDuration = 1000; // duration for straight bit
const int moveDuration2 = 1000; // duration for second straight bit
const int turnDuration = 800; // configure timing for turning of 90 degrees
const int speed = 127; // 0 - 255 for pwm - 127 for now which is half(ish)

// i am not using millis() right now

void setup(){
    // output for h-bridge and motor pins
    pinMode(enablePin1,OUTPUT);
  	pinMode(motor1A,OUTPUT);
	pinMode(motor1B,OUTPUT);
 
  	pinMode(enablePin2,OUTPUT);
  	pinMode(motor2A,OUTPUT);
	pinMode(motor2B,OUTPUT);

}


void loop(){
	//this is a basic template, we need to test to get a feel for the timings
	goStraight(moveDuration); // first straight
	delay(100);
	turnRight(turnDuration); 
	delay(100);
	goStraight(moveDuration2); // shorter length of rectangle
	delay(100);
	turnRight(turnDuration);
	delay(100);
	goStraight(moveDuration); // long length (2nd time)
	delay(100);
	turnRight(turnDuration);
	delay(100);
	goStraight(moveDuration2); // 2nd time short length
	delay(100);
	turnRight(turnDuration);
	delay(5000); //wait 5 seconds before going again

}


void goStraight(int duration){
	//motor 1
	analogWrite(motor1A, speed);
	analogWrite(motor1B, 0); // 0 is for "off"

	//motor 2
	analogWrite(motor2A, speed); // both "A" pins are HIGH so they both turn the same direction
	analogWrite(motor2B, 0); // 0 is for "off"

	delay(duration); // keeps going for specified amount of time
	
	// stops both motors
	analogWrite(motor1B, 0);
	analogWrite(motor2B, 0);

}

void turnRight(int duration){ // i actually dont know if this will turn right or left because it depends on other stuff
	//motor 1
	analogWrite(motor1A, speed);
	analogWrite(motor1B, 0); // 0 is for "off"

	//motor 2
	analogWrite(motor2A, 0); // 0 is for "off"
	analogWrite(motor2B, speed); 
	// pin A and B are turned on so the motors turn in opposite directions

	delay(duration); // keeps going for specified amount of time
	
	// stops both motors
	analogWrite(motor1A, 0);
	analogWrite(motor2B, 0);

}

