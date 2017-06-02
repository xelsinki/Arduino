#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>

#include <MFRC522.h>

LiquidCrystal_I2C _lcd1(0x27, 16, 2);
int _dispTempLength1=0;
boolean _isNeedClearDisp1;

unsigned long CardID_199700399_1;
bool Card_199700399_1;
#define SS_PIN_199700399_1 10

#define RST_PIN_199700399_1 9

byte N_199700399_1;
unsigned long uidDec_199700399_1;
unsigned long uidDecTemp_199700399_1;
MFRC522 mfrc522_199700399_1(SS_PIN_199700399_1, RST_PIN_199700399_1);	 // Create MFRC522 instance.
unsigned long _gtv1;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
unsigned long _stou1;
bool _tim1I = 0;
bool _tim1O = 0;
unsigned long _tim1P = 0UL;
bool _bounseInputD3S = 0;
bool _bounseInputD3O = 0;
unsigned long _bounseInputD3P = 0UL;
bool _bounse1S = 0;
bool _bounse1O = 0;
unsigned long _bounse1P = 0UL;
bool _bounse2S = 0;
bool _bounse2O = 0;
unsigned long _bounse2P = 0UL;
int _disp1oldLength = 0;
bool _trgrt1 = 0;
bool _trgrt1I = 0;
void setup()
{
Wire.begin();
delay(10);
Serial.begin(9600);
pinMode(3, INPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(2, OUTPUT);
pinMode(8, OUTPUT);

_lcd1.init();
_lcd1.backlight();
_bounseInputD3O =  digitalRead(3);
SPI.begin();			// Init SPI bus
mfrc522_199700399_1.PCD_Init();	// Init MFRC522 card
}
void loop()
{if (_isNeedClearDisp1) {_lcd1.clear(); _isNeedClearDisp1= 0;}

bool  _bounceInputTmpD3 =  (digitalRead (3));

if (_bounseInputD3S) 
    {
     if (millis() >= (_bounseInputD3P + 40)) 
         {_bounseInputD3O= _bounceInputTmpD3; _bounseInputD3S=0;}
     }
else
    {
     if (_bounceInputTmpD3 != _bounseInputD3O )
         {_bounseInputD3S=1; _bounseInputD3P = millis();} 
      } 




//Плата:1
	
	// MFRC522_2card
	if ( mfrc522_199700399_1.PICC_IsNewCardPresent() ) // если есть новая карта, то читаем ее
	{
		if ( mfrc522_199700399_1.PICC_ReadCardSerial() ) // если читается, то
		{
			uidDec_199700399_1 = 0;
			for (N_199700399_1 = 0; N_199700399_1 < mfrc522_199700399_1.uid.size; N_199700399_1++) // собираем серийный номер карточки
			{
				uidDecTemp_199700399_1=mfrc522_199700399_1.uid.uidByte[N_199700399_1];
				uidDec_199700399_1=uidDec_199700399_1*256+uidDecTemp_199700399_1;
			} 
			CardID_199700399_1 = uidDec_199700399_1;
			Card_199700399_1 = true;
		}
	}
	else // если карта пропала, то гасим выходы
	{
		CardID_199700399_1 = 0;
		Card_199700399_1 = false;
	}
if (( ((_gtv1) > (0UL)) || (( ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) )) ))
{ if (_tim1I) { if (_isTimer(_tim1P, 1000)) {_tim1O = 1;}} else {_tim1I =1; _tim1P = millis();}} else {_tim1O = 0; _tim1I = 0;}
bool   _bounceTmpD1 = ( ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) || ((_gtv1) == (3575185260UL)) );

if (_bounse1S) 
    {
     if (millis() >= (_bounse1P + 40)) 
         {_bounse1O=  _bounceTmpD1; _bounse1S=0;}
     }
else
    {
     if ( _bounceTmpD1 != _bounse1O )
         {_bounse1S=1; _bounse1P = millis();} 
      } 
if (_bounse1O) { if (_trgrt1I) { _trgrt1 = 0;} else {_trgrt1 = 1; _trgrt1I = 1;} } else {_trgrt1 = 0; _trgrt1I = 0;}; 
 bool   _bounceTmpD2 = (_gtv1) > (0UL);

if (_bounse2S) 
    {
     if (millis() >= (_bounse2P + 40)) 
         {_bounse2O=  _bounceTmpD2; _bounse2S=0;}
     }
else
    {
     if ( _bounceTmpD2 != _bounse2O )
         {_bounse2S=1; _bounse2P = millis();} 
      } 
if (_bounseInputD3O) {if (! _gen1I) { _gen1I = 1; _gen1O = 1; _gen1P =  millis(); } } else { _gen1I = 0 ;  _gen1O= 0;  } if (_gen1I ) { if (_gen1O) { if ( _isTimer( _gen1P , 200 )) { _gen1P = millis(); _gen1O = 0; } } else  { if ( _isTimer( _gen1P , 100 )) {  _gen1P = millis(); _gen1O = 1;  } } }
if (( (Card_199700399_1) || (_tim1O) )) {
_gtv1 = CardID_199700399_1;
}
if (1) {
_dispTempLength1 = ((((String("Kortti:")) + ((String(_gtv1, DEC)))))).length();
if (_disp1oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp1oldLength = _dispTempLength1;
_lcd1.setCursor(0, 0);
_lcd1.print((((String("Kortti:")) + ((String(_gtv1, DEC))))));
} else {
if (_disp1oldLength > 0) {_isNeedClearDisp1 = 1; _disp1oldLength = 0;} 
}
digitalWrite(7, _bounse1O);
digitalWrite(6, ( (_trgrt1) || (( (!(_bounse1O)) && (_bounse2O) )) ));
digitalWrite(5, ( (!(_bounse1O)) && (_bounse2O) ));
digitalWrite(8, _gen1O);
if (1){if(!(( _gtv1)==(_stou1))){Serial.println(_gtv1);}} _stou1 = _gtv1; 
digitalWrite(2, _gen1O);


}
bool _isTimer(unsigned long startTime, unsigned long period )
  {
  unsigned long currentTime;
currentTime = millis();
if (currentTime>= startTime) {return (currentTime>=(startTime + period));} else {return (currentTime >=(4294967295-startTime+period));}
  }
