#include "Config.h"

void rssiUpdate()
{

    rssiUpdateValue(rssiLeftHelix, analogRead(RSSI_PIN_LEFT_HELIX));
    rssiUpdateValue(rssiCenterHelix, analogRead(RSSI_PIN_CENTER_HELIX));
    rssiUpdateValue(rssiRightHelix, analogRead(RSSI_PIN_RIGHT_HELIX));
    rssiUpdateValue(rssiSPW, analogRead(RSSI_PIN_SPW));

}

void rssiUpdateValue(struct RSSI &rssi, int value)
{

    rssi.current = value;
    rssi.max = max(rssi.max, value);
    rssi.min = min(rssi.min, value);
    rssi.normalised = map(rssi.current, rssi.min, rssi.max, 0, 256);

}
