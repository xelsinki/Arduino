/*
 * Author: PANALEX 
 * Sensor: DHT 11 - PIN D5 ( 10kOm betwin pin 5 & 5V+)
 * LCD: SDA: PIN A4, SCL: PIN A5 
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT_NEW.h"
LiquidCrystal_I2C _lcd1(0x27, 16, 2);
int _dispTempLength1 = 0;
boolean _isNeedClearDisp1;

DHT _dht1;

String _gtv1;
String _gtv2;
int _disp1oldLength = 0;
int _disp2oldLength = 0;
unsigned long _dht1LRT = 0UL;
unsigned long _dht1Tti = 0UL;
void setup()
{
  Wire.begin();
  delay(10);
  _lcd1.init();
  _lcd1.backlight();
  _dht1.setup(5);
  _dht1LRT = millis();
  _dht1Tti = millis();
}
void loop()
{ if (_isNeedClearDisp1) {
    _lcd1.clear();
    _isNeedClearDisp1 = 0;
  }

  //Плата:1
  if (_isTimer(_dht1Tti, 1000)) {
    if (_isTimer(_dht1LRT, ( _dht1.getMinimumSamplingPeriod()))) {
      _dht1.readSensor();
      _dht1LRT = millis();
      _dht1Tti = millis();
    }
  }
  _gtv1 = ((String("Temperature:")) + (( _floatToStringWitRaz(_dht1.temperature, 0))) + (String("C")));
  _gtv2 = ((String("Humidity:")) + (( _floatToStringWitRaz(_dht1.humidity, 0))) + (String("%")));
  if (1) {
    _dispTempLength1 = ((((_gtv1) + (String(""))))).length();
    if (_disp2oldLength > _dispTempLength1) {
      _isNeedClearDisp1 = 1;
    }
    _disp2oldLength = _dispTempLength1;
    _lcd1.setCursor(int((16 - _dispTempLength1) / 2), 0);
    _lcd1.print((((_gtv1) + (String("")))));
  } else {
    if (_disp2oldLength > 0) {
      _isNeedClearDisp1 = 1;
      _disp2oldLength = 0;
    }
  }
  if (1) {
    _dispTempLength1 = ((((String("")) + (_gtv2)))).length();
    if (_disp1oldLength > _dispTempLength1) {
      _isNeedClearDisp1 = 1;
    }
    _disp1oldLength = _dispTempLength1;
    _lcd1.setCursor(int((16 - _dispTempLength1) / 2), 1);
    _lcd1.print((((String("")) + (_gtv2))));
  } else {
    if (_disp1oldLength > 0) {
      _isNeedClearDisp1 = 1;
      _disp1oldLength = 0;
    }
  }
}
String  _floatToStringWitRaz(float value, int raz)
{

  return String(value, raz);
}
bool _isTimer(unsigned long startTime, unsigned long period )
{
  unsigned long currentTime;
  currentTime = millis();
  if (currentTime >= startTime) {
    return (currentTime >= (startTime + period));
  } else {
    return (currentTime >= (4294967295 - startTime + period));
  }
}
