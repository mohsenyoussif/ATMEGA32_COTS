/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: TIMER        **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef  TIMER_REGISTER_H
#define  TIMER_REGISTER_H

#define TCCR0        *((volatile uint8*)0x53)      /*Timer0 control register*/
#define TCCR0_WGM00       6                        /*Wave geerator Mode bit0*/
#define TCCR0_WGM01       3                        /*Wave geerator Mode bit1*/
#define TCCR0_COM01       5
#define TCCR0_COM00       4
#define TCCR0_CS02        2                        /*Prescaler bit2*/
#define TCCR0_CS01        1                        /*Prescaler bit1*/
#define TCCR0_CS00        0                        /*Prescaler bit0*/
												   
#define OCR0        *((volatile uint8*)0x5C)       /*Output compare register 0*/
												   
#define TIMSK       *((volatile uint8*)0x59)       /*Timer mask*/
#define TIMSK_OCIE0    1                           /*Output compare 0 interrupt enable */

#define TIFR       *((volatile uint8*)0x58)       
#define TIFR_OCF0     1                           

#endif