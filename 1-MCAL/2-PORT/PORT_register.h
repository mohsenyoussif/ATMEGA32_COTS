/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: PORT                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/



#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

/*We want to set direction so we are interested in DDR registers*/

#define DDRA       *((vuint8_t*)0X3A)
#define DDRB       *((vuint8_t*)0X37)
#define DDRC       *((vuint8_t*)0X34)
#define DDRD       *((vuint8_t*)0X31)

#define PORTA      *((vuint8_t*)0x3B)  
#define PORTB      *((vuint8_t*)0X38)
#define PORTC      *((vuint8_t*)0X35)
#define PORTD      *((vuint8_t*)0X32)

#endif