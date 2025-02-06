/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  HAL            **************/
/***********   SWC: CLCD              **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
#ifndef  CLCD_INTERFACE_H_
#define  CLCD_INTERFACE_H_


void CLCD_voidInit(void);

/* This function used to send command to LCD */
void CLCD_voidSendCommand(uint8 copy_uint8Command);

/* This function used to send Data to LCD */
void CLCD_voidSendData(uint8 copy_uint8Data);

/*Function used to send string Data to LCD*/
void CLCD_voidSendString(const char* copy_pcString);

/*Function used to calculate the address with the help of x,y*/
void CLCD_voidGoToXY(uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition);

/*Function used to display special character at LCD*/
void CLCD_voidWriteSpecialCharacter(uint8* Copy_puint8Pattern,uint8 Copy_uint8PatternNumber,uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition );



#endif
