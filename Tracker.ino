#include "Config.h"

void trackerRun()
{

    triggerUpdates();
    trackerRunPan();
}

void trackerRunPan()
{

    while(rssiNormalisedValue(rssiLeftHelix) > rssiNormalisedValue(rssiCenterHelix)){

        servoMove(SERVO_DIRECTION_LEFT);
        delay(TRACKER_STEP_DELAY);
        triggerUpdates();

    }

    while(rssiNormalisedValue(rssiRightHelix) > rssiNormalisedValue(rssiCenterHelix)){

        servoMove(SERVO_DIRECTION_RIGHT);
        delay(TRACKER_STEP_DELAY);
        triggerUpdates();

    }

}
