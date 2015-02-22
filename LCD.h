#ifndef LCD_H
#define LCD_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(LCD_I2C_ADDR, LCD_EN_PIN, LCD_RW_PIN, LCD_RS_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

unsigned long lcdDebounce = 0;

#endif /* LCD_H */
