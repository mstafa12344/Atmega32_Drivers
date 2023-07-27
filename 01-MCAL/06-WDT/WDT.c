/******************************************/
/* Description : program  file for WDT    */
/* Author      : mustafa ali              */
/* Date        : sep 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "WDT_int.h"
#include "WDT_cfg.h"
#include "WDT_priv.h"

void WDT_voidEnable(void)
{
	WDTCR = WDT_PRESCALER;
}
void WDT_voidDisable(void)
{
	WDTCR |=(1<<4)|(1<<3);
    WDTCR = 0X00;	
	
}