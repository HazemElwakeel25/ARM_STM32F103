/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 22 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/*
 *
/**
	* Intrupt Mode :
	*	RISING 
	* 	FALLING
	* 	ON_CHANGE
	*/
void MEXTI_voidInit(u8 copy_u8Line ,u8 copy_u8Mode);
void MEXTI_voidEnableEXTI(u8 copy_u8Line);
void MEXTI_voidDisbleEXTI(u8 copy_u8Line);
void MEXTI_voidSWTrigger(u8 copy_u8Line);

void MEXTI_voidSetCallBack(void(*ptr)(void));

#endif