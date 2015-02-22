/**
##############################
## RSSI Setup               ##
##############################
**/

#define RSSI_PIN_LEFT_HELIX A8
#define RSSI_PIN_CENTER_HELIX A9
#define RSSI_PIN_RIGHT_HELIX A10
#define RSSI_PIN_SPW A11


/**
##############################
## Servo Setup              ##
##############################
**/

#define SERVO_PAN_PIN 44
#define SERVO_PAN_MIN 2000     // pan servo left limit in ms
#define SERVO_PAN_MAX 1100     // pan servo right limit in ms
#define SERVO_PAN_STEP 2

#define SERVO_TILT_PIN 45
#define SERVO_TILT_MIN 1850    // tilt servo bottom limit in ms
#define SERVO_TILT_MAX 975     // tilt servo upper limit in ms
#define SERVO_TILT_STEP 2

#define SCAN_DELAY 50
#define SCAN_STEP 2

/**
##############################
## LCD Setup                ##
##############################
**/

//#define LCD_TYPE_SMALL
#define LCD_TYPE_LARGE

#ifdef LCD_TYPE_SMALL

	#define LCD_I2C_ADDR 0x20  // Define I2C Address for the PCF8574A

	#define LCD_COLS 16
	#define LCD_ROWS 2

	//---(Following are the PCF8574 pin assignments to LCD connections )----
	// This are different than earlier/different I2C LCD displays

	#define LCD_BACKLIGHT_PIN 7
	#define LCD_BACKLIGHT_POL NEGATIVE

	#define LCD_EN_PIN 4
	#define LCD_RW_PIN 5
	#define LCD_RS_PIN 6
	#define LCD_D4_PIN 0
	#define LCD_D5_PIN 1
	#define LCD_D6_PIN 2
	#define LCD_D7_PIN 3

#endif

#ifdef LCD_TYPE_LARGE

	#define LCD_I2C_ADDR 0x27  // Define I2C Address for the PCF8574A

	#define LCD_COLS 20
	#define LCD_ROWS 4

	//---(Following are the PCF8574 pin assignments to LCD connections )----
	// This are different than earlier/different I2C LCD displays

	#define LCD_BACKLIGHT_PIN 3
	#define LCD_BACKLIGHT_POL POSITIVE

	#define LCD_EN_PIN 2
	#define LCD_RW_PIN 1
	#define LCD_RS_PIN 0
	#define LCD_D4_PIN 4
	#define LCD_D5_PIN 5
	#define LCD_D6_PIN 6
	#define LCD_D7_PIN 7

#endif

#define LCD_LED_OFF 0
#define LCD_LED_ON 1

#define LCD_ROW_MID LCD_COLS/2

#define LCD_FPS 4
#define LCD_UPDATE_LIMIT 1000/LCD_FPS

/**
##############################
## Tracker Setup               ##
##############################
**/

#define TRACKER_STEP_DELAY 10
#define TRACKER_RSSI_MIN_OFFSET 5

/**
##############################
## Internal Servo Constants ##
##############################
**/

#define DEMO_MODE
#define SERIAL_DEBUGGING

#define SERVO_MIN 0            // internal servo position bottom/left
#define SERVO_MAX 255          // internal servo position top/right
#define SERVO_MID SERVO_MAX/2  // internal servo position center/center

#define SERVO_DIRECTION_LEFT 1
#define SERVO_DIRECTION_RIGHT 2
#define SERVO_DIRECTION_UP 3
#define SERVO_DIRECTION_DOWN 4

