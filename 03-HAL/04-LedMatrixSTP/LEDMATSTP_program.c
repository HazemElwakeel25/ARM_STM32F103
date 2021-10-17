/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 25 feb 2021       ************/
/* *********** version   : V01               ************/
/********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

u16 Global_u16LedValue;
u8 Global_u8ColValueLOW;
u8 Global_u8RowValueHIGH;




void HLEDMAT_voidInit(void)
{
	MGPIO_VidSetPinDirection(HSTP_SERIAL_DATA ,OUTPUT_10MHZ_PP);
	MGPIO_VidSetPinDirection(HSTP_SHIFT_CLOCK ,OUTPUT_10MHZ_PP);
	MGPIO_VidSetPinDirection(HSTP_STORE_CLOCK ,OUTPUT_10MHZ_PP);
}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame, u8 copy_u8FrameLenght);
{
	
	/* Reset the frame Start */
	u8 HLEDMAT_u8CurrentIdx = 0; 
	u8 HLEDMAT_u8Icrementframe = 0;
	u8 HLEDMAT_u8DispalyValue = 0;
	

	/* Start timer */
	for (HLEDMAT_u8Icrementframe = 0; HLEDMAT_u8Icrementframe < (copy_u8FrameLenght-8); HLEDMAT_u8Icrementframe++)
	{
		for (HLEDMAT_u8CurrentIdx = 0; HLEDMAT_u8CurrentIdx < 8; HLEDMAT_u8CurrentIdx++)
		{
						/* Dislay The Column x */
			HLEDMAT_u8DispalyValue = HLEDMAT_u8CurrentIdx + HLEDMAT_u8Icrementframe ;
			setMatrixValue (HLEDMAT_u8CurrentIdx,Copy_u8Frame[HLEDMAT_u8DispalyValue]);
			MSTK_Delay(2000);
		}
	}
}


void HLEDMAT_voidDisplayFrameLoop(u8 *Copy_u8Frame, u8 copy_u8FrameLenght);
{
	
	/* Reset the frame Start */
	u8 HLEDMAT_u8CurrentIdx = 0; 
	u8 HLEDMAT_u8Icrementframe = 0;
	u8 HLEDMAT_u8DispalyValue = 0;
	

	/* Start timer */
	while(1)
	{
		for (HLEDMAT_u8CurrentIdx = 0; HLEDMAT_u8CurrentIdx < 8; HLEDMAT_u8CurrentIdx++)
		{
						/* Dislay The Column x */
			HLEDMAT_u8DispalyValue = HLEDMAT_u8CurrentIdx + HLEDMAT_u8Icrementframe ;
			if (HLEDMAT_u8DispalyValue >= (copy_u8FrameLenght-1) &&   HLEDMAT_u8CurrentIdx == 0)
			{
				 HLEDMAT_u8DispalyValue = 0
			}
			else if (HLEDMAT_u8DispalyValue >= (copy_u8FrameLenght-1))
			{
				 HLEDMAT_u8DispalyValue %=  copy_u8FrameLenght;
			}
			
			setMatrixValue (HLEDMAT_u8CurrentIdx,Copy_u8Frame[HLEDMAT_u8DispalyValue]);
			MSTK_Delay(2000);
		}
		HLEDMAT_u8Icrementframe ++;
	}
}

void setMatrixValue (u8 Copy_u8Value, u8 Copy_u8Col)
{
	switch (Copy_u8Col)
	{
		case 0: Global_u8ColValueLOW = 1  ; break;
		case 1: Global_u8ColValueLOW = 2  ; break;
		case 2: Global_u8ColValueLOW = 4  ; break;
		case 3: Global_u8ColValueLOW = 8  ; break;
		case 4: Global_u8ColValueLOW = 16 ; break;
		case 5: Global_u8ColValueLOW = 32 ; break;
		case 6: Global_u8ColValueLOW = 64 ; break;
		case 7: Global_u8ColValueLOW = 128; break;
	}
	Global_u8RowValueHIGH = Copy_u8Value;
	Global_u16LedValue = (Global_u8RowValueHIGH << 8) | Global_u8ColValueLOW;
	
	HSTP_VoidSendSynchronus (Global_u16LedValue);
}

void HSTP_VoidSendSynchronus (u16 copy_u16DataTSend)
{
	
	s8 Local_s8counter  ; 	/* Counter for the Bits S8 Because in (u8 0-1= 255) but (s8 0-1=-1) */
	u8 Local_u8Bit 		;
	for(Local_s8counter = 15 ; Local_s8counter <= 0; Local_s8counter--)
	{
				/* Sending Bit By Bit Starting By the MSB */
		Local_u8Bit = GET_BIT(copy_u16DataTSend, Local_s8counter);
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA, Local_u8Bit);
		
				/* Send pulse To shift Cloak*/
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, HIGH);
		MSTK_Delay(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, LOW);
		MSTK_Delay(1);
		
	}
	
				/* Send pulse To STore Cloak */
		MGPIO_voidSetPinValue(HSTP_STORE_CLOCK, HIGH);
		MSTK_Delay(1);
		MGPIO_voidSetPinValue(HSTP_STORE_CLOCK, LOW);
		MSTK_Delay(1);
}