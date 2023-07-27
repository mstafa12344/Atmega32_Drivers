/******************************************/
/* Description : privet file for timer0   */
/* Author      : mustafa ali              */
/* Date        : sep 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#ifndef TIM1_PRIV_H
#define TIM1_PRIV_H

#define TCCR1A	*((volatile uint8*)0x4F)
#define TCCR1B	*((volatile uint8*)0x4E)

#define TCNT1 *((volatile uint16*)0x4C)
#define TCNT1H *((volatile uint8*)0x4D)

#define OCR1A	*((volatile uint16*)0x4A)
#define OCR1AH	*((volatile uint8*)0x4B)

#define OCR1B	*((volatile uint16*)0x48)
#define OCR1BH	*((volatile uint8*)0x49)

#define ICR1	*((volatile uint16*)0x46)
#define ICR1H	*((volatile uint8*)0x47)

#define TIMSK   *((volatile uint8*)0x59)






#endif
