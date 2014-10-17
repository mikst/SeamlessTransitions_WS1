/*
  
  Reads an analog input on pin 0, prints the result to the serial monitor and turn on/off the output Pin in rhythm according to the sensor value
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  connect speaker to speaker pin and GND
 
 */
 
 // decide which pin will be output
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
  
  // output sound rhythm pattern according to the value from the potentiometer
  // the bigger the value is, the slower the pattern gets
  

  tone(speakerPin, 262);
  delay(sensorValue);
  noTone(8);
  delay(sensorValue);
  
  delay(1);        // delay in between reads for stability
}
