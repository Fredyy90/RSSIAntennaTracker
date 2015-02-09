#include <Servo.h>
#include "Config.h"


Servo servoPan;
Servo servoTilt;

void servoScan(Servo servo, int &pos, int (*map)(int));

void servoInit()
{

    servoPan.attach(SERVO_PAN_PIN);
    servoTilt.attach(SERVO_TILT_PIN);

}

void servoDemo()
{

    servoScan(servoPan, servoPositionPan, servoMapPan);
    delay(1000);
    servoScan(servoTilt, servoPositionTilt, servoMapTilt);
    delay(1000);

}

int servoMapTilt(int pos)
{

    return round(map(pos, SERVO_MIN, SERVO_MAX, SERVO_TILT_MIN, SERVO_TILT_MAX));

}
int servoMapPan(int pos)
{

    return round(map(pos, SERVO_MIN, SERVO_MAX, SERVO_PAN_MIN, SERVO_PAN_MAX));

}

void servoScan(Servo servo, int &pos, int (*map)(int))
{

    for(pos = SERVO_MID; pos <= SERVO_MAX; pos += SCAN_STEP)
    {
        servo.writeMicroseconds(map(pos));
        triggerUpdates();
        delay(SCAN_DELAY);
    }

    for(pos = SERVO_MAX; pos >= SERVO_MIN; pos -= SCAN_STEP)
    {
        servo.writeMicroseconds(map(pos));
        triggerUpdates();
        delay(SCAN_DELAY);
    }

    for(pos = SERVO_MIN; pos <= SERVO_MID; pos += SCAN_STEP)
    {
        servo.writeMicroseconds(map(pos));
        triggerUpdates();
        delay(SCAN_DELAY);
    }

}
