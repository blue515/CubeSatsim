#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

//                      RX    TX
HardwareSerial Serial2(PA3, PA2);

void setup() {
  Serial2.begin(115200);

  if (!bme.begin(0x76)) {
    Serial2.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  Serial2.print("Temperature = ");
  Serial2.print(bme.readTemperature());
  Serial2.println("*C");

  Serial2.print("Pressure = ");
  Serial2.print(bme.readPressure() / 100.0F);
  Serial2.println("hPa");

  Serial2.print("Approx. Altitude = ");
  Serial2.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial2.println("m");

  Serial2.print("Humidity = ");
  Serial2.print(bme.readHumidity());
  Serial2.println("%");

  Serial2.println();
  delay(1000);
}
