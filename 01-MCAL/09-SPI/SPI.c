#include "STD_Types.h"
#include "BIT_Math.h"

#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_cfg.h"

void SPIMaster_voidInit(void)
{
	SET_BIT(SPCR,4);

	#if SPI_CLK_RATE == FCPU_DIV4
		CLR_BIT(SPCR,0);
		CLR_BIT(SPCR,1);
		CLR_BIT(SPSR,0);
	#elif SPI_CLK_RATE == FCPU_DIV16
		SET_BIT(SPCR,0);
		CLR_BIT(SPCR,1);
		CLR_BIT(SPSR,0);
   #elif SPI_CLK_RATE == FCPU_DIV64
	   CLR_BIT(SPCR,0);
	   SET_BIT(SPCR,1);
	   CLR_BIT(SPSR,0);
   #elif SPI_CLK_RATE == FCPU_DIV128
	   SET_BIT(SPCR,0);
	   SET_BIT(SPCR,1);
	   CLR_BIT(SPSR,0);
   #elif SPI_CLK_RATE == FCPU_DIV2
	   CLR_BIT(SPCR,0);
	   CLR_BIT(SPCR,1);
	   SET_BIT(SPSR,0);
   #elif SPI_CLK_RATE == FCPU_DIV8
	   SET_BIT(SPCR,0);
	   CLR_BIT(SPCR,1);
	   SET_BIT(SPSR,0);
  #elif SPI_CLK_RATE == FCPU_DIV32
	   CLR_BIT(SPCR,0);
	   SET_BIT(SPCR,1);
	   SET_BIT(SPSR,0);
  #endif



	   /*clk polarity*/
#if CLK_POLARITY_MODE == LEAD_RIS_TRE_FALL
	  CLR_BIT(SPCR,3);
#elif CLK_POLARITY_MODE == LEAD_FALL_TRE_RIS
	SET_BIT(SPCR,3);
#endif

	/*CLK PHASE*/
#if CLK_PHASE_MODE == LEAD_SAMPL_TRE_SETUP
	CLR_BIT(SPCR,2) ;
#elif CLK_PHASE_MODE == LEAD_SETUP_TRE_SAMPL
	SET_BIT(SPCR,2);
#endif

	/*data order*/
#if	DATA_ORDER == FIRST_MS
	CLR_BIT(SPCR,5) ;
#elif DATA_ORDER == FIRST_LS
	SET_BIT(SPCR,5);
#endif

	/*enable spi*/
	SET_BIT(SPCR,6);

}
void SPISlave_voidInit(void)
{
	CLR_BIT(SPCR,4);
	/*enable spi*/
	SET_BIT(SPCR,6);
}
tenuErrorStatus SPI_u8Transceiver(uint8 u8DataCpy,uint8 * RecievData)
{
	tenuErrorStatus ErrorStatusReturnVal=E_OK;
	if(RecievData==NULL_PTR)
	{
		ErrorStatusReturnVal = E_NOK_PARAM_NULL_POINTER;
	}
	else
	{
		SPDR = u8DataCpy;
		while(GET_BIT(SPSR,7)==0);
		* RecievData = SPDR;
	}
	return ErrorStatusReturnVal;
}

