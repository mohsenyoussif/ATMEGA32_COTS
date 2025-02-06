/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: EXTI                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
 #ifndef  EXTI_REGISTER_H_
 #define  EXTI_REGISTER_H_
 
 
 /*General Interrupt Control Register  GICR*/
 #define GICR              *((volatile uint8*)0x5B)
#define GICR_INT1               7
#define GICR_INT0               6
#define GICR_INT2               5


/*The MCU Control Register contains control bits for interrupt sense control and general
  MCU functions for INT0 ,INT1 .                                                                         */
 #define MCUCR            *((volatile uint8*)0x55)
 #define MCUCR_ISC11            3
 #define MCUCR_ISC10            2
 #define MCUCR_ISC01            1
 #define MCUCR_ISC00            0

/*MCU Control and Status Register for INT2 – MCUCSR*/

 #define  MCUCSR           *((volatile uint8*)0x54)
 #define  MCUCSR_INT2           6

 /*General Interrupt FlagRegister “ GIFR*/
 #define  GIFR             *((volatile uint8*)0x5A)
  
 
 
 
 
 
 
 #endif
