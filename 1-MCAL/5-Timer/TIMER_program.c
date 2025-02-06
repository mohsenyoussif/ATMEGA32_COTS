/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: TIMER        **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (TIMER0_PVCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*Define the timer mode as CTC */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	
	/*Define the timer clock , prescaler /8*/
	CLR_BIT_BIT(TCCR0,TCCR0_TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT_BIT(TCCR0,TCCR0_CS02);
	
	/*SET the compare match value to 250 as our APP*/
	OCR0=COMPAREVALUE;
	
	/*Enable compare match interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
}

uint8 TIMER0_uint8setcallBack(void(*copy_pvCallBackFunc(void))
{
	 uint8 Local_uint8ErrorStatus =OK;
	 if(copy_pvCallBackFunc !=NULL)
	 {
	 TIMER0_PVCallBackFunc=copy_pvCallBackFunc;
	 }
     else{
		 Local_uint8ErrorStatus =NULL_POINTER ;
	 }

	return Local_uint8ErrorStatus ;
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_PVCallBackFunc !=NULL)
	{
		TIMER0_PVCallBackFunc();
	}
	
}