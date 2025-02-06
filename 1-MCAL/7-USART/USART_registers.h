/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: USART               ************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
#ifndef USART_REGESTER_H_
#define USART_REGESTER_H_

#include "Platform_Types.h"

#define UDR        *((volatile uint8*)0x0c)
#define UCSRA      *((volatile uint8*)0x2B)
#define UCSRA_RXC       7                       /* USART Receive Complete*/
#define UCSRA_TXC       6
#define UCSRA_UDRE      5
#define UCSRA_FE		4
#define UCSRA_FE		4
#define UCSRA_DOR		3
#define UCSRA_PE		2
#define UCSRA_U2X		1
#define UCSRA_MPCM		0


#define UCSRB      *((volatile uint8*)0x2A)
#define UCSRB_RXCIE           7                    /*RX Complete Interrupt Enable*/
#define UCSRB_TXCIE           6                   /*TX Complete Interrupt Enabl*/
#define UCSRB_UDRIE           5                   /* USART Data Register Empty Interrupt Enable*/
#define UCSRB_RXEN            4                  /* Receiver Enable*/
#define UCSRB_TXEN            3                  /*Transmitter Enable*/
#define UCSRB_UCSZ2           2                 /*Character Size*/
#define UCSRB_RXB8	          1                 /*Receive Data Bit 8*/
#define UCSRB_TXB8		      0                /*Transmit Data Bit 8*/

#define UCSRC       *((uint8*)0x40)
#define UCSRC_URSEL           7
#define UCSRC_UMSEL          6
#define UCSRC_UPM1            5
#define UCSRC_UPM0            4
#define UCSRC_USBS            3              /* Stop Bit Select*/
#define UCSRC_UCSZ1           2              /*Character Size*/
#define UCSRC_UCSZ0           1              /*Character Size*/
#define UCSRC_UCSRC_UCPOL		0

#define UBRRL      *((volatile uint8*)0x29)
#define UBRRH           * ((volatile u8 *) 0X40)
#define UBRRH_URSEL		7


#endif
