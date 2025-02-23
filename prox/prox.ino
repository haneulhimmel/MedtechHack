//Reference for IR Sensor: https://playwithcircuit.com/interfacing-ir-sensor-module-with-arduino/

#include <Servo.h>

//int pot = A7;  // Potentiometer pin
Servo myServo;
int val = 0;  // Initialize the angle
int offset = 0;
int valRes = 0;
int sensorInput = 10;
int distance = 0;
int sensorReturn = 0;
long previousDetect = 0;
//static bool timerActive = false;

long interval = 3000;

void setup() {
  Serial.begin(9600);
  pinMode(sensorInput, INPUT);
  myServo.attach(12);  // Attach the servo to pin 12
  myServo.write(val);  // Set initial position
  delay(1000);  // Wait for a second to ensure the servo is at the initial position

  previousDetect = 0;
}

/*bool checkSensor(int *sensorReturn) {
  int measuredVal1;
  int measuredVal2;
  bool detected;

  //Read information from sensor port for conditionals
  measuredVal1 = digitalRead(sensorInput);
  delay(20);
  measuredVal2 = digitalRead(sensorInput);

  //If measured distance remains equal for both detections, return object detected as result
  if (measuredVal1 == measuredVal2) {
    detected = true;
    
    //Ptr to sensorReturn set to measuredVal1
    *sensorReturn = measuredVal1;
  } else {
    detected = false;
  }
  return detected;
}*/

void loop() {
  bool result;
  bool reset = false;
  unsigned long currentDetect;
  static bool timerActive = false;

  //Calls function to load boolean result into var result
  sensorReturn = digitalRead(sensorInput);

  
  //if (result == true) {
    /*if (sensorReturn == LOW && timerActive == false) {
        Serial.print("Object Near\n");
        //distance = 0;
        myServo.write(0);
        timerActive = true;
        currentDetect = millis();
    } else if ((sensorReturn == LOW && timerActive == true)) {
        if (currentDetect - previousDetect >= interval) {
          previousDetect = currentDetect;
          reset = true;
        }
        if (reset == true) {
          myServo.write(90);
          timerActive = false;
          reset = false;
        }
    }*/
    if (sensorReturn == LOW && !timerActive) {
        Serial.print("Object Near\n");
        //distance = 0;
        myServo.write(0);
        timerActive = true;
    } else if (sensorReturn == LOW && timerActive) {
      Serial.print("Object Far\n");
      myServo.write(90);
      timerActive = false;
    }
    delay(2000);
}

