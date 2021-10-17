/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 12 feb 2021      ************/
/* *********** version   : V01               ************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_config.h"


void HSTP_voidSendSynchronus (u16 copy_u16DataTSend)
{
	
	s8 Local_s8counter  ; 	/* Counter for the Bits S8 Because in (u8 0-1= 255) but (s8 0-1=-1) */
	u8 Local_u8Bit 		;
	for(Local_s8counter = (HSTP_NUMBER_OF_BITS_SENT - 1); Local_s8counter >= 0; Local_s8counter--)
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
