
#include "STD_Types.h"
#include "BIT_Math.h"
#define  F_CPU    8000000UL
#include <util/delay.h>
#include "I2C_int.h"
#include "EEPRO_int.h"
#include "EEPRO_cfg.h"
#include "EEPRO_priv.h"
void EEPRO_voidInit(void)
{
	TWI_voidMasterInit();
}

void EEPROM_voidWritByte(uint16 U16ByteAddressCpy,uint8 u8DataCpy)
{
	/*start Condition*/
	TWI_ERRStatus TWI_StartCondition();
	/* send slave address*/
	TWI_SendSlaveAddressWrite(0b01010 | (EEPROM_A2_ADDRESS<<2) |(U16ByteAddressCpy>>8));
	/* Send Address Byte*/
	TWI_Master_SendDataByte((uint8)U16ByteAddressCpy);
	/* Send Data*/
	TWI_Master_SendDataByte(u8DataCpy);
	/*Send Stop Condition*/
	TWI_StopCondition();
	_delay_ms(5);
}
void EEPROM_voidReadByte(uint16 U16ByteAddressCpy,uint8 *u8ReturnDataCpy)
{
		/*start Condition*/
		TWI_ERRStatus TWI_StartCondition();
		/* send slave address*/
		TWI_SendSlaveAddressWrite(0b01010 | (EEPROM_A2_ADDRESS<<2) |(U16ByteAddressCpy>>8));
		/* Send Address Byte*/
		TWI_Master_SendDataByte((uint8)U16ByteAddressCpy);
		/* Repeat Start */
		 TWI_RepeatStartCondition();
		 /* send slave address*/
		 TWI_SendSlaveAddressRead(0b01010 | (EEPROM_A2_ADDRESS<<2) |(U16ByteAddressCpy>>8));
		/* Read Data*/
		 TWI_Master_ReadDataByte(u8ReturnDataCpy);
		/*Send Stop Condition*/
		TWI_StopCondition();
		_delay_ms(5);
	
}