/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 22 Aug 2020       ************/
/* *********** version   : V02               ************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIConfiguration (u8 copy_u8line, u8 copy_u8PortMapp)
{
	u8 local_u8RegesterIndex = copy_u8line % 4 ;
	copy_u8line = copy_u8line - (local_u8RegesterIndex * 4);
	
	AFIO->EXTICR[local_u8RegesterIndex] &=  ~((0b1111) << (copy_u8line * 4));
	AFIO->EXTICR[local_u8RegesterIndex] |=   ((copy_u8PortMapp) << (copy_u8line * 4));

}
void MAFIO_voidRemapPrephrals (u8 copy_u8Prephral)
{
	SET_BIT(AFIO->MAPR,copy_u8Prephral);
}

void MAFIO_voidRemapTimers (u8 copy_u8TimerBit, u8 copy_u8RemapValue)
{
	AFIO->MAPR |=  (copy_u8RemapValue << (copy_u8TimerBit));
}