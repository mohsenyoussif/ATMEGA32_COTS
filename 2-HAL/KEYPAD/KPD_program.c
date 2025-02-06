/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  HAL            **************/
/***********   SWC: KYPAD              **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "Platform_Types.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

uint8 KPD_uint8GetPressedKey(void)
{
	uint8 Local_uint8PressedKey =KPD_NO_PRESSED_KEY;
	uint8 Local_uint8PinState ;
	uint8 Local_uint8OClumnIdx ; /* for columns index */
	uint8 Local_uint8RowIdx; /* for Rows index */

	static uint8 Local_uint8KPDArr[ROW_NUM][COLUMN_NUM]= KPD_ARR_VAL  ;
	
	/* TO use it through looping to activate column*/
	static uint8 Local_uint8KPDColumnArr[COLUMN_NUM]={
			KPD_COLUMN0_PIN,
			KPD_COLUMN1_PIN,
			KPD_COLUMN2_PIN,
			KPD_COLUMN3_PIN  };
	static uint8 Local_uint8KPDRowArr[ROW_NUM]={
			KPD_ROW0_PIN,
			KPD_ROW1_PIN,
			KPD_ROW2_PIN,
			KPD_ROW3_PIN};

	for(Local_uint8OClumnIdx=0;Local_uint8OClumnIdx<COLUMN_NUM;Local_uint8OClumnIdx++)
	{
		/* Activate Current column */
		DIO_uint8SetPinValue(KPD_PORT ,Local_uint8KPDColumnArr[Local_uint8OClumnIdx],DIO_uint8PIN_LOW) ;
		for(Local_uint8RowIdx=0;Local_uint8RowIdx<ROW_NUM ;Local_uint8RowIdx++)
		  {
                  /*Read the current row */
			 DIO_uint8GetPinValue(KPD_PORT,Local_uint8KPDRowArr[Local_uint8RowIdx],&Local_uint8PinState);
			   /* Check if switch is pressed */
			 if(Local_uint8PinState == DIO_uint8PIN_LOW)
			  {
				 Local_uint8PressedKey =Local_uint8KPDArr[Local_uint8RowIdx][Local_uint8OClumnIdx];

				 /* polling (busy waiting until the key is pressed ) */
				 while(Local_uint8PinState == DIO_uint8PIN_LOW)
				 {
					 DIO_uint8GetPinValue(KPD_PORT,Local_uint8KPDRowArr[Local_uint8RowIdx],&Local_uint8PinState);
				 }
					return Local_uint8PressedKey;
			  }
		  }
		  /* De-activate Current column */
				DIO_uint8SetPinValue(KPD_PORT ,Local_uint8KPDColumnArr[Local_uint8OClumnIdx],DIO_uint8PIN_HIGH) ;

	}

	return Local_uint8PressedKey;

}
