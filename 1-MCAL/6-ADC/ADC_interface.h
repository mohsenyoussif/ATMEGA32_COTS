/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: ADC                *************/
/***********   Version: 1.00           *************/
/***************************************************/
/***************************************************/


#ifndef  ADC_INTERFACE_H
#define  ADC_INTERFACE_H
#define ADC_PRE_2               0
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7



void ADC_voidInit(void);

uint8 ADC_uint8GetChannelReadingSynch(uint8 copy_uint8channel,uint8* Copy_pu8Rading);


// Before use this function you should Enable global interrupt
uint8 ADC_u8StartConversionAsynch (uint8 Copy_uint8Channel , uint8 * Copy_pu8Rading , void (*Copy_pvNotificationFunc)(void));



#endif
