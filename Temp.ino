#include <Arduino.h>
#include <TM1637Display.h>

#include <LiquidCrystal_I2C.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#define CLK 2
#define DIO 3

#define source1 3
#define source2 2

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

TM1637Display display(CLK,DIO);

OneWire oneWire1(source1);
OneWire oneWire2(source2);

DallasTemperature sensor1(&oneWire1);
DallasTemperature sensor2(&oneWire2);

 float temp1=0;
 float temp2=0;
 int celcius = 0;
void setup(void)
{
  
  Serial.begin(9600);
  
  sensor1.begin();
  sensor2.begin();

  lcd.begin(16,2);
}


void loop(void)
{ 
  sensor1.requestTemperatures(); 
  temp1=sensor1.getTempCByIndex(0);
  sensor2.requestTemperatures(); 
  temp2=sensor2.getTempCByIndex(0);
  celcius = (temp1+temp2)/2;
  
  Serial.print(temp1);
  Serial.print(" C  ");
  Serial.print('\n');

  lcd.home();
 // lcd.print(temp1);

  Serial.print(temp2);
  Serial.print(" C  ");
  Serial.print('\n');

  lcd.setCursor(0,0);
  lcd.print("Temp(C) = ");
  lcd.print(temp2);
  
  delay(1000);
}
