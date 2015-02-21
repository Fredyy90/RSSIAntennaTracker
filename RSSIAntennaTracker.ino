#include "Config.h"

int servoPositionPan = SERVO_MID;
int servoPositionTilt = SERVO_MID;

struct RSSI {
  int current;
  int max;
  int min;
  int normalised;
};

RSSI rssiLeftHelix = { 0, 0, 0};
RSSI rssiCenterHelix = { 0, 0, 0};
RSSI rssiRightHelix = { 0, 0, 0};
RSSI rssiSPW = { 0, 0, 0};

void setup()
{

    Serial.begin(115200);
    lcdInit();
    servoInit();

}

void loop()
{

    triggerUpdates();

    #ifdef DEMO_MODE
        servoDemo();
    #else
        trackerRun();
    #endif

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
