#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM0_int.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"

pf TIM0_pfCmpFun ;
void  TIM0_voidInit(void)
{
	TCCR0 &= 0b11111000;
	TCCR0 |= TIM0_PPRESCALLER ;
	/*CTC Mode */
	CLR_BIT(TCCR0 , 6);
	SET_BIT(TCCR0 , 3);
	/*Compare Match Value*/
	OCR0 = TIM0_U8COMP_MATCH_VAL;
	CLR_BIT(TCCR0 ,4);
	CLR_BIT(TCCR0 ,5);
	
	
	
}

void  TIM0_voidEnableCmpInt(void)
{
	SET_BIT(TIMSK,1);
}
void  TIM0_voidDisableCmpInt(void)
{
	CLR_BIT(TIMSK,1);
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



