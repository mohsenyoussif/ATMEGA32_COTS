/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  HAL            **************/
/***********   SWC: CLCD              **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
#ifndef  CLCD_CONFIG_H_
#define  CLCD_CONFIG_H_

/*                 pre_build_config
   This file , user can modify any configiration
   any editing will affect directly program.c
   This is the only file , user can modify it*/
   
#define CLCD_DATA_PORT           DIO_uint8PORTA

#define CLCD_CTR_PORT            DIO_uint8PORTC
#define CLCD_RS_PIN              DIO_uint8PIN0
#define CLCD_RW_PIN              DIO_uint8PIN1
#define CLCD_EN_PIN              DIO_uint8PIN2









#endif
