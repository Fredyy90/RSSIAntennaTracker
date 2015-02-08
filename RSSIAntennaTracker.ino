#include <Servo.h> 
#include "Config.h"

 
Servo servoPan;  
Servo servoTilt;  

int positionPan = SERVO_MID;
int positionTilt = SERVO_MID;


void servoScan(Servo servo, int &pos, int (*map)(int));

void setup()
{
  initLCD();
  servoPan.attach(SERVO_PAN_PIN);
  servoTilt.attach(SERVO_TILT_PIN);
}

void loop()
{
  triggerUpdates();
  servoScan(servoPan, positionPan, mapPanServo);
  delay(1000);
  servoScan(servoTilt, positionTilt, mapTiltServo);
  delay(1000);
}

void triggerUpdates(){
  updateLCD();
}


int mapTiltServo(int pos){
  return round(map(pos, SERVO_MIN, SERVO_MAX, SERVO_TILT_MIN, SERVO_TILT_MAX));  
}
int mapPanServo(int pos){
  return round(map(pos, SERVO_MIN, SERVO_MAX, SERVO_PAN_MIN, SERVO_PAN_MAX));  
}

void servoScan(Servo servo, int &pos, int (*map)(int)){
  for(pos = SERVO_MID; pos <= SERVO_MAX; pos += SCAN_STEP)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo.writeMicroseconds(map(pos));              // tell servo to go to position in variable 'pos' 
    triggerUpdates();
    delay(SCAN_DELAY);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = SERVO_MAX; pos >= SERVO_MIN; pos -= SCAN_STEP)     // goes from 180 degrees to 0 degrees 
  {                                
    servo.writeMicroseconds(map(pos));              // tell servo to go to position in variable 'pos' 
    triggerUpdates();
    delay(SCAN_DELAY);                       // waits 15ms for the servo to reach the position 
  }   
  for(pos = SERVO_MIN; pos <= SERVO_MID; pos += SCAN_STEP)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo.writeMicroseconds(map(pos));              // tell servo to go to position in variable 'pos' 
    triggerUpdates();
    delay(SCAN_DELAY);                       // waits 15ms for the servo to reach the position 
  } 
  
}
