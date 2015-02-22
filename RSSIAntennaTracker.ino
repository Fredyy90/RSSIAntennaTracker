#include "Config.h"

void setup()
{

    #ifdef SERIAL_DEBUGGING
        Serial.begin(115200);
    #endif
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

    #ifdef SERIAL_DEBUGGING
        Serial.println(freeRam());
    #endif

}

#ifdef SERIAL_DEBUGGING
    int freeRam ()
    {
      extern int __heap_start, *__brkval;
      int v;
      return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
    }
#endif
