#include <stdio.h>
#include "STD_Types.h"
#include "BIT_Math.h"

void main (void)
{
	uint8 x = 10 ;
	uint8 y ;
	
	SET_BIT(x , 2);
	printf("%d\n",x);
	
	CLR_BIT(x , 2);
	printf("%d\n",x);
	
	TGL_BIT(x , 3);
	printf("%d\n",x);
	
	y = GET_BIT(x , 1);
	printf("%d\n",y);
}