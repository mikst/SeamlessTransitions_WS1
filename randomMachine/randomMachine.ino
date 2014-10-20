#include <Servo.h> 
Servo myservo;  // create servo object to control a servo

// digitalPin2,3,4,6,7 are assigned for equalizer effect
int outputPin1=2;
int outputPin2=3;
int outputPin3=4;
int outputPin4=6;
int outputPin5=7;

// servo motor control pin will be attached to digitalPin 9
int servoPin=9;

// fade effect (LED, vibration motor..) will be attached to digitalPin5
int fadePin=5;

// Rythm pattern effect (LED, vibration motor..) will be attached to digitalPin10
int RhythmPin=10;

// Pich control effect speaker pin will be attached to digitalPin 11
int speakerPitchPin=11;

// timer related variables
long randomMillis=0;
long servoMillis=0;
long previousMillis = 0;        // will store last time LED was updated
boolean State = LOW;             // ledState used to set the LED

// mapping related variables
int randomValue=0;
int steps=0;
int fadeValue=0;
int servoValue=0;
int pitchValue=0;
int blinkValue=0;


void setup() {
  // set the pins to output
  pinMode(outputPin1,OUTPUT);
  pinMode(outputPin2,OUTPUT);
  pinMode(outputPin3,OUTPUT);
  pinMode(outputPin4,OUTPUT);
  pinMode(outputPin5,OUTPUT);

  pinMode(fadePin,OUTPUT);
  pinMode(RhythmPin,OUTPUT);

  // attaches the servopin to the servo object
  myservo.attach(servoPin); 

  // start Serial Communication
  Serial.begin(9600);

  // Calculate random value
  randomSeed(analogRead(5));
  randomValue=random(100);

  // report to the serial
  Serial.println(randomValue);
}

void loop() {

  // Every 3000 milisecond, the random number is re-calculated
  unsigned long currentMillis = millis();
  if(currentMillis - randomMillis > 3000) {
    // save the last state changing timing
    randomMillis = currentMillis;  
    // read the input on analog pin 0:
    int randomValue = random(100);

    // convert the randomValue number (0-100) to steps (0-5)
    steps = map(randomValue,0,100,0,6);

    // convert the randomValue number (0-100) to fading value range (0-255)
    fadeValue = map(randomValue, 0,100,0,256);

    // convert the randomValue number (0-100) to servo position range (0-179)
    servoValue = map(randomValue, 0,100,0,179);

    // convert the randomValue number (0-100) to servo position range (0-179)
    blinkValue = map(randomValue, 0,100,1000,10);

    // convert the randomValue number (0-100) to pitch range (120-1500)
    pitchValue = map(randomValue, 0,100,120,1500);


    // repoart the random number to the serial
       Serial.print("randomValue: ");
        Serial.println(randomValue);

  }

  // output the fadeValue (0-255) corresponding voltage. This will result in controling intensity of the light or turning speed of the motor
  analogWrite(fadePin,fadeValue);

  // output the equalizer effect steps
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

  // output the sound (120-1500 frequency range)
  tone(speakerPitchPin, pitchValue, 10);

  // every 15 milisecond, the servo is set to new position
  currentMillis = millis();
  if(currentMillis - servoMillis > 15) {
    // save the last state changing timing
    servoMillis = currentMillis;   
    // turn the servo motor to the position according to the scaled value 
    myservo.write(servoValue);
  }

  // blink the Rhythm Pin with the mapped random value
  if(currentMillis - previousMillis > blinkValue) {
    // save the last state changing timing
    previousMillis = currentMillis;   

    // flip the state:
    if (State == LOW)
      State = HIGH;
    else
      State = LOW;

    digitalWrite(RhythmPin, State);
  }

}


