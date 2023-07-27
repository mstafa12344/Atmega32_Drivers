#include "STD_Types.h"
#include "keypad_cfg.h"
#include "keypad_priv.h"

uint8 KeyPad_au8SitchKey[ROWS_NUMBERS][COLS_NUMBERS]=
{
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','*'},
	{'0','=','/','%'}
	
};

uint8 au8Rows[ROWS_NUMBERS]={24,25,26,27};
uint8 au8cols[COLS_NUMBERS]={28,29,30,31};