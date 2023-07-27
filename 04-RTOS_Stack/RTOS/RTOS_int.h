/****************************************/
/*******   Name  : Mustafa Ali   ********/
/*******   Layer : RTOS_Stack    ********/
/*******   SWC   : RTOS          ********/
/*******   Date  : 21/12/2022    ********/
/****************************************/

#ifndef RTOS_INT_H
#define RTOS_INT_H

void RTOS_voidInit(void);/*initial for timer that uses in scheduler*/
void RTOS_voidCreatTask(uint8 u8PeriorityCpy,uint16 u16PeriodicityCpy,void(*pfCpy)(void),uint16 u16FirstDelay );
void RTOS_voidDeletTask(uint8 u8Priority);
void RTOS_voidResumeTask(uint8 u8Priority);
void RTOS_voidSuspendTask(uint8 u8Priority);

#endif
