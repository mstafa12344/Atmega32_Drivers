/******************************************************/
/********* Name     : Mustafa Ali *********************/
/********* comonent : TWI         *********************/
/********* Date     : 16/12/2022  *********************/
/******************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "I2C_int.h"
#include "I2C_priv.h"
#include "I2C_cfg.h"



void  TWI_voidMasterInit(uint8 u8SlaveAdress)
{
	/*Set Clock*/           /* scl = F_CPU /(16+((2*TWBR)*4^TWPS)*/
	TWBR =2;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	
	if(u8SlaveAdress != 0)
	{
		TWAR = u8SlaveAdress<<1;
	}
	/*Enable TWI*/ 
	SET_BIT(TWCR,TWCR_TWEN);
}




void  TWI_voidSlaveInit(uint8 u8SlaveAdress)
{
	/*initialize address*/
	TWAR = u8SlaveAdress<<1;
		/*Enable TWI*/ 
	SET_BIT(TWCR,TWCR_TWEN);
}



TWI_ERRStatus TWI_StartCondition(void)
{
	TWI_ERRStatus local_ERRStatus = NOERROR;
	/* send start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/* Clear Flag*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the flag raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/* check status*/
	if((TWSR & 0b11111000 != START_ACK)
	{
		local_ERRStatus = START_CONDITION_ERROR;
	}
	else
	{
		
	}
	return local_ERRStatus;
}



TWI_ERRStatus TWI_RepeatStartCondition (void)
{
	TWI_ERRStatus local_ERRStatus = NOERROR;
		/* send start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/* Clear Flag*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the flag raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/* check status*/
	if((TWSR & 0b11111000 != REP_START_ACK)
	{
		local_ERRStatus = REPEAT_START_CONDITION_ERROR;
	}
	else
	{
		
	}
	return local_ERRStatus;
}


TWI_ERRStatus TWI_SendSlaveAddressWrite(uint8 u8SlaveAdress)
{
	TWI_ERRStatus local_ERRStatus = NOERROR;
	/* clear start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	/* set slave address*/
	TWDR = u8SlaveAdress<<1;
	CLR_BIT(TWDR,0);
	/* Clear Flag*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the flag raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/* check status*/
	if((TWSR & 0b11111000 != SLAVE_ADD_AND_WR_ACK)
	{
		local_ERRStatus = SEND_ADD_AND_Write_Error;
	}
	else
	{
		
	}
	return local_ERRStatus;
}


TWI_ERRStatus TWI_SendSlaveAddressRead (uint8 u8SlaveAdress)
{
	TWI_ERRStatus local_ERRStatus = NOERROR;
	/* clear start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	/* set slave address*/
	TWDR = u8SlaveAdress<<1;
	SET_BIT(TWDR,0);
	/* Clear Flag*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the flag raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/* check status*/
	if((TWSR & 0b11111000 != SLAVE_ADD_AND_RD_ACK)
	{
		local_ERRStatus = SEND_ADD_AND_Read_Error;
	}
	else
	{
		
	}
	return local_ERRStatus;
}


TWI_ERRStatus TWI_Master_SendDataByte (uint8 u8Data)
{
	TWI_ERRStatus local_ERRStatus = NOERROR;
	
	TWDR = u8Data;
	/* Clear Flag*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the flag raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/* check status*/
	if((TWSR & 0b11111000 != MASTER_WR_BYTE_ACK)
	{
		local_ERRStatus = MASTER_WRITE_BYTE_ERROR;
	}
	else
	{
		
	}
	return local_ERRStatus;
}



TWI_ERRStatus TWI_Master_ReadDataByte (uint8 *u8Data)
{
	TWI_ERRStatus local_ERRStatus = NOERROR;
	SET_BIT(TWCR,TWCR_TWEA );
	/* Clear Flag*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* wait until the flag raised*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	
	/* check status*/
	if((TWSR & 0b11111000) != MASTER_RD_BYTE_WITH_ACK)
	{
		local_ERRStatus = MASTER_READ_BYTE_ERROR;
	}
	else
	{
		*u8Data = TWDR;
	}
	return local_ERRStatus;
}

void TWI_StopCondition(void)
{
	CLR_BIT(TWCR,TWCR_TWSTO);
	SET_BIT(TWCR,TWCR_TWINT);
}