/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: DIO                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "platform_Types.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"





uint8 DIO_uint8SetPinValue(uint8 Copy_uint8Port,uint8 Copy_uint8Pin,uint8 Copy_uint8Value)
{
	uint8 Local_uint8ErrorState = 0 ;

	if(Copy_uint8Pin<=DIO_uint8PIN7 )
	{
		if(Copy_uint8Value == DIO_uint8PIN_HIGH)
		{
			switch(Copy_uint8Port)
			{
			case DIO_uint8PORTA : SET_BIT(PORTA,Copy_uint8Pin);  break;
			case DIO_uint8PORTB : SET_BIT(PORTB,Copy_uint8Pin);  break;
			case DIO_uint8PORTC : SET_BIT(PORTC,Copy_uint8Pin);  break;
			case DIO_uint8PORTD : SET_BIT(PORTD,Copy_uint8Pin);  break;
			default             : Local_uint8ErrorState = 1   ;  break;
			}
		}

		else if (Copy_uint8Value == DIO_uint8PIN_LOW)
		{
			switch(Copy_uint8Port)
			{
			case DIO_uint8PORTA : CLR_BIT(PORTA,Copy_uint8Pin);  break;
			case DIO_uint8PORTB : CLR_BIT(PORTB,Copy_uint8Pin);  break;
			case DIO_uint8PORTC : CLR_BIT(PORTC,Copy_uint8Pin);  break;
			case DIO_uint8PORTD : CLR_BIT(PORTD,Copy_uint8Pin);  break;
			default             : Local_uint8ErrorState = 1   ; break ;
			}
		}
		else
		{
			Local_uint8ErrorState = 1 ;
		}
	}
	else
	{
		Local_uint8ErrorState = 1 ;
	}

	return Local_uint8ErrorState ;
}

uint8 DIO_uint8SetPortValue(uint8 Copy_uint8Port,uint8 Copy_uint8Value)
{
	uint8 Local_uint8ErrorState = 0 ;

	switch(Copy_uint8Port)
	{
	case DIO_uint8PORTA : PORTA = Copy_uint8Value   ;   break;
	case DIO_uint8PORTB : PORTB = Copy_uint8Value   ;   break;
	case DIO_uint8PORTC : PORTC = Copy_uint8Value   ;   break;
	case DIO_uint8PORTD : PORTD = Copy_uint8Value   ;   break;
	default             : Local_uint8ErrorState = 1 ;   break;

	}
	return Local_uint8ErrorState ;
	}

	uint8 DIO_uint8GetPinValue(uint8 Copy_uint8Port,uint8 Copy_uint8Pin,uint8* Copy_Puint8Value)
	{

		uint8 Local_uint8ErrorState = 0 ;
		if((Copy_Puint8Value !=NULL) && Copy_uint8Pin<=DIO_uint8PIN7)
		{

			switch(Copy_uint8Port)
			{
			case DIO_uint8PORTA :  *Copy_Puint8Value = GET_BIT(PINA,Copy_uint8Pin) ; break;
			case DIO_uint8PORTB :  *Copy_Puint8Value = GET_BIT(PINB,Copy_uint8Pin) ; break;
			case DIO_uint8PORTC :  *Copy_Puint8Value = GET_BIT(PINC,Copy_uint8Pin) ; break;
			case DIO_uint8PORTD :  *Copy_Puint8Value = GET_BIT(PIND,Copy_uint8Pin) ; break;
			default             :  Local_uint8ErrorState = 1 ;                        break;
			}
		}
		else
		{
			Local_uint8ErrorState = 1 ;
		}


	return Local_uint8ErrorState ;
}
