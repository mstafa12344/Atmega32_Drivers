/****************************************/
/*******   Name  : Mustafa Ali   ********/
/*******   Layer : RTOS_Stack    ********/
/*******   SWC   : RTOS          ********/
/*******   Date  : 21/12/2022    ********/
/****************************************/

#ifndef RTOS_PRIV_H
#define RTOS_PRIV_H

typedef struct
{
	uint16 Periodicity;
	uint8 State;
	void (*pf)(void) ;
	uint16 FirstDelay;
	
}RTOS_TCB;
static void RTOS_voidScheduler(void);
#define TASK_RESUMED     0
#define TASK_SUSPENDED   1
#endif
