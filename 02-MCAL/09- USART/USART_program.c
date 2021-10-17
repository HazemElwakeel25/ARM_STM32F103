/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 17 March  2021              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "string.h"
#include "stdlib.h"
#include "stdarg.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

u8 * USART_u8PtrReceiveData;

void MUSART1_voidInit(void)
{
	USART1 -> CR1 = 0;
	USART1 -> CR2 = 0;
	USART1 -> CR3 = 0;
	

	#if FRAME_SIZE == 1
		SET_BIT(USART1 -> CR1,12); 		/*1 Start bit, 9 Data bits, n Stop bit*/
	#endif
	
	#if PARITY_CONTROL_ENABLE == 1
		SET_BIT(USART1 -> CR1,10); 		/* Parity control enabled*/
	#endif
	
	#if PARITY_SELECTION == 1
		SET_BIT(USART1 -> CR1,9); 		/* Odd parity */
	#endif
	
	#if PARITY_ERROE_INTERRUP == 1
		SET_BIT(USART1 -> CR1,8); 		/* A USART interrupt is generated whenever PE=1 in the USART_SR register */
	#endif
	
	#if TX_REGISTER_EMPTY_INTERRUPT == 1
		SET_BIT(USART1 -> CR1,7); 		/* A USART interrupt is generated whenever TXE=1 in the USART_SR register  */
	#endif
	
	#if TX_COMPLETE_INTERRUPT == 1
		SET_BIT(USART1 -> CR1,7); 		/* A USART interrupt is generated whenever TC=1 in the USART_SR register  */
	#endif
	
	
	#if IDLE_LINE_INTERRUPT == 1
		SET_BIT(USART1 -> CR1,4); 		/* A USART interrupt is generated whenever IDLE=1 in the USART_SR register  */
	#endif
	
	USART1 -> CR2 |= (STOP_BIT_NUMBER << 12);
	
	SET_BIT(USART1 -> CR1,5); 			/* A USART interrupt is generated whenever RXNE=1 in the USART_SR register  */
	
	SET_BIT(USART1 -> CR1,2);    		/* Receiver enable */
	
	SET_BIT(USART1 -> CR1,3);     		/* Transmitter enable */
	
	SET_BIT(USART1 -> CR1,13);    		/* USART enable */

	USART1 -> SR = 0 ;					/* Clear Status Register */
	
	
	
	
	
}

void MUSART1_voidBaudRateInit(u32 copy_u32BaudRate)
{
	u16 Local_u16Mantissa;
	u8  local_u8Fraction;
	u32 Local_u32frequancy ;
	if (Frequancy_Prescaler == 2)
	{
		Local_u32frequancy = Frequancy/2;
	}
	else
	{
		Local_u32frequancy = Frequancy;
	}
	
	Local_u16Mantissa = (Local_u32frequancy / (16 * copy_u32BaudRate));
	Local_u16Mantissa = (Local_u16Mantissa << 4);

	local_u8Fraction = (((Local_u32frequancy % (16 * copy_u32BaudRate))*10) / (copy_u32BaudRate)) ;

    if ((local_u8Fraction % 10) >= 5)
    {
        local_u8Fraction = (local_u8Fraction / 10) + 1 ;
    }
    else
    {
        local_u8Fraction = (local_u8Fraction / 10);
    }

    USART1 -> BRR = (Local_u16Mantissa + local_u8Fraction) ;
	
}


void MUSART1_voidTransmit(u16 *Copy_u8DataPtr, ...)
{
	u8 Local_u8Reformated_string[80] ;
	u8 Local_u8Counter = 0 ;

	va_list list;

	va_start (list, Copy_u8DataPtr);
	vsprintf(Local_u8Reformated_string, Copy_u8DataPtr, list);

	for( Local_u8Counter = 0 ;  Local_u8Counter < strlen(Local_u8Reformated_string) ; Local_u8Counter ++)
	{
		USART1 -> DR = Local_u8Reformated_string [Local_u8Counter];	/* Sending the Character*/
		while (GET_BIT(USART1 -> SR, 6) == 0);				/* Wait till transition complete */
	}
}

void MUSART1_u8Receive(u8 * copy_u8DataToReceive)
{
		USART_u8PtrReceiveData = copy_u8DataToReceive ;
		
}

void USART1_IQRHandler()
{
	if (GET_BIT(USART1 -> SR, 5) == 1)
	{
		if (FRAME_SIZE == 1)								/* 9 bits Data */
		{
			* USART_u8PtrReceiveData = (0X1FF & (USART1 -> DR));				// return the Requiered 9 bits only
		}
		else												/* 8 bits Data */
		{
			* USART_u8PtrReceiveData = (0XFF & (USART1 -> DR));					// return the Requiered 8 bits only
		}
	}
	
}

