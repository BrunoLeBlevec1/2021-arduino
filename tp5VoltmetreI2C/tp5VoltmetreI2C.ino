#include <LCD_I2C.h>
#define PASVOLT (float)(5.0F / 1024.0F)

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup()
{
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
    lcd.print("Voltmetre 33.5V");
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned int palier=analogRead(A0);

  float pasSortie=33.5F/5.0F;
  float tensionIn=palier * PASVOLT * pasSortie;
  
  lcd.setCursor(8,1);
  lcd.print("     ");
  lcd.setCursor(8,1);
  lcd.print(tensionIn);
  lcd.print("V");
  delay(800);
}
