//declare pins
# define echoPin 7 //Echo pin
# define trigPin 8 //Trigger Pin

// establish a variable to track the duration of the echo
long duration; //output from sonar module
int distance;

void setup() {
    Serial.begin(9600);
 	//setup pins. Trigger pin is an output,
 	//echo pin receives the input
 	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
  	Serial.begin(9600);
	  
}
void loop() {
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
  
	//Delay 50ms before next reading.
	delay(500);
  
}