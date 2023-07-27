/****************************************/
/*******   Name  : Mustafa Ali   ********/
/*******   Layer : RTOS_Stack    ********/
/*******   SWC   : RTOS          ********/
/*******   Date  : 21/12/2022    ********/
/****************************************/

#include "STD_Types.h"
#include "BIT_Math.h"

/*HAL*/
#include "TIM0_int.h"

/*RTOS*/
#include "RTOS_int.h"
#include "RTOS_cfg.h"
#include "RTOS_priv.h"

/*Array of TCBS*/

RTOS_TCB  RTOS_ArrTasks[NUMBER_OF_TASK] = {{NULL_PTR}};


void RTOS_voidInit(void)
{
	TIM0_voidSetCallbackCmp(&RTOS_voidScheduler);
	GIE_voidEnable();
	TIM0_voidInit();
}
void RTOS_voidDeletTask(uint8 u8Priority)
{
	RTOS_ArrTasks[u8Priority].pf = NULL_PTR;
}
void RTOS_voidCreatTask(uint8 u8PeriorityCpy,uint16 u16PeriodicityCpy,void(*pfCpy)(void),uint16 u16FirstDelay )
{
	if(RTOS_ArrTasks[u8PeriorityCpy].pf == NULL_PTR)
	{
		RTOS_ArrTasks[u8PeriorityCpy].Periodicity = u16PeriodicityCpy;
		RTOS_ArrTasks[u8PeriorityCpy].pf          = pfCpy;
		RTOS_ArrTasks[u8PeriorityCpy].State       = TASK_RESUMED;
		RTOS_ArrTasks[u8PeriorityCpy].FirstDelay  = u16FirstDelay;

	}
	else
	{

	}
}
void RTOS_voidResumeTask(uint8 u8Priority)
{
	RTOS_ArrTasks[u8Priority].State= TASK_RESUMED;
}
void RTOS_voidSuspendTask(uint8 u8Priority)
{
	RTOS_ArrTasks[u8Priority].State= TASK_SUSPENDED;
}
static void RTOS_voidScheduler(void)
{

	uint8 Local_u8TaskCounter;

	for(Local_u8TaskCounter=0;Local_u8TaskCounter<NUMBER_OF_TASK;Local_u8TaskCounter++)
	{
		if(RTOS_ArrTasks[Local_u8TaskCounter].State== TASK_RESUMED)
		{
			if(RTOS_ArrTasks[Local_u8TaskCounter].FirstDelay == 0)
			{
				RTOS_ArrTasks[Local_u8TaskCounter].pf();
				RTOS_ArrTasks[Local_u8TaskCounter].FirstDelay = RTOS_ArrTasks[Local_u8TaskCounter].Periodicity-1  ;
			}
			else
			{
				RTOS_ArrTasks[Local_u8TaskCounter].FirstDelay --;
			}
		}
		else
		{

		}
	}

}                                   
