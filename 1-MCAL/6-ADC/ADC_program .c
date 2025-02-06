/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: ADC                *************/
/***********   Version: 1.00           *************/
/***************************************************/
/***************************************************/

#include "platform_Types.h"
#include "BIT_MATH.h"
#include "ADC_register.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

static uint8* ADCuint8eading =NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;

uint8 ADC_uint8State  =IDLE ;

void ADC_voidInit(void)
{
	/*Select the voltage reference*/
#if ADC_VREF == AVCC

	SET_BIT(ADMUX , ADMUX_REFS0) ;
	CLR_BIT(ADMUX , ADMUX_REFS1) ;

#elif ADC_VREF == AREF
	CLR_BIT(ADMUX , ADMUX_REFS0) ;
	CLR_BIT(ADMUX , ADMUX_REFS1) ;

#elif ADC_VREF == INTERNAL_2_56
	SET_BIT(ADMUX , ADMUX_REFS0) ;
	SET_BIT(ADMUX , ADMUX_REFS1) ;

#else
#error "Wrong ADC_VREF config"

#endif


	/*Set Left Adjust Result*/
#if ADC_ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX , ADMUX_ADLAR) ;

#elif ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX , ADMUX_ADLAR) ;

#else
#error "Wrong ADC_ADJUSTMENT config"

#endif

	/*Set Prescaler Value*/
	ADSAR &= ADC_PRE_MASK ;   // ADC_PRE_MASK has the value of 3bits which you are interested
	ADSAR |= ADC_PRESCALLER ;

	/* ENABLE The Peripheral & Interrupt  */


	/*Enable ADC Peripheral*/
#if ADC_STATUS == ADC_ENABLE
	SET_BIT(ADSAR , ADSAR_ADEN) ;

#elif ADC_STATUS == ADC_DISABLE
	CLR_BIT(ADSAR , ADSAR_ADEN) ;

#else
#error "Wrong ADC_STATUS config"
#endif

	/*Enable ADC Interrupt*/
#if INT_STATUS == INT_DISABLE
	CLR_BIT(ADSAR , ADSAR_ADIE) ;
#elif INT_STATUS == INT_ENABLE
	SET_BIT(ADSAR , ADSAR_ADIE) ;
#else
#error "Wrong INT_STATUS config"
#endif

}

uint8 ADC_uint8GetChannelReadingSynch(uint8 copy_uint8channel,uint8* Copy_pu8Rading)
{
uint8 Local_uint8ErrorState = OK ;
uint32 Local_u3int2TimeoutCounter = 0 ;
if(ADC_uint8State = IDLE)
{
	/*Make the ADC busy in order not to work until being IDLE  */
	ADC_uint8State = BUSY;

/*clear the MUX bitd in ADMUX register*/
ADMUX &= ADC_CH_MASK ;

/*Set required channel*/
ADMUX |= copy_uint8channel ;

/*ADC Start Conversion */
SET_BIT(ADCSRA,ADCSRA_ADSC);

/*polling (busy waiting) until the conversion complete flag is set or counter reaching time out */
while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0) && (Local_u3int2TimeoutCounter < ADC_TIMEOUT ))
{
	Local_u3int2TimeoutCounter ++ ;
}
if(Local_u3int2TimeoutCounter ==ADC_TIMEOUT)
{
	// Loop is broken because the timeout is reached
	Local_uint8ErrorState = TIMEOUT_STATE ;
}else
{// Loop is broken because Flag is raised

	/*Clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*Return the ADC reading */
	*Copy_pu8Rading = ADCH;

	/*Make ADC state be IDLE because it finished */
	 ADC_uint8State = IDLE;

}

}else
{
	Local_uint8ErrorState = BUSY_FUNCTION;
}



return Local_uint8ErrorState;

}



uint8 ADC_u8StartConversionAsynch(uint8 Copy_uint8Channel , uint8 * Copy_pu8Rading ,void (*Copy_pvNotificationFunc)(void))
{
	uint8 Local_uint8ErrorState = OK ;
      if(ADC_uint8State ==IDLE)
      {
	if ((Copy_pu8Rading != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		/*Make the ADC busy in order not to work until being IDLE  */
		ADC_uint8State = BUSY;
		/*Initialize the global result pointer*/
		ADCuint8eading = Copy_pu8Rading;

		/*Initialize the global notification function pointer*/
		ADC_pvCallBackNotificationFunc= Copy_pvNotificationFunc;

		/*clear the MUX bits in ADMUX register*/
		ADMUX &= ADC_CH_MASK ;

		/*Set required channel*/
		ADMUX |= Copy_uint8Channel ;

		/*ADC Start Conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*ADC Conversion Complete Interrupt Enable*/
		SET_BIT(ADSAR , ADSAR_ADIE) ;
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}
      }else
      {
    	  Local_uint8ErrorState =BUSY_FUNCTION;
      }

return Local_uint8ErrorState ;
}



/* ISR for ADC conversion complete */
void __vector_16 (void) __attribute__((signal)) ;
void __vector_16 (void)
{
	/*Reading the ADC result*/
	*ADCuint8eading =ADCH;

	 /*Make ADC state be IDLE because it finished */
	ADC_uint8State = IDLE;

	/*Invoke the callback notification function */
	ADC_pvCallBackNotificationFunc();

	/*Disable ADC conversion complete interrupt  */
	CLR_BIT(ADSAR , ADSAR_ADIE) ;
}



