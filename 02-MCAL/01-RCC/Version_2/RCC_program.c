/******************************************************************************************************************************/
/* Auther    : Hazem El-Wakeel                                                                                                */
/* Date      : 24 Aug 2020                                                                                                    */
/* version   : V02                                                                                                            */
/******************************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidEnableClock (u8 copy_u8BusId, u8 copy_u8PerId)
{
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,copy_u8PerId);	break; // Enable perphiral on AHB bus
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,copy_u8PerId);	break; // Enable perphiral on APB1 bus
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,copy_u8PerId);	break; // Enable perphiral on APB2 bus
			//default       :  /* return error */                 break;
		}
	}
	else
	{
	  /* return error */
	}
}

void MRCC_voidDisableClock (u8 copy_u8BusId, u8 copy_u8PerId)
{
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,copy_u8PerId);	break;  // Disable perphiral on AHB bus
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,copy_u8PerId);	break;  // Disable perphiral on APB1 bus
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,copy_u8PerId);	break;  // Disable perphiral on APB2 bus
			//default       :  /* return error */                 break;
		}
	}
	else
	{
	  /* return error */
	}
}

void MRCC_voidInitSysClock (RCC_Clock_config *Clock_config)
{	
	if (Clock_config -> PLLEnable == 0)
	{	
		switch (Clock_config -> ClockType)
		{
			case RCC_HSE_CRYSTAL :
			{	
				RCC_CR = 0x00090000; 				/* HSE Crystal ENabled and clock security system. */
				RCC_CFGR = 0X00000001;
				RCC_CFGR |= (RCC_ADC_PRESCALER << 14 );	/* ADC Preascaler*/
				break;
			}
			case RCC_HSE_RC :
			{
				RCC_CR = 0x00050000; 				/* HSI RC ENabled and clock security system. */
				RCC_CFGR = 0X00000001;
				RCC_CFGR |= (RCC_ADC_PRESCALER << 14 );		/* ADC Preascaler*/
				break;
			}
			case RCC_HSI :
			{	
				RCC_CR = 0x00000081; 				/* HSI ENabled + Triming = 0 and clock security system. */
				RCC_CFGR = 0X00000000;
				RCC_CFGR |= (RCC_ADC_PRESCALER << 14 );	 	/* ADC Preascaler*/
				break;
			}	
			default:
			{
				//error("you choose wrong clock type.")
				break;
			}
		}
	}
	else if (Clock_config -> PLLEnable == 1)
	{
		switch (Clock_config -> PllValue)
		{
			case RCC_PLL_IN_HSI_DIV_2 :
			{	
				RCC_CFGR  = 0X00000002 ;                  /* set up HSI/2  */
				RCC_CFGR |=  ((Clock_config ->PllMULLVal - 2) << 18); /* set prescaler */
				RCC_CR    = 0X01000081; 
				break;
			}
			case RCC_PLL_IN_HSE_DIV_2 :
			{
				RCC_CFGR = 0X00030002  ;                 /* set up HSE/2  */
				RCC_CFGR |=  ((Clock_config ->PllMULLVal - 2) << 18); /* set prescaler */
				if (Clock_config -> ClockType == RCC_HSE_CRYSTAL)
				{
					RCC_CR   = 0x01010000 ;
					break;
				}
				else if (Clock_config -> ClockType == RCC_HSE_RC)
				{
					RCC_CR   = 0x01050000;
					break;
				}
				else
				{
					break;
				}
			}
			case RCC_PLL_IN_HSE :
			{	
				RCC_CFGR = 0X00010002 ;                  /* set up HSe    */
				RCC_CFGR |=  ((Clock_config ->PllMULLVal - 2) << 18); /* set prescaler */
				if (Clock_config -> ClockType == RCC_HSE_CRYSTAL)
				{
					RCC_CR   = 0x01010000 ;
					break;
				}
				else if (Clock_config -> ClockType == RCC_HSE_RC)
				{
					RCC_CR   = 0x01050000;
					break;
				}
				else
				{
					break;
				}
			}	
			default:
			{
				//error("you choose wrong clock type.")
				break;
			}
		}
	}
}





