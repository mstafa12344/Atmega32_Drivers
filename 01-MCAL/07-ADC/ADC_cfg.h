/******************************************/
/* Description : configur file for ADC    */
/* Author      : mustafa ali              */
/* Date        : Oct 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#ifndef ADC_CFG_H
#define ADC_CFG_H

#define ADC_READ_MODE          ADC_8BIT

#define ADC_CHANNEL_NUM        ADC_CHANNEL_0 

#define ADC_REF_VOLT           ADC_AVCC

#define ADC_PRESCALLER         ADC_DIV_2

#define ADC_AUTO_TRIGGER_MODE  ADC_DISABLE

#if ADC_AUTO_TRIGGER_MODE==ADC_ENABLE

#define ADC_AUTO_TRIGGER_SRC    FREE_RUNNING

#endif





#endif
