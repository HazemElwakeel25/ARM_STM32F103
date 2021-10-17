/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 19 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterpput (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;					// to shift it to 0 bit in register NVIC_ISER1
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}


void MNVIC_voidDisableInterpput(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;					// to shift it to 0 bit in register NVIC_ISER1
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}


void MNVIC_voidSetPendingFlag  (u8 Copy_u8IntNumber)
{
	// this function is use to set the pending flag of any interrupt to test it with out needing to activate the prephiral
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0  = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;					// to shift it to 0 bit in register NVIC_ISER1
		NVIC_ISPR1  = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0  = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;					// to shift it to 0 bit in register NVIC_ISER1
		NVIC_ICPR1  = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 local_ActiveFlag_Statues;
	if (Copy_u8IntNumber <= 31)
	{
		local_ActiveFlag_Statues = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;					// to shift it to 0 bit in register NVIC_ISER1
		local_ActiveFlag_Statues = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else
	{
		/* return error */
		local_ActiveFlag_Statues = 2;
	}
	
	return local_ActiveFlag_Statues;
}


void MNVIC_voidSCBInit(void)
{
			/*		Application interrupt and reset control register ADDRESSES 	*/
	#define SCB_AIRCR 			 *((volatile u32 *)(0X0000000C + SCB_BASE_ADDRESS))
	#define SCB_BASE_ADDRESS 			0xE000ED00
	SCB_AIRCR = MNVIC_NumGroupSub;

}


void MNVIC_voidSetPriority (NVIC_PriorityInit * PriorityInit)
{
	u32 local_u8Priority = PriorityInit->Copy_u8SubGroupPriority | (PriorityInit->Copy_u8GroupPriority << ((PriorityInit->copy_u32NumGroupSub - 0x05FA0300) / 0x100));     // for Seting the priority in the IPR
	
	if (PriorityInit->Copy_s8IntNumber >= 0) /* External preipheral */
	{
		NVIC_IPR[PriorityInit->Copy_s8IntNumber] = (local_u8Priority << 4); // Shift 4 because The processor implements only bits[7:4] of each field
	}
	else /* Core preipheral */
	{
		
	}
}
