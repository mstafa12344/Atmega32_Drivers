
#ifndef  SEV_PRIV_H
#define  SEV_PRIV_H

#define SEV_COMMON_ANODE    0
#define SEV_COMMON_CATHODE  1

typedef struct {
	uint8 u8SevMode ;
	uint8 u8CommonPinMap ;
	uint8 au8SevPinMap[7] ;
	
}tstrSevCfg;

extern tstrSevCfg  SEV_astrConfig [SEV_MAX_NUM]  ;

static void SEV_voidHelp(uint8 u8SevIndxCpy , uint8 u8SevValueCpy);

#endif