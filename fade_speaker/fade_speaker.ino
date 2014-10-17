/*
  
  Reads an analog input on pin 0, prints the result to the serial monitor and turn on/off the output Pin in rhythm according to the sensor value
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  connect speaker to speaker pin and GND
 
 */
 
 int speakerPin=11;
 
  // a variable to store the sensor value
 int sensorValue=0;

// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  
 // convert the sensorValue number (0-1023) to pitch range (120-1500)
 int thisPitch = map(sensorValue, 0,1023,120,1500);
 
 // output the sound (120-1500 frequency range)
  tone(9, thisPitch, 10);
 
  
  delay(1);        // delay in between reads for stability
}
