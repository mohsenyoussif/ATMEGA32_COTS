/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: USART               **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


void USART_VoidInit(void) ;

void USART_voidSendData(uint8 Copy_uint8Data);

uint8 USART_uint8ReceiveData(void);

#endif
