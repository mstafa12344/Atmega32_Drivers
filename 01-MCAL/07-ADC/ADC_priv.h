/******************************************/
/* Description : privet file for ADC      */
/* Author      : mustafa ali              */
/* Date        : Oct 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#ifndef  ADC_PRIV_H
#define  ADC_PRIV_H

#define ADC_8BIT       0
#define ADC_10BIT      1


#define ADC_AREF   0
#define ADC_AVCC   1
#define ADC_2_56V  2

#define ADC_DIV_2           1
#define ADC_DIV_4           2
#define ADC_DIV_8           3
#define ADC_DIV_16          4
#define ADC_DIV_32          5
#define ADC_DIV_64          6
#define ADC_DIV_128         7

#define ADC_ENABLE           0
#define ADC_DISABLE          1

#define FREE_RUNNING         0
#define ANALOG_COMP          32
#define EXTINT0_SRC          64
#define TIM0_CMP             96
#define TIM0_OVF             128
#define TIM1_CMP             160
#define TIM1_OVF             0b11000000
#define TIM1_ICU             0xE0


#define ADMUX  *((volatile uint8 *) 0x27 )
#define ADCSRA  *((volatile uint8 *) 0x26 )
#define SFIOR   *((volatile uint8 *) 0x50 )
#define ADCH    *((volatile uint8 *) 0x25 )
#define ADCL    *((volatile uint8 *) 0x24 )


#endif
