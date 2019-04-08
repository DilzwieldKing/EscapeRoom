//Escape Room Puzzle One
//By Joseph Eiles

#include <Servo.h>

Servo myservo;

const int analogInPin1 = A1;
const int analogInPin2 = A2;
const int analogInPin3 = A3;
const int buzzer = 4;
int motorPin = 3;
int freq = 100;

//The answer values for the potentiometers
const int answerOne = 48;
const int answerTwo = 78;
const int answerThree = 96;

int sensorValue1 = 0;
int outputValue1 = 0;
int sensorValue2 = 0;
int outputValue2 = 0;
int sensorValue3 = 0;
int outputValue3 = 0;

//Variable to store servo position
int pos = 0;

void setup() {
  //Sets the initial state for the buzzer, motor, and servo
  Serial.begin(9600);
  myservo.attach(6);
  pinMode(buzzer, OUTPUT);
  pinMode(motorPin,OUTPUT) ;
  tone(buzzer, freq);
  digitalWrite(motorPin, LOW);
  myservo.write(55);
}

void loop() {
  //Calculates the difference between the answer key and the mapped output value of the potentiometers
  int difference1 = outputValue1 - answerOne;
  int difference2 = outputValue2 - answerTwo;
  int difference3 = outputValue3 - answerThree;

  //Reads the potentiometer values, then converts them into a range of 0 - 100
  sensorValue1 = analogRead(analogInPin1);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 100);
  sensorValue2 = analogRead(analogInPin2);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 100);
  sensorValue3 = analogRead(analogInPin3);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 100);

  //Determines if the absolute difference of the values calculated earlier are within a range of 10, if true then the motor and buzzer turn off, servo angle changes.
  if (abs(difference1) < 10 && abs(difference2) < 10 && abs(difference3) < 10){
    noTone(buzzer);     // Stop sound...
    digitalWrite(motorPin,HIGH);
    myservo.write(180);
    delay(10);
  }else{
    delay(10);
  }

  Serial.println(outputValue1);
  Serial.print("    ");
  Serial.print(outputValue2);
  Serial.print("    ");
  Serial.print(outputValue3);
  Serial.print("    ");

  delay(2);
}
