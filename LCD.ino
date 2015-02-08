#include "Config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // F Malpartida's NewLiquidCrystal library
#include <MS561101BA.h>




LiquidCrystal_I2C  lcd(LCD_I2C_ADDR, LCD_EN_PIN, LCD_RW_PIN, LCD_RS_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
MS561101BA baro = MS561101BA();

long debounceLCD = 0;

void initLCD()
{
  
 lcd.begin (16,2);
 lcd.setBacklightPin(LCD_BACKLIGHT_PIN,NEGATIVE);
 lcd.setBacklight(LCD_LED_ON);
 baro.init(MS561101BA_ADDR_CSB_LOW); 
 
}


void updateLCD()
{
  if ((millis() - debounceLCD) > LCD_UPDATE_LIMIT) {
    
   debounceLCD = millis();
      
   lcd.clear();
   
   // Row 1
   lcd.setCursor(0,0); 
   lcd.print("Pan:");
   lcd.print(positionPan);
   lcd.setCursor(8,0); 
   lcd.print("Tilt:");
   lcd.print(positionTilt);
   
   //Row 2
   lcd.setCursor(8,1);
   lcd.print("Temp: ");
   lcd.print(round(baro.getTemperature(MS561101BA_OSR_4096)));
   lcd.print("C");
    
  }
}
