/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 17 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SevenSegmant_interface.h"
#include "SevenSegmant_config.h"

void SevenSegment_VoidDesplay ( SevenSegegmanInit *SEVENSEG, u8 copy_u8Value)
{
	if (SEVENSEG->COM_ANODE == COM_ANODE)
	{
		switch (copy_u8Value)
		{
			case 0 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 1 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				break;
			}
			case 2 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 3 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 4 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 5 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 6 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 7 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 8 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 9 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			default :
			{
				// wrong number
			}
						
		}
	}
	else if (SEVENSEG->COM_CATHOD == COM_CATHOD)
	{

		switch (copy_u8Value)
		{
			case 0 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 1 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 2 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 3 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 4 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 5 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 6 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 7 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 1);
				break;
			}
			case 8 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			case 9 :
			{
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->A, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->B, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->C, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->D, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->E, 1);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->F, 0);
				MGPIO_voidSetPinValue(SEVENSEG->PORT, SEVENSEG->G, 0);
				break;
			}
			default :
			{
				// wrong number
			}
		}			
		
	}
}