/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  31 March 2020              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "STK_interface.h"


void MADC_voidInitContConv( u8 u8_copyChannelNumber)
{
	
	if ( u8_copyChannelNumber < 10 ) 										/* Check wether to use SMPR1 or SMPR1*/
	{
		ADC -> SMPR2 |= (ADC_PRESCALER << (u8_copyChannelNumber *3)); 		/* Setting the prescaler*/
	}
	else 
	{
		ADC -> SMPR1 |= (ADC_PRESCALER << ((u8_copyChannelNumber-10) *3));	/* Setting the prescaler   we use -10 because SMPR start with channel 10*/
	}
	
	
	ADC -> SQR1 = 0 ;														/* set the total number of channel used to 1*/			
	ADC -> SQR3 = u8_copyChannelNumber;										/* set the conversion sequance to the first*/

	
	SET_BIT(ADC -> CR2, 0); 												/* Turn the ADC on for the first time */
	SET_BIT(ADC -> CR2, 1); 												/* Set ADC to continus Mode*/
	MSTK_Delay(1000);														/* Waiting for ADC to Stablize*/
	
	SET_BIT(ADC -> CR2, 0); 												/* Turn the ADC on for the seconed time */
	MSTK_Delay(1000);														/* Waiting for ADC to Stablize*/
	
	SET_BIT(ADC -> CR2, 2); 												/* Calibrating the ADC */
	while(GET_BIT(ADC -> CR2, 2));											/* waiting for the calibration */
	
	
}

u16 MADC_u16GetPinValue(u8 u8_copyChannelNumber)
{
	return ADC -> DR;
}