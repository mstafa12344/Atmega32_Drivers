/****************************************/
/* Description : progran file for timer0*/
/* Author      : mustafa ali            */
/* Date        : sep 2022               */
/* Version     : 0.1V                   */ 
/****************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM0_int.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"

pf TIM0_pfOvfFun ;
pf TIM0_pfCmpFun ;
void  TIM0_voidInit(void)
{
	TCCR0 &= 0b11111000;
	TCCR0 |= TIM0_PPRESCALLER ;
	TIM0_voidChangeMode(TIM0_MODE);
	TIM0_voidChangeWfMode(TIM0_WF_MODE);
	
}
void  TIM0_voidChangeMode(uint8 u8ModeValueCpy)
{
	switch(u8ModeValueCpy)
	{
		case TIM0_MODE_NORMAL    : 
		CLR_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);
		break ;
		case TIM0_MODE_CTC       :
		CLR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		break ;
		case TIM0_MODE_FAST_PWM  :
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		break ;
		case TIM0_MODE_PHASE_PWM :
		SET_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);
		break ;
		default :
		CLR_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);
	}
}
void  TIM0_voidChangeWfMode(uint8 u8WfModeValueCpy)
{
	switch(u8WfModeValueCpy)
	{
		case TIM0_WF_TOGGLE_PIN      : 
		SET_BIT(TCCR0 ,4);
		CLR_BIT(TCCR0 ,5);
		break ; 
		case TIM0_WF_CLR_PIN         :  
		SET_BIT(TCCR0 ,5);
		CLR_BIT(TCCR0 ,4);
		break ;
		case TIM0_WF_SET_PIN         : 
		SET_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_SET_CMP_CLR_TOP :
		SET_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_CLR_CMP_SET_TOP : 
		CLR_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_SET_UPC_CLR_DNC :
		SET_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_SET_DNC_CLR_UPC : 
		CLR_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_OFF             : 
        CLR_BIT(TCCR0 ,4);
		CLR_BIT(TCCR0 ,5);
		break ;
		default :
		/* No waveform generated*/
		CLR_BIT(TCCR0 ,4);
		CLR_BIT(TCCR0 ,5);
	
		
	}
}
void  TIM0_voidSetTimeValue(uint8 u8TimerValueCpy)
{
	TCNT0 = u8TimerValueCpy;
}
uint8 TIM0_u8GetTimeValue( void)
{
	return TCNT0 ;
}
void  TIM0_voidSetCompareValue(uint8 u8CompValueCpy)
{
	OCR0 = u8CompValueCpy;
}
void  TIM0_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK,0);
}
void  TIM0_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK,0);
}
void  TIM0_voidEnableCmpInt(void)
{
	SET_BIT(TIMSK,1);
}
void  TIM0_voidDisableCmpInt(void)
{
	CLR_BIT(TIMSK,1);
}
void  TIM0_voidSetCallbackOvf(pf pfCpy)
{
	TIM0_pfOvfFun = pfCpy;
}
void  TIM0_voidSetCallbackCmp(pf pfCpy)
{
	TIM0_pfCmpFun= pfCpy;
}

void __vector_10 (void) __attribute__ ((signal ,used));
void __vector_10 (void)
{
	TIM0_pfCmpFun();
}

/*OVF interrupt*/
void __vector_11 (void) __attribute__ ((signal ,used));
void __vector_11 (void)
{
	TIM0_pfOvfFun();
}



