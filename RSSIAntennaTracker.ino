#include "Config.h"

uint8_t servoPositionPan = SERVO_MID;
uint8_t servoPositionTilt = SERVO_MID;

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
}

void triggerUpdates()
{

    rssiUpdate();
    lcdUpdate();
    Serial.println(freeRam());

}

int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
