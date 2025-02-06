/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  HAL            **************/
/***********   SWC: LED             **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef  LED_H_
#define  LED_H_
typedef enum
{
	LED_1,
	LED_2,
	LED_3,
	LED_4
}tLED;

typedef enum
{
	LED_OFF=0 ,
	LED_ON =1
}tLED_State;


 void LED_Init(tLED copy_tLEDled,tLED_State copy_tLEDInitialState);
 void LED_Update(void);
 tLED_State LED_GetState(tLED copy_tLEDled);
 LED_SetState(tLED copy_tLEDled,tLED_State copy_tLEDState);
 
#endif