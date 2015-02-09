#include "Config.h"

int servoPositionPan = SERVO_MID;
int servoPositionTilt = SERVO_MID;

void setup()
{

    Serial.begin(115200);
    lcdInit();
    servoInit();

}

void loop()
{

    triggerUpdates();
    servoDemo();
    Serial.println(freeRam());
}

void triggerUpdates()
{

    rssiUpdate();
    lcdUpdate();

}

int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
