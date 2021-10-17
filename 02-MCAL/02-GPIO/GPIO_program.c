/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 19 Aug 2020       ************/
/* *********** version   : V02               ************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
		case GPIOA :
		{
			if (copy_u8Pin <= 7)												/* check if to use CRL[0-7] or CRH[8-15] */ 
			{
				GPIOA_CRL &= ~((0b1111)      << (copy_u8Pin * 4));               /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits */
				GPIOA_CRL |=  ((copy_u8Mode) << (copy_u8Pin * 4));				/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits */
				break ;
			}
			else if ( copy_u8Pin <= 15)											/* check if to use CRL[0-7] or CRH[8-15] */ 
			{
				GPIOA_CRH  &= ~((0b1111)      << ((copy_u8Pin - 8) * 4));       /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				GPIOA_CRH  |=  ((copy_u8Mode) << ((copy_u8Pin - 8) * 4));		/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				break ;
			}
			else
			{
				/* error wrong pin */
				break ;
			}
		}
		case GPIOB :
		{
			if (copy_u8Pin <= 7)												/* check if to use CRL[0-7] or CRH[8-15] */ 
			{
				GPIOB_CRL &= ~((0b1111)      << (copy_u8Pin * 4));               /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits */
				GPIOB_CRL |=  ((copy_u8Mode) << (copy_u8Pin * 4));				/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits */
				break ;
			}
			else if (copy_u8Pin <= 15)											/* check if to use CRL[0-7] or CRH[8-15] */ 
			{
				GPIOB_CRH  &= ~((0b1111)      << ((copy_u8Pin - 8) * 4));       /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				GPIOB_CRH  |=  ((copy_u8Mode) << ((copy_u8Pin - 8) * 4));		/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				break ;
			}
			else
			{
				/* error wrong pin */
				break ;
			}
		}
		case GPIOC :
		{
			
			if (copy_u8Pin <= 13)												/* check if to use CRL[0-7] or CRH[8-15] */ 
			{
				/* error PORT C ONLY [13 - 15] */
				break ;
			}
			else if (copy_u8Pin <= 15 && copy_u8Pin >= 13)							/* check if to use CRL[0-7] or CRH[8-15] */ 
			{
				GPIOB_CRH  &= ~((0b1111)      << ((copy_u8Pin - 8) * 4));       /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				GPIOB_CRH  |=  ((copy_u8Mode) << ((copy_u8Pin - 8) * 4));		/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				break ;
			}
			else
			{
				/* error wrong pin */
				break ;
			}
		}
		default:
		{
			/* error Wrong port */
		}
	}

}


void MGPIO_voidSetPinRangeDirection(u8 copy_u8Port, u8 copy_u8StartPin, u8 copy_u8EndPin, u8 copy_u8Mode)
{
	u8 local_u8pin;
	if (copy_u8StartPin > copy_u8EndPin)
		{
			copy_u8StartPin ^= copy_u8EndPin;
			copy_u8EndPin   ^= copy_u8StartPin;
			copy_u8StartPin ^= copy_u8EndPin;
		}
	
	
	switch(copy_u8Port)
	{
		case GPIOA :
		{
			for (local_u8pin = copy_u8StartPin; local_u8pin <= copy_u8EndPin; local_u8pin++)
			{
				if (local_u8pin <= 7)												/* check if to use CRL[0-7] or CRH[8-15] */ 
				{
					GPIOA_CRL &= ~((0b1111)      << (local_u8pin * 4));               /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits */
					GPIOA_CRL |=  ((copy_u8Mode) << (local_u8pin * 4));				/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits */
				}
				else if (local_u8pin  <= 15)											/* check if to use CRL[0-7] or CRH[8-15] */ 
				{
					GPIOA_CRH  &= ~((0b1111)      << ((local_u8pin - 8) * 4));       /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
					GPIOA_CRH  |=  ((copy_u8Mode) << ((local_u8pin - 8) * 4));		/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				}
				else
				{
					/* error wrong pin */
					break ;
				}
			}
			break ;
		}
		case GPIOB :
		{
			for (local_u8pin = copy_u8StartPin; local_u8pin <= copy_u8EndPin; local_u8pin++)
			{
				if (local_u8pin <= 7)												/* check if to use CRL[0-7] or CRH[8-15] */ 
				{
					GPIOB_CRL &= ~((0b1111)      << (local_u8pin * 4));               /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits */
					GPIOB_CRL |=  ((copy_u8Mode) << (local_u8pin * 4));				/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits */
				}
				else if (local_u8pin  <= 15)											/* check if to use CRL[0-7] or CRH[8-15] */ 
				{
					GPIOB_CRH  &= ~((0b1111)      << ((local_u8pin - 8) * 4));       /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
					GPIOB_CRH  |=  ((copy_u8Mode) << ((local_u8pin - 8) * 4));		/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				}
				else
				{
					/* error wrong pin */
					break ;
				}
			}
			break ;
		}
		case GPIOC :
		{
			for (local_u8pin = copy_u8StartPin; local_u8pin <= copy_u8EndPin; local_u8pin++)
			{
				if (local_u8pin <= 7)												/* check if to use CRL[0-7] or CRH[8-15] */ 
				{
					GPIOC_CRL &= ~((0b1111)      << (local_u8pin * 4));               /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits */
					GPIOC_CRL |=  ((copy_u8Mode) << (local_u8pin * 4));				/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits */
				}
				else if (local_u8pin  <= 15)											/* check if to use CRL[0-7] or CRH[8-15] */ 
				{
					GPIOC_CRH  &= ~((0b1111)      << ((local_u8pin - 8) * 4));       /* clearing the 4 bit first before setting multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
					GPIOC_CRH  |=  ((copy_u8Mode) << ((local_u8pin - 8) * 4));		/* setting the 4 as the reqired mode multiple by 4 to shift each bin by 4 bits minus 8 because the CRH Strat from 0 not 8 */
				}
				else
				{
					/* error wrong pin */
					break ;
				}
			}
			break ;
		}
		default:
		{
			/* error Wrong port */
		}
	}

}


