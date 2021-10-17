/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  03 October 2020            */
/*****************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3
#define ADC4  4
#define ADC5  5
#define ADC6  6
#define ADC7  7
#define ADC8  8
#define ADC9  9



void MADC_voidInitContConv( u8 u8_copyChannelNumber);
u16 MADC_u16GetPinValue(u8 u8_copyChannelNumber);

#endif