/******************************************/
/* Description : privet file for WDT      */
/* Author      : mustafa ali              */
/* Date        : sep 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#ifndef WDT_PRIV_H
#define WDT_PRIV_H

#define  WDTCR *((volatile uint8*)0X41)

#define WDT_16K   0b00001000
#define WDT_32K   0b00001001
#define WDT_64K   0b00001010
#define WDT_128K  0b00001011
#define WDT_256K  0b00001100
#define WDT_512K  0b00001101
#define WDT_1024K 0b00001110
#define WDT_2048K 0b00001111


#endif