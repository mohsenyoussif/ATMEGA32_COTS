/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: SPI               **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

/* Registers Definition  */
#define SPCR				* ((volatile uint8 *)0X2D)    /*SPI control register*/
#define SPCR_SPIE			7                            /*SPI interupt enable*/
#define SPCR_SPE			6                            /*SPI enable*/
#define SPCR_DORD			5                            /*Data order to choose which bit written first LSB or MSB*/
#define SPCR_MSTR			4                            /* Master,Slave Select*/
#define SPCR_CPOL			3                            /* Clock Polarity*/
#define SPCR_CPHA			2                            /*Clock Phase*/
#define SPCR_SPR1			1                            /**/
#define SPCR_SPR0			0                            /**/

#define SPSR		    	* ((volatile uint8 *)0X2E)   /*SPI status register*/
#define SPSR_SPIF			7
#define SPSR_WCOL			6
#define SPSR_SPI2X			0

#define SPDR			    * ((volatile uint8 *)0X2F) /*SPI data register*/





#endif
