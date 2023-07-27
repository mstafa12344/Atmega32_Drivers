

#ifndef KEYPAD_PRIV_H
#define KEYPAD_PRIV_H

typedef struct
{
	uint8 au8SwitchMapping[KEYPAD_MAX_INPUT_PIN_NUMS][KEYPAD_MAX_OUTPUT_PIN_NUMS];
	uint8 au8InputPinsCon [KEYPAD_MAX_INPUT_PIN_NUMS];
	uint8 au8OutputPinsCon[KEYPAD_MAX_OUTPUT_PIN_NUMS];
	uint8 au8MaskValue[KEYPAD_MAX_INPUT_PIN_NUMS];
	uint8 u8InputPinNum;
	uint8 u8OutputPinNum;
	
}tstrKeypadInfo;

extern tstrKeypadInfo  KEYPAD_astrConfigSet[KEYPAD_MAX_NUM];

static uint8 KEYPAD_u8Check(uint8 u8KeypadNumCpy , uint8 u8SeqIndxCpy ,uint8 u8ReadValueCpy );
static void KEYPAD_voidReadInputs(uint8 u8KeypadNumCpy , uint8 *pu8ReadValueCpy);
static void KEYPAD_voidWriteSeq(uint8 u8KeypadNumCpy , uint8 u8SeqIndxCpy);



#endif 