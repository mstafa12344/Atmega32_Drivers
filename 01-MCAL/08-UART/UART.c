#include "STD_Types.h"
#include "BIT_Math.h"

#include "UART_int.h"
#include "UART-cfg.h"
#include "UART_priv.h"



void UART_voidInit(uint16 BUDRATE)
{
	UBBRL = (uint8)BUDRATE;
	UBBRH = (uint8)(BUDRATE>>8);

	uint8 Local_u8UCSRC=0b10000000;
	#if UART_SPEED == NORMAL_SPEED
	CLR_BIT(UCSRA,1);
	#else
	SET_BIT(UCSRA,1);
	#endif
	/* NO MULTI CORE */
	CLR_BIT(UCSRA,0);

	/* RX ENABLE AND TX ENABLE*/
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);

	/*CHARACTER SIZE*/
	#if   CHARACTER_SIZE == DATA_5BIT
	CLR_BIT(Local_u8UCSRC,1);
	CLR_BIT(Local_u8UCSRC,2);
	CLR_BIT(UCSRB,2);
	#elif CHARACTER_SIZE == DATA_6BIT
	SET_BIT(Local_u8UCSRC,1);
	CLR_BIT(Local_u8UCSRC,2);
	CLR_BIT(UCSRB,2);
	#elif CHARACTER_SIZE == DATA_7BIT
	CLR_BIT(Local_u8UCSRC,1);
	SET_BIT(Local_u8UCSRC,2);
	CLR_BIT(UCSRB,2);
	#elif CHARACTER_SIZE == DATA_8BIT
	SET_BIT(Local_u8UCSRC,1);
	SET_BIT(Local_u8UCSRC,2);
	CLR_BIT(UCSRB,2);
	#else 
	SET_BIT(Local_u8UCSRC,1);
	SET_BIT(Local_u8UCSRC,2);
	SET_BIT(UCSRC,2);	
	#endif
	
	#if UART_MODE==SYNC_MODE
	SET_BIT(Local_u8UCSRC,6);
		#if CLOCK_POLARITY==FALLING_TX_RISING_RX
		SET_BIT(Local_u8UCSRC,0);
		#else
		clr_BIT(Local_u8UCSRC,0);
		#endif
	#else
	CLR_BIT(Local_u8UCSRC,6);
	#endif
	
	#if   PARITY_MODE==PARITY_DISABLE
	CLR_BIT(Local_u8UCSRC,4);
	CLR_BIT(Local_u8UCSRC,5);
	#elif PARITY_MODE==PARITY_ENABLE
	SET_BIT(Local_u8UCSRC,4);
	CLR_BIT(Local_u8UCSRC,5);
	#elif PARITY_MODE==PARITY_EVEN
	CLR_BIT(Local_u8UCSRC,4);
	SET_BIT(Local_u8UCSRC,5);
	#else
	SET_BIT(Local_u8UCSRC,4);
	SET_BIT(Local_u8UCSRC,5);
	#endif
	
	#if STOP_BIT_MODE  == STOP_1BIT
	CLR_BIT(Local_u8UCSRC,3);
	#else
	SET_BIT(Local_u8UCSRC,3);	
	#endif
	/*PUT VALUE FROM VARIBALE INTO REGISTER*/
	UCSRC = Local_u8UCSRC;

	
}

void UART_voidTransmit(uint8 u8DataCpy)
{
	while(GET_BIT(UCSRA,5)== 0);
	UDR = u8DataCpy ; 
}

uint8 UART_u8Receive (void)
{
	uint8 result;
	while(GET_BIT(UCSRA,7)== 0);
	result = UDR;
	return result ;
}
