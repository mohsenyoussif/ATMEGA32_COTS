/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: DIO                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*some macros to communicate with user to tell him how pass the parameters to functions */



//To set the value of the pin
#define DIO_uint8PIN_HIGH         1
#define DIO_uint8PIN_LOW          0

//To set the value of the port
#define DIO_uint8PORT_HIGH       0xFF
#define DIO_uint8PORT_LOW        0

#define DIO_uint8PORTA            0
#define DIO_uint8PORTB            1
#define DIO_uint8PORTC            2
#define DIO_uint8PORTD            3

#define DIO_uint8PIN0             0
#define DIO_uint8PIN1             1
#define DIO_uint8PIN2             2
#define DIO_uint8PIN3             3
#define DIO_uint8PIN4             4
#define DIO_uint8PIN5             5
#define DIO_uint8PIN6             6
#define DIO_uint8PIN7             7



uint8 DIO_uint8SetPinValue(uint8 Copy_uint8Port,uint8 Copy_uint8Pin,uint8 Copy_uint8Value);

uint8 DIO_uint8SetPortValue(uint8 Copy_uint8Port,uint8 Copy_uint8Value);

// Function used to read a value at input pin
uint8 DIO_uint8GetPinValue(uint8 Copy_uint8Port,uint8 Copy_uint8Pin,uint8* Copy_Puint8Value);




#endif
