/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: SPI               **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_register.h"
void SPI_InitMaster(void)
{
	/*Select the Master*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*Data order*/
	CLR_BIT(SPCR,SPCR_DORD);

	/*Clock Polarity & Clock phase --> keer it @ default as in data sheet*/

	/*PreScaler : division by 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_InitSlave(void)
{
	/*Select the Slave*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*Data order*/
	CLR_BIT(SPCR,SPCR_DORD);

	/*Clock Polarity & Clock phase --> keer it @ default as in data sheet*/

	
	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}

uint8 SPI_uint8Transceve(uint8 copy_uint8Data)
{
   /* Write data to SPI data register to initiate transmission */
    SPDR = copy_uint8Data;

    /* Wait until the transmission is complete (SPIF set) */
    while(GET_BIT(SPSR,SPSR_SPIF)==0);

    /*Get the exchanged data*/
	return SPDR;
}
