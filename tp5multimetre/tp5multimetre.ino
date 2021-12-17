#define PASVOLT (float)(5.0F / 1024.0F)
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup() 
{
  // put your setup code here, to run once:
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
    lcd.print("Voltmetre Multimetre");
    attachInterrupt(INT0,changeType,RISING);
}
volatile bool isVoltOrOhm=false;

void loop() 
{
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);
  if(isVoltOrOhm){showVoltage();}
  else
  {
    showRes();
  }
  delay(1000);
}

void changeType()
{isVoltOrOhm=!isVoltOrOhm;}

void showVoltage(){ // put your main code here, to run repeatedly:
  unsigned int palier=analogRead(A0);

  float pasSortie=1;//33.5F / 5.0F;
  float tensionIn=palier * PASVOLT * pasSortie;
  Serial.print(palier * PASVOLT * pasSortie);
  Serial.print("V\n");

  lcd.setCursor(8,1);
  lcd.print("        ");
  lcd.setCursor(5,1);
  lcd.print(tensionIn);
  lcd.print("V");
}

#define R1 942.0F
void showRes()
{
  unsigned int palier=analogRead(A1);
  float tensionEnA1=palier * PASVOLT;
  float r2=R1 * (5.0F/tensionEnA1)-R1;
  lcd.setCursor(8, 1);
  lcd.print("      ");

  lcd.setCursor(5, 1);
  lcd.print(r2);
  lcd.print("ohm");
}
