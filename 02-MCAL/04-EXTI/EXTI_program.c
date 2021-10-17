/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 22 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (* EXT_Callback[16])(void) = NULL;

void MEXTI_voidInit(u8 copy_u8Line ,u8 copy_u8Mode)
{
	if(copy_u8Line <= 19) 
	{
		switch (copy_u8Mode)
		{
			case RISING :
			{
				SET_BIT(EXTI -> RTSR, copy_u8Line);			/* Setting the Regester to make intruppt on rissing edge*/ 
				break;
			}
			case FALLING:
			{
				SET_BIT(EXTI -> FTSR, copy_u8Line);			/* Setting the Regester to make intruppt on falling edge*/
				break;
			}
			case ON_CHANGE:
			{
				SET_BIT(EXTI -> RTSR, copy_u8Line);			/* Setting the Regester to make intruppt on rissing edge*/
				SET_BIT(EXTI -> FTSR, copy_u8Line);			/* Setting the Regester to make intruppt on falling edge*/
				break;
			}
			default:
			{
				/* Wrong Mode */
				break;
			}
		}
	}
	else
	{
		/* wrong line */
	}
	MEXTI_voidDisbleEXTI(copy_u8Line);          // to close the Intruppt untill the user open it 
}

void MEXTI_voidEnableEXTI(u8 copy_u8Line)
{
	if(copy_u8Line <= 19) 
	{
		SET_BIT(EXTI -> IMR, copy_u8Line);
	}
	else
	{
		/* wrong line */
	}
}


void MEXTI_voidDisbleEXTI(u8 copy_u8Line)
{
		if(copy_u8Line <= 19) 
	{
		CLR_BIT(EXTI -> IMR, copy_u8Line);
	}
	else
	{
		/* wrong line */
	}
}


void MEXTI_voidSWTrigger(u8 copy_u8Line)
{
		if(copy_u8Line <= 19) 
	{
		SET_BIT(EXTI -> SWIER, copy_u8Line);
	}
	else
	{
		/* wrong line */
	}
}


void MEXTI_voidSetCallBack(u8 copy_u8Line, void(*ptr)(void))
{
	EXT_Callback[copy_u8Line] = ptr ;
}

void EXTI0_IRQHandler(void)
{
	EXT_Callback[0]();
	SET_BIT(EXTI -> PR, 0);
}

void EXTI1_IRQHandler(void)
{
	EXT_Callback[1]();
	SET_BIT(EXTI -> PR, 1);
}

void EXTI2_IRQHandler(void)
{
	EXT_Callback[2]();
	SET_BIT(EXTI -> PR, 2);
}

void EXTI3_IRQHandler(void)
{
	EXT_Callback[3]();
	SET_BIT(EXTI -> PR, 3);
}

void EXTI4_IRQHandler(void)
{
	EXT_Callback[4]();
	SET_BIT(EXTI -> PR, 4);
}

void EXTI5_IRQHandler(void)
{
	EXT_Callback[5]();
	SET_BIT(EXTI -> PR, 5);
}

void EXTI6_IRQHandler(void)
{
	EXT_Callback[6]();
	SET_BIT(EXTI -> PR, 6);
}

void EXTI7_IRQHandler(void)
{
	EXT_Callback[7]();
	SET_BIT(EXTI -> PR, 7);
}

void EXTI8_IRQHandler(void)
{
	EXT_Callback[8]();
	SET_BIT(EXTI -> PR, 8);
}

void EXTI9_IRQHandler(void)
{
	EXT_Callback[9]();
	SET_BIT(EXTI -> PR, 9);
}


void EXTI10_IRQHandler(void)
{
	EXT_Callback[10]();
	SET_BIT(EXTI -> PR, 0);
}

void EXTI11_IRQHandler(void)
{
	EXT_Callback[11]();
	SET_BIT(EXTI -> PR, 11);
}

void EXTI12_IRQHandler(void)
{
	EXT_Callback[12]();
	SET_BIT(EXTI -> PR, 12);
}

void EXTI13_IRQHandler(void)
{
	EXT_Callback[13]();
	SET_BIT(EXTI -> PR, 13);
}

void EXTI14_IRQHandler(void)
{
	EXT_Callback[14]();
	SET_BIT(EXTI -> PR, 14);
}

void EXTI15_IRQHandler(void)
{
	EXT_Callback[15]();
	SET_BIT(EXTI -> PR, 15);
}
