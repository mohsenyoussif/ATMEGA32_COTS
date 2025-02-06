/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: TWI               **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

/* Error Status fot TWI */
typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	SlaveWriteByteErr,
	SlaveReadByteErr,

}TWI_ErrStatus;


/*Set master address to 0 if master will not be addressed*/
void TWI_voidInitMaster(uint8 Copy_uint8Address);

void TWI_voidInitSlave(uint8 Copy_uint8Address);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(uint8 Copy_uint8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(uint8 Copy_uint8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(uint8 Copy_uint8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(uint8* Copy_puint8DataByte);



void TWI_SendStopCondition(void);

#endif
