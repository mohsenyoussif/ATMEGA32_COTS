/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: TWI               **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_interface.h"


void TWI_voidInitMaster(uint8 Copy_uint8Address)
{
	/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
	/*1- Set TWBR to 2 => [0:255] */
	TWBR =2 ;
	/*2- Clear the 2 bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	/*Initialize the node address*/
	if(Copy_uint8Address !=0)
	{
		TWAR =Copy_uint8Address <<1;
	}

	/*Enable the acknowledge bit from the master after receiving the data*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}
void TWI_voidInitSlave(uint8 Copy_uint8Address)
{
	/*Initialize the node address*/
	TWAR =Copy_uint8Address <<1;

	/*Enable the acknowledge bit from the master after receiving the data*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);

}

TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError ;

	/*Send Start condition on the bus : TWSTA: TWI START Condition Bit*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previos operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again to indicate the previous operation is complete */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status (Bit Masking) , Note : i interesed in the 5 MSB*/
	if((TWSR & 0xF8) != START_ACK)
	{
		Local_ErrStatus = StartConditionErr ;

	}

	return Local_ErrStatus ;
}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError ;

	/*Send Start condition on the bus : TWSTA: TWI START Condition Bit*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previos operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again to indicate the previous operation is complete */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status (Bit Masking) , Note : iI interesed in the 5 MSB so i masked with 0xF8**/
	if((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_ErrStatus = RepeatedStartError ;

	}

	return Local_ErrStatus ;
}
TWI_ErrStatus TWI_SendSlaveAddressWithWrite(uint8 Copy_uint8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoError ;

	/*Clear the start condition bit as the data sheet tells */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Send THE slave address in the 7MSB in the data register */
	TWDR = Copy_uint8SlaveAddress <<1 ;
	CLR_BIT(TWDR,0);   /*for write request*/

	/*Clear the interrupt flag to start the previos operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again to indicate the previous operation is complete */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status (Bit Masking) , Note : I interesed in the 5 MSB so i masked with 0xF8**/
	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrStatus = SlaveAddressWithWriteErr ;

	}

	return Local_ErrStatus ;
}
TWI_ErrStatus TWI_SendSlaveAddressWithRead(uint8 Copy_uint8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoError ;

	/*Clear the start condition bit as the data sheet tells */
	CLR_BIT(TWCR,TWCR_TWSTA);
	/*Send THE slave address in the 7MSB in the data register  */
	TWDR = Copy_uint8SlaveAddress <<1 ;
	SET_BIT(TWDR,0);             /*for reed request*/

	/*Clear the interrupt flag to start the previos operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again to indicate the previous operation is complete */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status (Bit Masking) , Note :  I interesed in the 5 MSB so i masked with 0xF8*/
	if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK )
	{
		Local_ErrStatus = SlaveAddressWithReadErr ;

	}

	return Local_ErrStatus ;
}
TWI_ErrStatus TWI_MasterWriteDataByte(uint8 Copy_uint8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError ;

	/*Write the data byte*/
	TWDR = Copy_uint8DataByte ;

	/*Clear the interrupt flag to start the previos operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again to indicate the previous operation is complete */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status (Bit Masking) , Note :  I interesed in the 5 MSB so i masked with 0xF8*/
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK )
	{
		Local_ErrStatus = MasterWriteByteErr ;

	}

	return Local_ErrStatus ;
}
TWI_ErrStatus TWI_MasterReadDataByte(uint8* Copy_puint8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError ;

	/*Clear the interrupt flag to start the slave sending data */
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again to indicate the previous operation is complete */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status (Bit Masking) , Note :  I interesed in the 5 MSB so i masked with 0xF8*/
	if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK )
	{
		Local_ErrStatus = MasterReadByteErr ;
	}else
	{
		*Copy_puint8DataByte = TWDR ;
	}
	return Local_ErrStatus ;
}



void TWI_SendStopCondition(void)
{

	/*Send stop condition on the bus : TWSTO: TWI STOP Condition Bit*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*Clear the interrupt flag to start the previos operation */
	SET_BIT(TWCR,TWCR_TWINT);

}
