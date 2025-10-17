/*
This is just a basic code for the MAX6675 washer type temperature sensor. 

Here is the wiring of the sensor(for the Arduino Uno R4 but easily can be apply to other boards like ESP):
    GND --> GND
    VCC --> 5V
    SCK --> D13
    CS --> D10
    SO --> D12

!!! Red cable of the sensor is positive, blue one is negative. 

And you need the install the MAX6676 library from adafruit. Links of the sensor: 

https://www.aliexpress.com/item/1005003993231326.html?spm=a2g0o.order_list.order_list_main.83.5b021802NwHeWl (Sensor itself)
https://www.aliexpress.com/item/1005009189267778.html?spm=a2g0o.order_list.order_list_main.125.5b021802NwHeWl (Controller)

*/

#include <max6675.h>

// MAX6675 pin mapping
int thermoSO  = 12;  // SO (Serial Out)
int thermoCS  = 10;  // CS (Chip Select)
int thermoSCK = 13;  // SCK (Clock)

// Create sensor object
MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void setup() {
  Serial.begin(9600);
  Serial.println("MAX6675 Test");
  delay(1000);
}

void loop() {
  float celsius = thermocouple.readCelsius();
  float fahrenheit = thermocouple.readFahrenheit();

  if (isnan(celsius && fahrenheit)) {
    Serial.println("Sensor error! Check wiring or probe.");
  } else {
    Serial.print("Temperature: ");
    Serial.print(celsius, 1);
    Serial.print(" °C  |  ");
    Serial.print(fahrenheit, 1);
    Serial.println(" °F");
  }

  delay(1000);
}
