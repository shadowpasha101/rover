//declare pins
# define echoPin 12 //Echo pin
# define trigPin 13 //Trigger Pin

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

// establish a variable to track the duration of the echo
long duration; //output from sonar module
int distance;

void setup() {
    Serial.begin(9600);
 	//setup pins. Trigger pin is an output,
 	//echo pin receives the input
 	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

    //motor stuff
    pinMode(enablePin1,OUTPUT);
  	pinMode(motor1A,OUTPUT);
	pinMode(motor1B,OUTPUT);
 
  	pinMode(enablePin2,OUTPUT);
  	pinMode(motor2A,OUTPUT);
	pinMode(motor2B,OUTPUT);
	  
}
void loop() {
  


}

int sonarRead(){ // reads distance from sonar sensor
//Trigger a pulse on the sonar module
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	//measure the duration of the echo
	duration = pulseIn(echoPin, HIGH);

  	Serial.print("duration: "); // in microseconds
	Serial.println(duration);
  	
    // sound travels at 343 meters per second, so it takes 29.155 microseconds per centimeter
  	distance = duration / 29 /2;
    //distance = duration / 58.3773 ;

  	Serial.print("distance: ");
  	Serial.println(distance);
  
    return distance;
	//Delay 50ms before next reading.
	// delay(500);

    /*
    sound travels at 343 meters per second, so it takes 29.155 microseconds per centimeter
  	distance = duration / 29 /2; // this formula was found to be more accurate
	distance = (duration / 2) * 0.0343;
    */
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

void goStraightNoStop(){ // runs straight forever
	//motor 1
	analogWrite(motor1A, speed);
	analogWrite(motor1B, 0); // 0 is for "off"

	//motor 2
	analogWrite(motor2A, speed); // both "A" pins are HIGH so they both turn the same direction
	analogWrite(motor2B, 0); // 0 is for "off"

}

void stopMotors(){ // stops all motors
    analogWrite(motor1A, 0); // 0 is for "off"
    analogWrite(motor1B, 0); // 0 is for "off"
    analogWrite(motor2A, 0); // 0 is for "off"
    analogWrite(motor2B, 0); // 0 is for "off"
}

void turnRight(int duration){ // turns right 90 degrees
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

void turnStep(int steps){ // takes in the amount of times we want to step

    for (int i = 0; i <= steps; i++){
    //motor 1
	analogWrite(motor1A, speed);
	analogWrite(motor1B, 0); // 0 is for "off"

	//motor 2
	analogWrite(motor2A, 0); // 0 is for "off"
	analogWrite(motor2B, speed); 
	// pin A and B are turned on so the motors turn in opposite directions

	delay(duration/steps); // keeps turning for the duration divided by step count
	
	// put logic for reading and moving here

	// stops both motors
	analogWrite(motor1A, 0);
	analogWrite(motor2B, 0);

    }
}


void followRight(){ 
    if (sonarRead() < 40){
      Serial.print("STOP");
        stopMotors();
		delay(200);
		turnRight(turnDuration);
		goStraight(duration);
	}
  else{
	goStraightNoStop();
  }

}