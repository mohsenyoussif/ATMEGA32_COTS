/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  HAL            **************/
/***********   SWC: KYPAD              **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT        DIO_uint8PORTD

#define KPD_NO_PRESSED_KEY     0xff

#define KPD_COLUMN0_PIN        DIO_uint8PIN0
#define KPD_COLUMN1_PIN        DIO_uint8PIN1
#define KPD_COLUMN2_PIN        DIO_uint8PIN2
#define KPD_COLUMN3_PIN        DIO_uint8PIN3

#define KPD_ROW0_PIN          DIO_uint8PIN4
#define KPD_ROW1_PIN          DIO_uint8PIN5
#define KPD_ROW2_PIN          DIO_uint8PIN6
#define KPD_ROW3_PIN          DIO_uint8PIN7

#define KPD_ARR_VAL              {\
									{'7', '8', '9', '+'},\
									{'4', '5', '6', '-'},\
									{'1', '2', '3', 'x'},\
									{'c', '0', '=', '/'}\
								}

#endif
