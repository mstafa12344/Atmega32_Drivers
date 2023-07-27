/******************************************/
/* Description : interface file for ADC   */
/* Author      : mustafa ali              */
/* Date        : Oct 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#ifndef ADC_INT_H
#define ADC_INT_H


#define ADC_CHANNEL_0         0
#define ADC_CHANNEL_1         1
#define ADC_CHANNEL_2         2
#define ADC_CHANNEL_3         3
#define ADC_CHANNEL_4         4
#define ADC_CHANNEL_5         5
#define ADC_CHANNEL_6         6
#define ADC_CHANNEL_7         7
#define ADC_CH0_CH0_GAIN_10X  8
#define ADC_CH1_CH0_GAIN_10X  9

void ADC_voidInit(void);
uint16 ADC_u16ReadSync (void);
uint16 ADC_u16ReadAsync(void);






#endif
