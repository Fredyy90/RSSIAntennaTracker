/**
##############################
## RSSI Setup               ##
##############################
**/

#define RSSI_PIN_LEFT_HELIX A0
#define RSSI_PIN_CENTER_HELIX A1
#define RSSI_PIN_RIGHT_HELIX A2
#define RSSI_PIN_SPW A3


/**
##############################
## Servo Setup              ##
##############################
**/

#define SERVO_PAN_PIN 44
#define SERVO_PAN_MIN 1100
#define SERVO_PAN_MAX 2000

#define SERVO_TILT_PIN 45
#define SERVO_TILT_MIN 1850
#define SERVO_TILT_MAX 975

#define SCAN_DELAY 50
#define SCAN_STEP 2

/**
##############################
## LCD Setup                ##
##############################
**/


#define LCD_I2C_ADDR    0x20  // Define I2C Address for the PCF8574A

#define LCD_COLS 16
#define LCD_ROWS 2

//---(Following are the PCF8574 pin assignments to LCD connections )----
// This are different than earlier/different I2C LCD displays

#define LCD_BACKLIGHT_PIN  7
#define LCD_EN_PIN  4
#define LCD_RW_PIN  5
#define LCD_RS_PIN  6
#define LCD_D4_PIN  0
#define LCD_D5_PIN  1
#define LCD_D6_PIN  2
#define LCD_D7_PIN  3

#define LCD_LED_OFF  0
#define LCD_LED_ON  1

#define LCD_UPDATE_LIMIT 250

/**
##############################
## Internal Servo Constants ##
##############################
**/

#define SERVO_MIN 0
#define SERVO_MAX 256
#define SERVO_MID SERVO_MAX/2

