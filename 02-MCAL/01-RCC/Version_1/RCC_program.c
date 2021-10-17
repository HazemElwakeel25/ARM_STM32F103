/******************************************************************************************************************************/
/* Auther    : Hazem El-Wakeel                                                                                                */
/* Date      : 08 Aug 2020                                                                                                    */
/* version   : V01                                                                                                            */
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
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,copy_u8PerId);	break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,copy_u8PerId);	break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,copy_u8PerId);	break;
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
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,copy_u8PerId);	break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,copy_u8PerId);	break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,copy_u8PerId);	break;
			//default       :  /* return error */                 break;
		}
	}
	else
	{
	  /* return error */
	}
}

void MRCC_voidInitSysClock (void)
{	
	# if  RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL 
		RCC_CR   = 0x00010000; /* HSE Crystal ENabled*/
		RCC_CFGR = 0X00000001; 
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000;                      /* HSI RC ENabled */
		RCC_CFGR = 0X00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081;                      /* HSI ENabled + Triming = 0*/
		RCC_CFGR = 0X00000000;	
	#elif RCC_CLOCK_TYPE == RCC_PLL
		# if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CFGR = 0X00000001                   /* set up HSI/2  */
			RCC_CFGR |=  (17 << (RCC_PLL_MUL_VAL))) /* set prescaler */
			RCC_CR   = 0x01000000                   /* PLL ENabled   */
		# elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CFGR = 0X00030001                   /* set up HSE/2  */
			RCC_CFGR |=  (17 << (RCC_PLL_MUL_VAL))) /* set prescaler */
			RCC_CR   = 0x01000000                   /* PLL ENabled   */
		# elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CFGR = 0X00010001                   /* set up HSe    */
			RCC_CFGR |=  (17 << (RCC_PLL_MUL_VAL))) /* set prescaler */
			RCC_CR   = 0x01000000                   /* PLL ENabled   */
		# else 
			#error("you choose wrong clock type")
		#endif
	#else
		#error("you choose wrong clock type")
	
	#endif
}






