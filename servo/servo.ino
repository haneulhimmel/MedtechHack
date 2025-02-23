/*#include <Servo.h>

Servo myservo;

int trimPotentiometer = A7;
//int rotationMotor = 12;
int valRes = 0;
int offset = 0;
int val = 0;
bool direction = true;

void setup() {
  Serial.begin(9600);
  myservo.attach(12);
  //pinMode(rotationMotor, OUTPUT); // declares pin 12 as output
  pinMode(trimPotentiometer, INPUT);
}

void loop() {
  myservo.write(90);
  /*valRes = analogRead(trimPotentiometer);  // read the input pin
  offset = 1024 - valRes;
  val = map(valRes, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)

  Serial.print("Potentiometer Value: ");
  Serial.print(valRes);
  Serial.print(" | Servo Angle: ");
  Serial.println(val);

  //myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15); 

  if (val >= 180) {
    direction = -1;  // Reverse the direction
  }

  // If the servo reaches 0°, reverse direction again
  if (val <= 0) {
    direction = 1;  // Move forward again
  }

  myservo.write(val);


  digitalWrite(rotationMotor, HIGH); 
  delayMicroseconds(delay);   
  digitalWrite(rotationMotor, LOW);  
  delayMicroseconds(valRes); */
//}

#include <Servo.h>

int pot = A7;  // Potentiometer pin
Servo myServo;
int val = 0;  // Initialize the angle
int offset = 0;
int valRes = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  myServo.attach(12);  // Attach the servo to pin 12
  myServo.write(val);  // Set initial position
  delay(1000);  // Wait for a second to ensure the servo is at the initial position
}

void loop() {
  valRes = analogRead(pot);  // Read the potentiometer value
  offset = 1024 - valRes;
  val = map(valRes, 0, 1023, 0, 180);  // Map it to servo's range (0 to 180)

  Serial.print("Pot: ");
  Serial.print(valRes);
  Serial.print('\n');
  Serial.print("Scale Val: ");
  Serial.println(val);

  if (offset <= 730) {
    myServo.write(90);  // Set the servo to 90° if the offset is below 730
  } else {
    myServo.write(val);  // Otherwise, move the servo based on potentiometer value
  }

  delay(15);  // Small delay to smooth the motion
}

