#include "Config.h"
#include "RSSI.h"
#include "Tracker.h"

void trackerRun()
{

    triggerUpdates();
    trackerRunPan();
    trackerRunTilt();
}

void trackerRunPan()
{

    while(rssiLeftHelix.normalised - rssiCenterHelix.normalised > TRACKER_RSSI_MIN_OFFSET){

        trackerMove(SERVO_DIRECTION_LEFT);

    }

    while(rssiRightHelix.normalised - rssiCenterHelix.normalised > TRACKER_RSSI_MIN_OFFSET){

        trackerMove(SERVO_DIRECTION_RIGHT);

    }

}

void trackerMove(char direction){

    servoMove(direction);
    delay(TRACKER_STEP_DELAY);
    triggerUpdates();

}

void trackerUpdateOldRSSIValues(){

    trackerOldRSSILeftHelix   = rssiLeftHelix.normalised;
    trackerOldRSSIRightHelix  = rssiRightHelix.normalised;
    trackerOldRSSICenterHelix = rssiCenterHelix.normalised;

}

char trackerCompareRSSIValues(){

    if(trackerOldRSSILeftHelix   < rssiLeftHelix.normalised
    && trackerOldRSSIRightHelix  < rssiRightHelix.normalised
    && trackerOldRSSICenterHelix < rssiCenterHelix.normalised){

        return TRACKER_RSSI_HIGHER;

    }else{

        return TRACKER_RSSI_LOWER;

    }

}

void trackerRunTilt()
{

    do{

        trackerUpdateOldRSSIValues();
        trackerMove(SERVO_DIRECTION_UP);

    }while( trackerCompareRSSIValues() == TRACKER_RSSI_HIGHER );

    trackerMove(SERVO_DIRECTION_DOWN);

    do{

        trackerUpdateOldRSSIValues();
        trackerMove(SERVO_DIRECTION_DOWN);

    }while( trackerCompareRSSIValues() == TRACKER_RSSI_HIGHER );

    trackerMove(SERVO_DIRECTION_UP);

}
