/****************************************/
/* Description : progran file for timer1*/
/* Author      : mustafa ali            */
/* Date        : sep 2022               */
/* Version     : 0.1V                   */ 
/****************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM1_int.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"

pf TIM1_pfCtcACallback;
pf TIM1_pfCtcBCallback;
pf TIM1_pfOvfCallback;
pf TIM1_pfICUCallBack;

void TIM1_void_Init(void)
{
  /* first should select mode*/

	#if TIM1_MODE ==  NORMAL_MODE
		CLR_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE == PWM_PHASE_CORRECT_8BIT_MODE
		CLR_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

	#elif TIM1_MODE == PWM_PHASE_CORRECT_9BIT_MODE
		CLR_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  PWM_PHASE_CORRECT_10BIT_MODE
		CLR_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

	#elif TIM1_MODE == CTC_TOP_OCRA1_MODE
		CLR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE == FAST_PWM_8BIT_MODE
		CLR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

	#elif TIM1_MODE == FAST_PWM_9BIT_MODE
		CLR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  FAST_PWM_10BIT_MODE
		CLR_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

	#elif TIM1_MODE == PWM_PHASE_AND_FREQ_CORREC_TOP_ICR1_MODE
		SET_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  PWM_PHASE_AND_FREQ_CORREC_TOP_OCRA1_MODE
		SET_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  PWM_PHASE_CORRECT_TOP_ICR1_MODE
		SET_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  PWM_PHASE_CORRECT_TOP_OCRA1_MODE
		SET_BIT(TCCR1B,4);
		CLR_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  CTC_TOP_ICR1_MODE
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		CLR_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  FAST_PWM_TOP_ICR1_MODE
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		CLR_BIT(TCCR1A,0);

	#elif TIM1_MODE ==  FAST_PWM_TOP_OCRA1_MODE
		SET_BIT(TCCR1B,4);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,0);
    #endif

	switch(TIM1_MODE_CHANNEL1A)
	{
		case MODE_CHANNEL_A_NORMAL:
		CLR_BIT(TCCR1A,7);
		CLR_BIT(TCCR1A,6);
		break;
		case MODE_CHANNEL_A_TOGGLE:
		CLR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
		break;
		case MODE_CHANNEL_A_CLEAR_OC1A:
		CLR_BIT(TCCR1A,6);
		SET_BIT(TCCR1A,7);
		break;
		case MODE_CHANNEL_A_SET_OC1A:
		SET_BIT(TCCR1A,6);
		SET_BIT(TCCR1A,7);
		break;
	}
	switch(TIM1_MODE_CHANNEL1B)
	{
		case MODE_CHANNEL_B_NORMAL:
		CLR_BIT(TCCR1A,5);
		CLR_BIT(TCCR1A,4);
		break;
		case MODE_CHANNEL_B_TOGGLE:
		CLR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
		break;
		case MODE_CHANNEL_B_CLEAR_OC1B:
		CLR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
		break;
		case MODE_CHANNEL_B_SET_OC1B:
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
		break;
	}
		/* select prescaler*/
		TCCR1B &= (0xF8);					  /* clear reg 0b1111 1000 */
		TCCR1B |= ((0x07) & TIM1_PRESCALLER); /* write in reg to set prescaler*/
        /* initialize registers*/

		TCNT1 = 0;
		OCR1A = 0;
		OCR1B = 0;
		ICR1  = 0;
		/* disable all interrupts*/

		CLR_BIT(TIMSK,5); // disable input capture interrupt
		CLR_BIT(TIMSK,4); //disable out compare match interrupt 1
		CLR_BIT(TIMSK,3); //disable out compare match interrupt 2
		CLR_BIT(TIMSK,2); //disable overflow interrupt
}

void TIM1_voidSetTimeValue(uint16 u16TimerValueCpy)
{
	TCNT1 = u16TimerValueCpy;
}
void TIM1_voidSetComMatchValueA(uint16 u16TimerCompValueACpy)
{
	OCR1A =u16TimerCompValueACpy;
}
void TIM1_voidSetComMatchValueB(uint16 u16TimerCompValueBCpy)
{
	OCR1B =u16TimerCompValueBCpy;
}
void TIM1_voidSeICR1Value(uint16 u16TimerICRValueBCpy)
{
	ICR1 =(uint16)u16TimerICRValueBCpy;
}
uint16 TIM1_u16GetCntrValue(void)
{
	return (uint16)TCNT1;
}
void TIM1_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK,2);
}
void TIM1_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK,2);
}
void TIM1_voidEnableCTCAInterrupt(void)
{
	SET_BIT(TIMSK,4);
}
void TIM1_voidDisableCTCAInterrupt(void)
{
	CLR_BIT(TIMSK,4);
}
void TIM1_voidEnableCTCBInterrupt(void)
{
	SET_BIT(TIMSK,3);
}
void TIM1_voidDisableCTCBInterrupt(void)
{
	CLR_BIT(TIMSK,3);
}
void TIM1_voidEnableICUIntterrupt(void)
{
	SET_BIT(TIMSK,5);
}
void TIM1_voidDisableICUIntterrupt(void)
{
	CLR_BIT(TIMSK,5);
}
void TIM1_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM1_pfOvfCallback = pfOvfCallbackCpy;
}
void TIM1_voidSetCtcACallback(pf pfCtcCallbackCpy)
{
	TIM1_pfCtcACallback =pfCtcCallbackCpy;
}
void TIM1_voidSetCtcBCallback(pf pfCtcCallbackCpy)
{
	TIM1_pfCtcBCallback = pfCtcCallbackCpy;
}
void TIM1_voidSetICUCallback(pf pfCtcCallbackCpy)
{
	TIM1_pfICUCallBack =pfCtcCallbackCpy;
}
void __vector__9(void) __attribute__((signal,used)); // ovf ISR
void __vector__9(void)
{
	TIM1_pfOvfCallback();
}
void __vector__8(void) __attribute__((signal,used)); // CTCB ISR
void __vector__8(void)
{
	TIM1_pfCtcBCallback();
}
void __vector__7(void) __attribute__((signal,used)); //CTCA ISR
void __vector__7(void)
{
	TIM1_pfCtcBCallback();
}
void __vector__6(void) __attribute__((signal,used)); //ICU ISR
void __vector__6(void)
{
	TIM1_pfICUCallBack();
}

void Timer1Icu_voidInit(void)
{
	/* Set trigger source*/
	SET_BIT( TCCR1B,6);
	TIM1_voidEnableICUIntterrupt();
	
}
void Timer1ICU_voidSetTriggerEdge(uint8 u8ICUEdgeCpy)
{
	if(u8ICUEdgeCpy == TIMER1_ICU_RISING_EDGE)
	{
		SET_BIT( TCCR1B,6);
	}
	else if(u8ICUEdgeCpy == TIMER1_ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,6);
	}
}
uint16 Timer1IcuGetValu(void)
{
	return ICR1;
}
