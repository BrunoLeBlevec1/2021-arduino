#include "PCF8574.h"

PCF8574 PCF_01(0x20);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
attachInterrupt(INT0,a,CHANGE);

}
void a(){
  Serial.print("\ninter\n");
}
void loop() {
  // put your main code here, to run repeatedly:

  int x = PCF_01.read8();
  Serial.print("Read ");
  Serial.println(x, BIN);
  delay(900);
}
