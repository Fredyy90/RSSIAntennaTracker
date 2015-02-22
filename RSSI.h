#ifndef RSSI_H
#define RSSI_H

struct RSSI {
  int current;
  int max;
  int min;
  int normalised;
  int percent;
};

RSSI rssiLeftHelix = { 0, 0, 0, 0};
RSSI rssiCenterHelix = { 0, 0, 0, 0};
RSSI rssiRightHelix = { 0, 0, 0, 0};
RSSI rssiSPW = { 0, 0, 0, 0};

#endif /* RSSI_H */
