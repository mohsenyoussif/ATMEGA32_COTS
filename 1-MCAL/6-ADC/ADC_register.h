/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  *************/
/***********   layer:  MCAL            *************/
/***********   SWC: ADC                *************/
/***********   Version: 1.00           *************/
/***************************************************/
/***************************************************/

#ifndef  ADC_REGISTER_H
#define  ADC_REGISTER_H

#define ADMUX                   *((volatile uint8*)0x27)  //ADC multiplexer register
#define ADMUX_REF1                    7                 //Reference selection bit1
#define ADMUX_REF0                    6                 //Reference selection bit0
#define ADMUX_ADLAR                   5                 //ADC left adjust result

#define ADCSRA                 *((volatile uint8*)0x26) //ADC control and status register A
#define ADCSRA_ADEN                   7                //ADC enable
#define ADCSRA_ADSC                   6                //start conversion
#define ADCSRA_ADATE                  5                //Auto trigger enable
#define ADCSRA_ADIF                   4                //Interrupt Flag
#define ADCSRA_ADIE                   3                //Interrupt Enable
#define ADCSRA_ADPS2                  2                //Prescaler Select Bit2
#define ADCSRA_ADPS1                  1                //Prescaler Select Bit1
#define ADCSRA_ADPS0                  0                //Prescaler Select Bit0
#define ADCH                   *((volatile uint8*)0x25) //ADC Data high register
#define ADCL                   *((volatile uint8*)0x24) //ADC Data Low register




#endif
