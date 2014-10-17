/*
  
  Reads an analog input on pin 0, prints the result to the serial monitor and turn on/off the output Pin in rhythm according to the sensor value
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  connect LED/ motor/ vibration motor to output pin and GND
 
 */
 
 // decide which pin will be output, for the fading, it works only on pin 3, 5, 6, 9, 10, and 11
 int outputPin=5;
 
  // a variable to store the sensor value
 int sensorValue=0;

// the setup routine runs once when you press reset:
void setup() {
  
  // set the pin to output
  pinMode(outputPin,OUTPUT);
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  
 // convert the sensorValue number (0-1023) to fading value range (0-255)
 int fadeValue = map(sensorValue, 0,1023,0,255);
 
 // output the fadeValue (0-255) corresponding voltage. This will result in controling intensity of the light or turning speed of the motor
  analogWrite(outputPin, fadeValue);
 
  
  delay(1);        // delay in between reads for stability
}
