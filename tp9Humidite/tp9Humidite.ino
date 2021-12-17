// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>

#include <Adafruit_BMP085.h>
#include <LCD_I2C.h>

#define DHTPIN 4     // Digital pin connected to the DHT sensor 

#define DHTTYPE    DHT11     // DHT 11

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


DHT_Unified dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;
Adafruit_MPU6050 mpu;
//LCD_I2C lcd(0x27, 16, 2);


uint32_t delayMS;

float initialePressure = 0;

void setup() {
  Serial.begin(9600);
  
  sensors.begin();
  
  // Initialize device.
  dht.begin();
  mpu.begin();
  if (bmp.begin()) {
    initialePressure = bmp.readPressure();
  }
}

void loop() {
  delay(1500);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  dht.humidity().getEvent(&event);

  float press = bmp.readPressure();
  float bmpTemp = bmp.readTemperature();
  float alt = bmp.readAltitude(initialePressure);

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  

  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  } 
  else
  {
    Serial.println("Error: Could not read temperature data");
  }


  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.

  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }

/* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("mpuTemperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");

 Serial.print("bmpTemperature: ");
  Serial.print(bmpTemp);
  Serial.println(" degC");
  
  Serial.print("alt : ");
  Serial.print(alt);
  Serial.println(" m");

   Serial.print("press: ");
  Serial.print(press/100000.0F);
  Serial.println(" bar\n\n\n");
}
