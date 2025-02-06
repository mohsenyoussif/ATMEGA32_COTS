/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: TIMER        **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef  TIMER_INTERFACE_H
#define  TIMER_INTERFACE_H


void TIMER0_voidInit(void);

uint8 TIMER0_uint8setcallBack(void*copy_pvCallBackFunc(void));
#endif