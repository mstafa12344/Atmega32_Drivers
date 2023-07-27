#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPDR    *((volatile uint8 *) 0x2F)
#define SPCR    *((volatile uint8 *) 0x2D)
#define SPSR    *((volatile uint8 *) 0x2E)

#endif /* SPI_PRIV_H_ */
