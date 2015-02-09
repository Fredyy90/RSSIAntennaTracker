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
        triggerUpdates();
        delay(TRACKER_STEP_DELAY);

    }

    while(rssiNormalisedValue(rssiRightHelix) > rssiNormalisedValue(rssiCenterHelix)){

        servoMove(SERVO_DIRECTION_RIGHT);
        triggerUpdates();
        delay(TRACKER_STEP_DELAY);

    }

}
