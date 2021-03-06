#include <Servo.h>
#include "Config.h"

void servoInit()
{

    servoPan.attach(SERVO_PAN_PIN);
    servoTilt.attach(SERVO_TILT_PIN);

}

#ifdef DEMO_MODE
    void servoDemo()
    {

        servoScan(servoPan, servoPositionPan, servoMapPan);
        delay(1000);
        servoScan(servoTilt, servoPositionTilt, servoMapTilt);
        delay(1000);

    }
#endif

void servoMove(char direction)
{

    Servo servo;

    if(direction == SERVO_DIRECTION_LEFT or direction == SERVO_DIRECTION_RIGHT){

        servoMovePan(direction);

    }else if(direction == SERVO_DIRECTION_UP or direction == SERVO_DIRECTION_DOWN){

        servoMoveTilt(direction);

    }

}

void servoMoveTilt(char direction)
{

    if(direction == SERVO_DIRECTION_DOWN && servoPositionTilt > SERVO_MIN){

        servoPositionTilt = max(servoPositionTilt - SERVO_PAN_STEP, SERVO_MIN);

    }else if(direction == SERVO_DIRECTION_UP && servoPositionTilt < SERVO_MAX){

        servoPositionTilt = min(servoPositionTilt + SERVO_PAN_STEP, SERVO_MAX);

    }

    servoTilt.writeMicroseconds(servoMapTilt(servoPositionTilt));

}

void servoMovePan(char direction)
{

    if(direction == SERVO_DIRECTION_LEFT && servoPositionPan > SERVO_MIN){

        servoPositionPan = max(servoPositionPan - SERVO_PAN_STEP, SERVO_MIN);

    }else if(direction == SERVO_DIRECTION_RIGHT && servoPositionPan < SERVO_MAX){

        servoPositionPan = min(servoPositionPan + SERVO_PAN_STEP, SERVO_MAX);

    }

    servoPan.writeMicroseconds(servoMapPan(servoPositionPan));

}

int servoMapTilt(int pos)
{

    return round(map(pos, SERVO_MIN, SERVO_MAX, SERVO_TILT_MIN, SERVO_TILT_MAX));

}

int servoMapPan(int pos)
{

    return round(map(pos, SERVO_MIN, SERVO_MAX, SERVO_PAN_MIN, SERVO_PAN_MAX));

}

void servoScan(Servo &servo, int &pos, int (*map)(int))
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
