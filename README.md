# Arduino: 
Prototyypin rakentaminen: 


Thermometer and humidity meter

PINS:
DHT 11 sensor:
Data-pin to D5 throw 10kOm transistor
GND –> GND,
VCC–> V5+

LCD-nscreen(16x2):
SDA-pin to A4
SCL-pin to A5
GND –> GND,
VCC–> V5+

ALARM System:

SPI: (RFID-korttilukija)
9 – RST
10 – SDA(SS)
11 –   MOSI
12 – MISO
13 – SCK
GND
+3.3V

I2C: (LCD-näyttö)
A4 – SDA
A5 – SCL
+5V & GND
3-väri LED (Korttilukijalle)
4 – Red
7 – Green
5- Blue
GND (220Om kautta)

HC-SR501 (PIR-liiketunnustin)
+5V
GND
3 PIN – Digital IN

Buzzer & LCD (Hälytys)
GND
6 PIN – Buzzer Digital OUT
2 PIN – LCD (220Om kautta)
