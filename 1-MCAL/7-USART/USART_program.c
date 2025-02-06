/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: USART               **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "USART_registers.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"

void USART_VoidInit(void)
{
	uint8 Local_uint8UCSRC =0;
   SET_BIT(Local_uint8UCSRC,UCSRC_URSEL); /* Setting bit7 for UCSRC */
   CLR_BIT(Local_uint8UCSRC,UCSRC_UMSEL); /* clear the  UMSEL bit for Asynchronous  mode of operation. */
   CLR_BIT(Local_uint8UCSRC,UCSRC_UPM1); /* clear the UPM1   for no parity */
   CLR_BIT(Local_uint8UCSRC,UCSRC_UPM0); /* clear the UPM0   for  no parity */

   /*This bit selects the number of Stop Bits to be inserted by the Transmitter. The Receiver
   ignores this setting.
     0 --> 1 bit
     1 --> 2 bit*/
  CLR_BIT(Local_uint8UCSRC,UCSRC_USBS);

   /*The UCSZ1:0 bits combined with the UCSZ2 bit in UCSRB sets the number of data bits
   (Character Size) in a frame the Receiver and Transmitter use.
     FOR 8 data bits */
   SET_BIT(Local_uint8UCSRC,UCSRC_UCSZ1);
   SET_BIT(Local_uint8UCSRC,UCSRC_UCSZ0);
   CLR_BIT(UCSRB,UCSRB_UCSZ2) ;
   UCSRC = Local_uint8UCSRC ;

     UBRRL = 6;                    // boud rate 9600 bps if fosc = 1.0000 MHz
   //UBRRL = 51;                  // boud rate 9600 bps if fosc = 8.0000 MHz
/*Enabling receiver and transmiter*/
SET_BIT(UCSRB,UCSRB_TXEN);
SET_BIT(UCSRB,UCSRB_RXEN);

}

/*This function sends Byte through UART */
void USART_voidSendData(uint8 Copy_uint8Data)
{
  while(GET_BIT(UCSRA,UCSRA_UDRE) ==0); // polling , wait until transmit buffer "UDR" is empty ( Read flag )

  /*Assign data to UDR Register to be sent using UART */
	UDR =Copy_uint8Data;


}

/*This function Receives Byte through UART */
uint8 USART_uint8ReceiveData(void)
{  
while(GET_BIT(UCSRA,UCSRA_RXC)==0); //  polling , wait until receiving data

  return UDR ;
}

