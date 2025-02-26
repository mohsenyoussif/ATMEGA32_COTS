 /***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: DIO                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
#include "Platform_Types.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"


void PORT_voidInit(void)
{
	DDRA =PORTA_DIR ;
	DDRB =PORTB_DIR  ;
	DDRC =PORTC_DIR ;
	DDRD =PORTD_DIR ;
	
	PORTA  = PORTA_INITIAL_VALUE;
	PORTB  = PORTB_INITIAL_VALUE ;
	PORTC  = PORTC_INITIAL_VALUE ;
	PORTD  = PORTD_INITIAL_VALUE  ;
}
