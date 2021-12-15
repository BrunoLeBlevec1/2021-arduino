#define PASVOLT (float)(5.0F / 1024.0F)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int palier=analogRead(A0);
  Serial.print("Valeur :\t");
  Serial.print(palier);
  Serial.print("Tension :\t");
  Serial.print(palier * PASVOLT);
  Serial.print("\n");
}
