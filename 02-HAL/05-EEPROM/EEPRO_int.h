#ifndef EEPRO_INT_H
#define EEPRO_INT_H
void EEPRO_voidInit(void);
void EEPROM_voidWritByte(uint16 U16ByteAddressCpy,uint8 u8DataCpy);
void EEPROM_voidReadByte(uint16 U16ByteAddressCpy,uint8 *u8ReturnDataCpy);

#endif