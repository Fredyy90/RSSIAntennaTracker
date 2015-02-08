#include "Config.h"

int servoPositionPan = SERVO_MID;
int servoPositionTilt = SERVO_MID;

void setup()
{
    lcdInit();
    servoInit();
}

void loop()
{
    triggerUpdates();
    servoDemo();
}

void triggerUpdates(){
    lcdUpdate();
}
