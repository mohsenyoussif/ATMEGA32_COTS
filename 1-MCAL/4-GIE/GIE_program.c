/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: GIE                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_registers.h"
void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
