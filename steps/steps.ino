/*
  
  Reads an analog input on pin 0, prints the result to the serial monitor and turn on/off the output Pin in rhythm according to the sensor value
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  connect LED/ motor/ vibration motor to output pins (2,3,4,5,6,7,8,9) and GND
 
 */
 
 // this example is for 8 steps
 int StepNumber =5;
 
 // a variable to store the sensor value
 int sensorValue=0;

 int outputPin1=2;
 int outputPin2=3;
 int outputPin3=4;
 int outputPin4=5;
 int outputPin5=6;

 
 

// the setup routine runs once when you press reset:
void setup() {
  
  // set the pin to output
  pinMode(outputPin1,OUTPUT);
  pinMode(outputPin2,OUTPUT);
  pinMode(outputPin3,OUTPUT);
  pinMode(outputPin4,OUTPUT);
  pinMode(outputPin5,OUTPUT);

  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  
 // convert the sensorValue number (0-1023) to steps (0-5)
 int steps = map(sensorValue, 0,1023,0,StepNumber);
 
if (steps == 0){
  digitalWrite(outputPin1,LOW);
  digitalWrite(outputPin2,LOW);
  digitalWrite(outputPin3,LOW);
  digitalWrite(outputPin4,LOW);
  digitalWrite(outputPin5,LOW);

}

if (steps == 1){
  digitalWrite(outputPin1,HIGH);
  digitalWrite(outputPin2,LOW);
  digitalWrite(outputPin3,LOW);
  digitalWrite(outputPin4,LOW);
  digitalWrite(outputPin5,LOW);

}

if (steps == 2){
  digitalWrite(outputPin1,HIGH);
  digitalWrite(outputPin2,HIGH);
  digitalWrite(outputPin3,LOW);
  digitalWrite(outputPin4,LOW);
  digitalWrite(outputPin5,LOW);

}

if (steps == 3){
  digitalWrite(outputPin1,HIGH);
  digitalWrite(outputPin2,HIGH);
  digitalWrite(outputPin3,HIGH);
  digitalWrite(outputPin4,LOW);
  digitalWrite(outputPin5,LOW);

}

if (steps == 4){
  digitalWrite(outputPin1,HIGH);
  digitalWrite(outputPin2,HIGH);
  digitalWrite(outputPin3,HIGH);
  digitalWrite(outputPin4,HIGH);
  digitalWrite(outputPin5,LOW);

}

if (steps == 5){
  digitalWrite(outputPin1,HIGH);
  digitalWrite(outputPin2,HIGH);
  digitalWrite(outputPin3,HIGH);
  digitalWrite(outputPin4,HIGH);
  digitalWrite(outputPin5,HIGH);

}



 
  
  delay(1);        // delay in between reads for stability
}
