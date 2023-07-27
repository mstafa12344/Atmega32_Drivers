#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/delay.h"
#include "DIO_int.h"



void LED_voidLedOn(uint8 U8PinNumCpy)
{
	DIO_enuWritePin(8PinNumCpy,1);
}
void LED_voidLedOFF(uint8 U8PinNumCpy)
{
	DIO_enuWritePin(8PinNumCpy,0);
}

void LED_voidLedToggle(uint8 U8PinNumCpy,uint8 u8DelayTimeCpy)
{
	DIO_enuWritePin(8PinNumCpy,1);
	_delay_ms(u8DelayTimeCpy);
	DIO_enuWritePin(8PinNumCpy,0);
	_delay_ms(u8DelayTimeCpy);
}