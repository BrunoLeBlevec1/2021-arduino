
#include <Adafruit_BMP085.h>
#include <LCD_I2C.h>

Adafruit_BMP085 bmp;

LCD_I2C lcd(0x27, 16, 2);

  
void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(115200);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
}
  
void loop() {
  lcd.setCursor(0,1);
  showPression();
  showTemperature();
  showAltitude();
 
  /*delay(500);
    

    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal


    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();*/
    delay(500);
}

void showPression(){ // put your main code here, to run repeatedly:

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(5,0);
  lcd.print(bmp.readPressure()/100000.0F);
  lcd.print("Bar");
    /*Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

  float pasSortie=1;//33.5F / 5.0F;
  float tensionIn=palier * PASVOLT * pasSortie;
  Serial.print(palier * PASVOLT * pasSortie);
  Serial.print("V\n");*/


}

void showTemperature(){ // put your main code here, to run repeatedly:

  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(1,1);
  lcd.print(bmp.readTemperature());
  lcd.print("*C");
  /*Serial.print("Temp = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");
  /*float pasSortie=1;//33.5F / 5.0F;
  float tensionIn=palier * PASVOLT * pasSortie;
  Serial.print(palier * PASVOLT * pasSortie);
  Serial.print("V\n");*/



}


void showAltitude(){ // put your main code here, to run repeatedly:


  lcd.setCursor(8,1);
  lcd.print(bmp.readAltitude());
  lcd.print("m");
 /*   Serial.print("Alt = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");
  /*float pasSortie=1;//33.5F / 5.0F;
  float tensionIn=palier * PASVOLT * pasSortie;
  Serial.print(palier * PASVOLT * pasSortie);
  Serial.print("V\n");*/

}
