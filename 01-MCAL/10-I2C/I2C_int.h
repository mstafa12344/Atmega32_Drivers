/******************************************************/
/********* Name     : Mustafa Ali *********************/
/********* comonent : TWI         *********************/
/********* Date     : 16/12/2022  *********************/
/******************************************************/

#ifndef I2C_INT_H
#define I2C_INT_H

/******** initialize the Master *************/
void  TWI_voidMasterInit(uint8 u8SlaveAdress);
/********************************************/

/********* initialize the Slave**********/
void TWI_voidSlaveInit(uint8 u8SlaveAdress);
/****************************************/

/********* Start Condition **************/
TWI_ERRStatus TWI_StartCondition (void);
/****************************************/

/******* REPeat Start Condition ******************************/
TWI_ERRStatus TWI_RepeatStartCondition (void );
/*************************************************************/

/*********** Send Stop Condition*************/
void TWI_StopCondition(void);
/*******************************************/

/************ Send Slave Address with write *****************/
TWI_ERRStatus TWI_SendSlaveAddressWrite(uint8 u8SlaveAdress);
/************************************************************/

/************* Send Slave Address with read  ****************/
TWI_ERRStatus TWI_SendSlaveAddressRead (uint8 u8SlaveAdress);
/************************************************************/

/**************Master Send Data *****************************/
TWI_ERRStatus TWI_Master_SendDataByte  (uint8 u8Data);
/************************************************************/

/**************Master Recieve Data **************************/
TWI_ERRStatus TWI_Master_ReadDataByte  (uint8 *u8Data);
/************************************************************/

#endif