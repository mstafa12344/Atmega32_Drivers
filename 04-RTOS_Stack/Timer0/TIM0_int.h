#ifndef   TIM0_INT_H
#define   TIM0_INT_H



#define TIM0_WF_TOGGLE_PIN         0
#define TIM0_WF_CLR_PIN            1
#define TIM0_WF_SET_PIN            2
#define TIM0_WF_SET_CMP_CLR_TOP    3
#define TIM0_WF_CLR_CMP_SET_TOP    4
#define TIM0_WF_SET_UPC_CLR_DNC    5
#define TIM0_WF_SET_DNC_CLR_UPC    6
#define TIM0_WF_OFF                7


void  TIM0_voidInit(void);
void  TIM0_voidSetCompareValue(uint8 u8CompValueCpy);
void  TIM0_voidEnableCmpInt(void);
void  TIM0_voidDisableCmpInt(void);
void  TIM0_voidSetCallbackCmp(pf pfCpy);






#endif
