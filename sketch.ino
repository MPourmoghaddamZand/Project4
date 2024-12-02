#include <OneWire.h>
#include <DallasTemperature.h>
#include <TM1637Display.h>
#define ONE_WIRE_BUS 2
#define CLK 4
#define DIO 5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
TM1637Display display(CLK, DIO);

void setup(void)
{

Serial.begin(9600);
sensors.begin();
display.setBrightness(0x0f, true);
}

void loop(void)
{

sensors.requestTemperatures(); 
Serial.print("Temperature: ");
Serial.println(sensors.getTempCByIndex(0));
display.showNumberDec(sensors.getTempCByIndex(0), true, 4, 0);
}