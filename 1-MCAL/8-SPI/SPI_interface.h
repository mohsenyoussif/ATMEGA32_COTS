/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: SPI               **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef SPI_INTERGACE_H_
#define SPI_INTERGACE_H_

void SPI_InitMaster(void);

void SPI_InitSlave(void);

/*
 * This function simultaneously sends and receives a byte over SPI.
 * The input data is written to the SPDR register to initiate transmission to the SPI slave.
 * The function waits until the transmission is complete by monitoring the SPIF flag.
 * After the transmission, the received data from the slave is read from the SPDR register and returned.
 */
uint8 SPI_uint8Transceve(uint8 copy_uint8Data);

#endif
