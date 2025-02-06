/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: EXTI                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef  EXTI_INTERFACE_H_
#define  EXTI_INTERFACE_H_
 
 
/*Don't choose 0 as configuration option to avoid undefined behavior */
#define  EXTI_LOW_LEVEL_SENCE_CONTROL            1    /*LOW LEVEL SENSE CONTROL */
#define  EXTI_ONCHANGE_SENCE_CONTROL             2    /*ON CHANGE SENSE CONTROL */
#define  EXTI_FALLING_EDGE_SENCE_CONTROL         3    /*FAILING EDGE SENSE CONTROL */
#define  EXTI_RISING_EDGE_SENCE_CONTROL          4    /*RISING EDGE SENSE CONTROL */

/*Input     : None
 Output     : None
 Desciption :A function to Initiate  INT0 by SET The sense and Enable peripheral interrupt enable  */
void EXTI_voidInt0Init(void);

/*Input     : None
 Output     : None
 Desciption :A function to Initiate  INT1 by SET The sense and Enable peripheral interrupt enable  */
void EXTI_voidInt1Init(void);
/*Input     : None
 Output     : None
 Desciption :A function to Initiate  INT2 by SET The sense and Enable peripheral interrupt enable  */
void EXTI_voidInt2Init(void);


//=======================================================================

/*Input : Copy_uint8Sense  , Options are :
                                      1-    EXTI_LOW_LEVEL_SENCE_CONTROL
                                      2-    EXTI_ONCHANGE_SENCE_CONTROL
                                      3-    EXTI_FALLING_EDGE_SENCE_CONTROL
                                      4-    EXTI_RISING_EDGE_SENCE_CONTROL
 Output  : Error status with type uint8

 *Desciption :A function to set the required sense Control of INT0 using postbuild configuration */
uint8 EXTI_uint8Int0SetSenseControl(uint8 Copy_uint8Sense );

uint8 EXTI_uint8Int1SetSenseControl(uint8 Copy_uint8Sense );

uint8 EXTI_uint8Int2SetSenseControl(uint8 Copy_uint8Sense );

 
 /*pass which interrupt(int0 , int1 , int2) To enable */
uint8 EXTI_uint8IntEnable(uint8 Copy_uint8Int );

/*pass which interrupt(int0 , int1 , int2) To enable */
uint8 EXTI_uint8IntDisable(uint8 Copy_uint8Int );
 
//=======================================================================

/*Input :void(*Copy_pvInt0Func)(void)  : pointer to function
 Output  : Error status with type uint8

 *Descoprion :A function to set the address of the function the user want to run as ISR
               User will call this function to pass the address of his function   */
uint8 EXTI_uint8Int0SetCallBack(void(*Copy_pvInt0Func)(void));
 
 
 #endif
