/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  HAL            **************/
/***********   SWC: CLCD              **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "Platform_Types.h"
#include <util/delay.h>

/* DIO_interface.h is the only file I exported to another components*/
#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

/*8bit initialization*/
void CLCD_voidInit(void)
{

	/*Wait for more than 30ms after VDD rises to 4.5V*/
	_delay_ms(40);

	/*function set --> RS =0 so it is a command
	 *RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
	 *0   0   0    0   1   1   N   F   X   X
	 *N--> NO of lines which I want to write (0-->1 line or 1-->2 lines)
	 *F-->Font size       5*8 or 5*11 including cursor    (0-->5*8   1--> 5*11)
	 *
	 *Function set command:  2 Lines    5*8 Font size */

	CLCD_voidSendCommand(0b00111000);

	/*Display ON/OFF control
	 *RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
	 *0   0   0    0  0   0    1   D   C   B
	 *D-->Display(screen) enable .  (0-->disable ,1-->enable).
	 *C-->cursor enable     (0->disable , 1-->enable)
	 *B-->Blink cursor  (0->no blink , 1-->blink)
	 *
	 *D = 1    Display(screen) enable
	 *C =0    cursor disable
	 *B=0     no blink cursor        */

	CLCD_voidSendCommand(0b00001100);

	/*clear Display */
	CLCD_voidSendCommand(1);


}
/* This function used to send command to LCD */
void CLCD_voidSendCommand(uint8 copy_uint8Command)
{
	/*Set RS pin to low to send command */
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_RS_PIN,DIO_uint8PIN_LOW);

	/*Set R/W to low to write */
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_RW_PIN,DIO_uint8PIN_LOW);

	/*Set command to data pins */
	DIO_uint8SetPortValue(CLCD_DATA_PORT,copy_uint8Command);

	/*Send enable pulse */
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_EN_PIN,DIO_uint8PIN_HIGH);
	_delay_ms(2);
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_EN_PIN,DIO_uint8PIN_LOW);

}

/* This function used to send Data to LCD */
void CLCD_voidSendData(uint8 copy_uint8Data)
{
	/*Set RS pin to high to send data */
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_RS_PIN,DIO_uint8PIN_HIGH);

	/*Set R/W to low to write */
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_RW_PIN,DIO_uint8PIN_LOW);

	/*Set Data  to data pins */
	DIO_uint8SetPortValue(CLCD_DATA_PORT,copy_uint8Data);

	/*Send enable pulse */
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_EN_PIN,DIO_uint8PIN_HIGH);
	_delay_ms(2);
	DIO_uint8SetPinValue(CLCD_CTR_PORT,CLCD_EN_PIN,DIO_uint8PIN_LOW);


}
/* This function used to send string Data  to LCD */
void CLCD_voidSendString(const char* copy_pcString)
{
	uint8 Local_uint8counter=0 ;
	while(copy_pcString[Local_uint8counter]!='\0')
	{
		CLCD_voidSendData(copy_pcString[Local_uint8counter]);
		Local_uint8counter++;
	}
}
/*Function used to specific location at LCD*/
CLCD_voidGoToXY(uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition)
{
	uint8 Local_uint8Address;
	if(Copy_uint8Xposition==0)
	{
		/*Location is at first line*/
		Local_uint8Address=Copy_uint8Yposition;
	}
	else if(Copy_uint8Xposition==1)
	{
		/*Location is at second line*/
		Local_uint8Address=0x40+Copy_uint8Yposition;
	}
	/*Now, my role to ask LCD to go to my address
	 *set bit 7 for set DDRAM Address command then send the command */
	CLCD_voidSendCommand(Local_uint8Address+128);
}

void CLCD_voidWriteSpecialCharacter(uint8* Copy_puint8Pattern,uint8 Copy_uint8PatternNumber,uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition )
{

	uint8 Local_uint8CGRAMAddress=0,Local_uint8Iterator;
	/*calculate the CGRAM address whose each block is 8 byte*/

	Local_uint8CGRAMAddress=Copy_uint8PatternNumber*8;
	/*Send CGRAM coomand to LCD , with setting bit 6 */
	CLCD_voidSendCommand(Local_uint8CGRAMAddress+64);

	/*Write pattern into CGRAM*/
	for(Local_uint8Iterator=0;Local_uint8Iterator<8;Local_uint8Iterator++)
	{
		CLCD_voidSendData(Copy_puint8Pattern[Local_uint8Iterator]);
	}
	/*Go back to DDRAM to display the pattern*/
	CLCD_voidGoToXY(Copy_uint8Xposition,Copy_uint8Yposition);

	/*Display the pattern written in the CGRAM*/
	CLCD_voidSendData(Copy_uint8PatternNumber);

}







