/******************************************/
/* Description : interface file for timer1*/
/* Author      : mustafa ali              */
/* Date        : sep 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#ifndef TIM1_INT_H
#define TIM1_INT_H

void TIM1_void_Init(void);
void TIM1_voidSetTimeValue(uint16 u16TimerValueCpy);
void TIM1_voidSetComMatchValueA(uint16 u16TimerCompValueACpy);
void TIM1_voidSetComMatchValueB(uint16 u16TimerCompValueBCpy);
void TIM1_voidEnableOVFIntterrupt(void);
void TIM1_voidDisableOVFIntterrupt(void);
void TIM1_voidEnableCTCAInterrupt(void);
void TIM1_voidDisableCTCAInterrupt(void);
void TIM1_voidEnableCTCBInterrupt(void);
void TIM1_voidDisableCTCBInterrupt(void);
void TIM1_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM1_voidSetCtcACallback(pf pfCtcCallbackCpy);
void TIM1_voidSetCtcBCallback(pf pfCtcCallbackCpy);
uint16 TIM1_u16GetCntrValue(void);
void TIM1_voidSeICR1Value(uint16 u16TimerICRValueBCpy);
/*********************************************************/
/***********************ICU*******************************/
/*********************************************************/
void Timer1Icu_voidInit(void);
void Timer1ICU_voidSetTriggerEdge(uint8 u8ICUEdgeCpy);
void TIM1_voidEnableICUIntterrupt(void);
void TIM1_voidDisableICUIntterrupt(void);
void TIM1_voidSetICUCallback(pf pfCtcCallbackCpy);
uint16 Timer1IcuGetValu(void);



#endif
