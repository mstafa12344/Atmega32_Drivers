/******************************************/
/* Description : program file for ADC     */
/* Author      : mustafa ali              */
/* Date        : Oct 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#include "STD_Types.h"
#include "BIT_Math.h"


#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"


uint16 ADC_u16ReadValue ;

void ADC_voidInit(void)
{
	
	ADMUX &= 0b11100000;
	ADMUX |= ADC_CHANNEL_NUM ;
	SET_BIT(ADCSRA , 7);
	#if ADC_READ_MODE == ADC_10BIT
	CLR_BIT(ADMUX , 5);
	#else
	SET_BIT(ADMUX , 5);
    #endif
	
	#if   ADC_REF_VOLT ==ADC_AREF 
	CLR_BIT(ADMUX ,6);
	CLR_BIT(ADMUX ,7);
    #elif ADC_REF_VOLT == ADC_AVCC 
	SET_BIT(ADMUX ,6);
	CLR_BIT(ADMUX ,7);
	#else 
	SET_BIT(ADMUX ,6);
	SET_BIT(ADMUX ,7);		
	#endif

	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_PRESCALLER ;
	
	#if ADC_AUTO_TRIGGER_MODE == ADC_ENABLE 
	  SET_BIT(ADCSRA , 5);
	  SFIOR &= 0b00011111;
	  SFIOR |= ADC_AUTO_TRIGGER_SRC ;
	#else
	  CLR_BIT(ADCSRA , 5);
	#endif
	
	
}

uint16 ADC_u16ReadSync (void)
{
	
	uint16 u16ReadValueLoc = 0 ;
	SET_BIT(ADCSRA , 6);
	while (GET_BIT(ADCSRA , 4) == 0);
	SET_BIT(ADCSRA , 4) ; // clear flag
	#if ADC_READ_MODE == ADC_8BIT   // left adjustment
	u16ReadValueLoc = ADCH ;
	#else // Right adjustment
	u16ReadValueLoc = ADCH <<8|ADCL ;
	#endif
	
	return u16ReadValueLoc ;
}

uint16 ADC_u16ReadAsync(void)
{
	SET_BIT(ADCSRA , 3);
	SET_BIT(ADCSRA , 6);
	return ADC_u16ReadValue ;
}


void __vector_16 (void) __attribute__((signal,used));
void __vector_16 (void)
{
	#if ADC_READ_MODE == ADC_8BIT   // left adjustment
	ADC_u16ReadValue = ADCH ;
	#else // Right adjustment
	ADC_u16ReadValue = ADCH <<8|ADCL ;
	#endif
}





