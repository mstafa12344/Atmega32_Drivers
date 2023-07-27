/****************************************/
/* Description : program file for GIE   */
/* Author      : mustafa ali            */
/* Date        :    Aug 2022            */
/* Version     : 0.1V                   */ 
/****************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "GIE_int.h"
#include "GIE_priv.h"

void GIE_voidEnable(void)
{
	
	SET_BIT(SREG , 7);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG , 7);
	
}
