void setup() {
  // put your setup code here, to run once:
pinMode(2, INPUT);
pinMode(12, OUTPUT);
attachInterrupt(INT0,turnOnLight, RISING);
}

volatile bool ledState=false;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("DEMAT BREIZH\n");
  digitalWrite(12,ledstate);
}

void turnOnLight(){
  ledState =!ledState}; 
}
