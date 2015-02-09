#include "Config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(LCD_I2C_ADDR, LCD_EN_PIN, LCD_RW_PIN, LCD_RS_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

long lcdDebounce = 0;

void lcdInit()
{

    lcd.begin (LCD_COLS, LCD_ROWS);
    lcd.setBacklightPin(LCD_BACKLIGHT_PIN, NEGATIVE);
    lcd.setBacklight(LCD_LED_ON);

}

void lcdUpdate()
{

    if ((millis() - lcdDebounce) > LCD_UPDATE_LIMIT) {

        lcdDebounce = millis();

        lcd.clear();

        // Row 1
        lcd.setCursor(0,0);
        lcd.print("Pan:");
        lcd.print(servoPositionPan);
        lcd.setCursor(8,0);
        lcd.print("Tilt:");
        lcd.print(servoPositionTilt);

        //Row 2
        lcd.setCursor(8,1);

    }

}
