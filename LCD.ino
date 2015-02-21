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

    if(rssi.percent >= 100){
        lcd.print(" ");
    }else if(rssi.percent >= 10){
        lcd.print("  ");
    }else{
        lcd.print("   ");
    }

    lcd.print(rssi.percent);
    lcd.print("%");

}

void lcdDrawValue(char postion, char row, char* name, int value){


    lcd.setCursor(postion, row);
    lcd.print(name);

    if(value >= 100){
        lcd.print(" ");
    }else if(value >= 10){
        lcd.print("  ");
    }else{
        lcd.print("   ");
    }

    lcd.print(value);

}

void lcdUpdate()
{

    if ((millis() - lcdDebounce) > LCD_UPDATE_LIMIT) {

        lcdDebounce = millis();

        lcd.clear();

        // Row 1
        lcdDrawValue(0, 0, "Pan: ", servoPositionPan);
        lcdDrawValue(LCD_ROW_MID, 0, "Tilt:", servoPositionTilt);

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
