#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO_int.h"

#include "SEV_int.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"

uint8 SEV_au8CathodMatrix[10] =
{
	0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D ,  0x7D ,  0x07, 0x7F , 0x6F
};

tenuErrorStatus SEV_enuOnOff(uint8 u8SevIndxCpy, uint8 u8SevStateCpy)
{
	tenuErrorStatus enuReturnStatLoc = E_OK ;
	
	if(u8SevIndxCpy < SEV_MAX_NUM )
	{
		if(u8SevStateCpy == 0)
		{
			
		   if (SEV_astrConfig[u8SevIndxCpy].u8SevMode== SEV_COMMON_ANODE)
		   {
			   DIO_enuWritePin(SEV_astrConfig[u8SevIndxCpy].u8CommonPinMap,0);
		   }
		   else if (SEV_astrConfig[u8SevIndxCpy].u8SevMode == SEV_COMMON_CATHODE)
		   {
			   DIO_enuWritePin(SEV_astrConfig[u8SevIndxCpy].u8CommonPinMap,1);
			   
		   }
		   else
		   {
			   enuReturnStatLoc = E_NOK_CONFIG_ERROR ;
		   }
		
		}
		else if (u8SevStateCpy == 1)
		{  
	      if (SEV_astrConfig[u8SevIndxCpy].u8SevMode== SEV_COMMON_ANODE)
		   {
			   DIO_enuWritePin(SEV_astrConfig[u8SevIndxCpy].u8CommonPinMap,1);
		   }
		   else if (SEV_astrConfig[u8SevIndxCpy].u8SevMode == SEV_COMMON_CATHODE)
		   {
			   DIO_enuWritePin(SEV_astrConfig[u8SevIndxCpy].u8CommonPinMap,0);
			   
		   }
		   else
		   {
			   enuReturnStatLoc = E_NOK_CONFIG_ERROR ;
		   }
		
			
		}
		else
		{
			enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;	
		}
	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	
	return enuReturnStatLoc ;
	
}

tenuErrorStatus SEV_enuWrite(uint8 u8SevIndxCpy , uint8 u8SevValueCpy)
{
	tenuErrorStatus enuReturnStatLoc = E_OK ;
	if(u8SevIndxCpy < SEV_MAX_NUM)
	{
		if(u8SevValueCpy <= 9)
		{
			if(SEV_astrConfig[u8SevIndxCpy].u8SevMode == SEV_COMMON_ANODE)
			{
				SEV_voidHelp(u8SevIndxCpy , ~SEV_au8CathodMatrix[u8SevValueCpy]);
			}
			else if(SEV_astrConfig[u8SevIndxCpy].u8SevMode == SEV_COMMON_CATHODE)
			{
				SEV_voidHelp(u8SevIndxCpy , SEV_au8CathodMatrix[u8SevValueCpy]);
			}
			else
			{
				enuReturnStatLoc = E_NOK_CONFIG_ERROR ;
			}
		}
		else
		{
	       enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
		}
	}
	else
	{
	  enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;	
	}
	return enuReturnStatLoc ;
}

static void SEV_voidHelp(uint8 u8SevIndxCpy , uint8 u8SevValueCpy)
{
	uint8 u8CntLoc ;
	for (u8CntLoc = 0 ;u8CntLoc < 7 ;u8CntLoc++)
	{
		DIO_enuWritePin(SEV_astrConfig[u8SevIndxCpy].au8SevPinMap[u8CntLoc],GET_BIT(u8SevValueCpy,u8CntLoc));
	
	}
	
}