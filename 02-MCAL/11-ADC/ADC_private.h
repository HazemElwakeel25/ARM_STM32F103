/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  03 October 2020            */
/*****************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


typedef struct 
{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR1;
	volatile u32 SMPR2;
	volatile u32 JOFR1;
	volatile u32 JOFR2;
	volatile u32 JOFR3;
	volatile u32 JOFR4;
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR1;
	volatile u32 SQR2;
	volatile u32 SQR3;
	volatile u32 JSQR;
	volatile u32 JDR1;
	volatile u32 JRD2;
	volatile u32 JDR3;
	volatile u32 JDR4;
	volatile u32 DR;
	
}ADC_TYPE;

#define ADC ((ADC_TYPE*) 0x 40012400)

#endif
