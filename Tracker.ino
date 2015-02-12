#include "Config.h"

void trackerRun()
{

    triggerUpdates();
    trackerRunPan();
}

void trackerRunPan()
{

    while(rssiLeftHelix.normalised - rssiCenterHelix.normalised > TRACKER_RSSI_MIN_OFFSET){

        servoMove(SERVO_DIRECTION_LEFT);
        delay(TRACKER_STEP_DELAY);
        triggerUpdates();

    }

    while(rssiRightHelix.normalised - rssiCenterHelix.normalised > TRACKER_RSSI_MIN_OFFSET){

        servoMove(SERVO_DIRECTION_RIGHT);
        delay(TRACKER_STEP_DELAY);
        triggerUpdates();

    }

}