void MGPIO_voidSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	if (copy_u8Pin <= 15)								/* check pin */ 
	{
		switch(copy_u8Port)
		{
			case GPIOA :
			{
				if (copy_u8Value == LOW)
				{
					//CLR_BIT(GPIOA_ODR, copy_u8Pin); /* Using ODR  */
					GPIOA_BRR = (1 << copy_u8Pin);    /* Using BRR  */
					break ;
				}
				else if (copy_u8Value == HIGH)
				{
					//SET_BIT(GPIOA_ODR, copy_u8Pin); /* Using ODR  */
					GPIOA_BSRR = (1 << copy_u8Pin);    /* Using BSRR */
					break ;
				}
				else 
				{
					 // error wrong value
					break ;
				}
	
			}
			case GPIOB :
			{
				if (copy_u8Value == LOW)
				{
					//CLR_BIT(GPIOB_ODR, copy_u8Pin); /* Using ODR  */
					GPIOB_BRR = (1 << copy_u8Pin);    /* Using BRR  */
					break ;
				}
				else if (copy_u8Value == HIGH)
				{
					//SET_BIT(GPIOB_ODR, copy_u8Pin); /* Using ODR  */
					GPIOB_BSRR = (1 << copy_u8Pin);    /* Using BSRR */
					break ;
				}
				else 
				{
					 // error wrong value
					break ;
				}
			}
			case GPIOC :
			{
				if (copy_u8Value == LOW)
				{
					//CLR_BIT(GPIOC_ODR, copy_u8Pin); /* Using ODR  */
					GPIOC_BRR = (1 << copy_u8Pin);    /* Using BRR  */
					break ;
				}
				else if (copy_u8Value == HIGH)
				{
					//SET_BIT(GPIOB_ODR, copy_u8Pin); /* Using ODR  */
					GPIOC_BSRR = (1 << copy_u8Pin);    /* Using BSRR */
					break ;
				}
				else 
				{
					 // error wrong value
					break ;
				}
				
			}
			default:
			{
				/* error Wrong port */
			}
		}
	}
}


u8 MGPIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 local_u8Result = 0;
	switch(copy_u8Port)
	{
		case GPIOA :
		{
			local_u8Result = GET_BIT(GPIOA_IDR, copy_u8Pin);
			break ;
		}
		case GPIOB :
		{
			local_u8Result = GET_BIT(GPIOA_IDR, copy_u8Pin);
			break ;
		}
		case GPIOC :
		{
			local_u8Result = GET_BIT(GPIOA_IDR, copy_u8Pin);
			break ;
		}
		default:
		{
			/* error Wrong port */
		}
	}
	return local_u8Result;
}
