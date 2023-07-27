/******************************************/
/* Description : interface file for timer0*/
/* Author      : mustafa ali              */
/* Date        : sep 2022                 */
/* Version     : 0.1V                     */ 
/******************************************/
#ifndef   TIM0_INT_H
#define   TIM0_INT_H

#define TIM0_MODE_NORMAL     0
#define TIM0_MODE_CTC        1
#define TIM0_MODE_FAST_PWM   2
#define TIM0_MODE_PHASE_PWM  3

#define TIM0_WF_TOGGLE_PIN         0
#define TIM0_WF_CLR_PIN            1
#define TIM0_WF_SET_PIN            2
#define TIM0_WF_SET_CMP_CLR_TOP    3
#define TIM0_WF_CLR_CMP_SET_TOP    4
#define TIM0_WF_SET_UPC_CLR_DNC    5
#define TIM0_WF_SET_DNC_CLR_UPC    6
#define TIM0_WF_OFF                7


void  TIM0_voidInit(void);
void  TIM0_voidChangeMode(uint8 u8ModeValueCpy);
void  TIM0_voidChangeWfMode(uint8 u8WfModeValueCpy);
void  TIM0_voidSetTimeValue(uint8 u8TimerValueCpy);
uint8 TIM0_u8GetTimeValue( void);
void  TIM0_voidSetCompareValue(uint8 u8CompValueCpy);
void  TIM0_voidEnableOvfInt(void);
void  TIM0_voidDisableOvfInt(void);
void  TIM0_voidEnableCmpInt(void);
void  TIM0_voidDisableCmpInt(void);
void  TIM0_voidSetCallbackOvf(pf pfCpy);
void  TIM0_voidSetCallbackCmp(pf pfCpy);






#endif
