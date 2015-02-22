#ifndef SERVO_H
#define SERVO_H

#include <Servo.h>

int servoPositionPan = SERVO_MID;
int servoPositionTilt = SERVO_MID;

Servo servoPan;
Servo servoTilt;

void servoScan(Servo &servo, int &pos, int (*map)(int));

#endif /* SERVO_H */
