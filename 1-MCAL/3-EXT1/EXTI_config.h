/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: EXTI                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

/* Options :
     1-EXTI_LOW_LEVEL_SENCE_CONTROL
     2- EXTI_ONCHANGE_SENCE_CONTROL
     3-EXTI_FALLING_EDGE_SENCE_CONTROL
     4- EXTI_RISING_EDGE_SENCE_CONTROL
      */
#define   INT0_SENSE_CONTROL      EXTI_FALLING_EDGE_SENCE_CONTROL

/* Options :
     1-EXTI_LOW_LEVEL_SENCE_CONTROL
     2- EXTI_ONCHANGE_SENCE_CONTROL
     3-EXTI_FALLING_EDGE_SENCE_CONTROL
     4- EXTI_RISING_EDGE_SENCE_CONTROL
      */
#define   INT1_SENSE_CONTROL      EXTI_FALLING_EDGE_SENCE_CONTROL

/* Options :
     3-EXTI_FALLING_EDGE_SENCE_CONTROL
     4- EXTI_RISING_EDGE_SENCE_CONTROL
      */
#define   INT2_SENSE_CONTROL      EXTI_FALLING_EDGE_SENCE_CONTROL
/* Options :
   1-ENABLED
   2-DISABLED
   */

//=======================================================================

#define  INT0_INITIAL_STATE          ENABLED
#define  INT1_INITIAL_STATE          ENABLED
#define  INT2_INITIAL_STATE          ENABLED

