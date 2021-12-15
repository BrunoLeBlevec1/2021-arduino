
int pin=3;
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(pin, INPUT);
}
bool ledState = false;

void loop() {
  // put your main code here, to run repeatedly:
    bool buttonState = digitalRead(pin);
    Serial.print("Valeur du port");
    Serial.println(buttonState);
    if(buttonState)
    {
      digitalWrite(12, HIGH);
      
    }
    delay(3000);
    digitalWrite(12, LOW);
}
