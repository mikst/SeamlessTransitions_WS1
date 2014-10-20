/*
  
  Reads an analog input on pin 0, prints the result to the serial monitor and turn on/off the output Pin in rhythm according to the sensor value
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  connect servo motor control pin to servo pin, power to 5V and GND to GND
 
 */
 
 #include <Servo.h> 

 Servo myservo;  // create servo object to control a servo 

 // decide which pin will be output, for the fading, it works only on pin 3, 5, 6, 9, 10, and 11
 int servoPin=9;
 
  // a variable to store the sensor value
 int sensorValue=0;

// the setup routine runs once when you press reset:
void setup() {
  
    myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  
 // convert the sensorValue number (0-1023) to servo position range (0-179)
 int servoValue = map(sensorValue, 0,1023,0,179);
 
 // turn the servo motor to the position according to the scaled value 
  myservo.write(servoValue);
 delay(15); 
  
  delay(1);        // delay in between reads for stability
}
