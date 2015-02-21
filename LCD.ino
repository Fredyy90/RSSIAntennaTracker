#include "Config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(LCD_I2C_ADDR, LCD_EN_PIN, LCD_RW_PIN, LCD_RS_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

long lcdDebounce = 0;

void lcdInit()
{

    lcd.begin (LCD_COLS, LCD_ROWS);
    lcd.setBacklightPin(LCD_BACKLIGHT_PIN, LCD_BACKLIGHT_POL);
    lcd.setBacklight(LCD_LED_ON);

}

void lcdDrawRSSI(char postion, char row, char* name, struct RSSI &rssi){


    lcd.setCursor(postion, row);
    lcd.print(name);
    lcd.print(" ");
    lcd.print(rssi.percent);
    lcd.print("%");

}

void lcdUpdate()
{

    if ((millis() - lcdDebounce) > LCD_UPDATE_LIMIT) {

        lcdDebounce = millis();

        lcd.clear();

        // Row 1
        lcd.setCursor(0,0);
        lcd.print("Pan: ");
        lcd.print(servoPositionPan);
        lcd.setCursor(LCD_ROW_MID,0);
        lcd.print("Tilt: ");
        lcd.print(servoPositionTilt);

        //Row 2
        /*
        lcd.setCursor(0,1);
        lcd.print("Row2");
        lcd.setCursor(LCD_ROW_MID,1);
        lcd.print("Row2");
        */

        #if LCD_ROWS > 2

            //Row 3
            lcdDrawRSSI(0, 2, "H-L:", rssiLeftHelix);
            lcdDrawRSSI(LCD_ROW_MID, 2, "H-R:", rssiRightHelix);

            //Row 4
            lcdDrawRSSI(0, 3, "H-C:", rssiLeftHelix);
            lcdDrawRSSI(LCD_ROW_MID, 3, "SPW:", rssiSPW);

        #endif

    }

}
