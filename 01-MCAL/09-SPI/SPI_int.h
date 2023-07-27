

#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPIMaster_voidInit(void);
void SPISlave_voidInit(void);

tenuErrorStatus SPI_u8Transceiver(uint8 u8DataCpy,uint8 * RecievData);

#endif /* SPI_INT_H_ */
