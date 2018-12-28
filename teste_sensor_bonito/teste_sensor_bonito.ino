#include <OneWire.h>
#include <DallasTemperature.h>

// Porta do pino de sinal do DS18B20
#define INPUT_SENSOR 3

// Define uma instancia do oneWire para comunicacao com o sensor
OneWire oneWire(INPUT_SENSOR);

DallasTemperature sensors(&oneWire);
DeviceAddress sensor_temperatura;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(sensor_temperatura);

  Serial.print("Temp C: ");
  Serial.println(tempC);

  delay(1000);

}
