/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 22 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#define RISING     1
#define FALLING    3
#define ON_CHANGE  5

			/*		REGESTERS BASE POT ADDRESSES 		*/
#define EXTI_BASE_ADDRESS 0x40010400

typedef struct {
	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER ;
	volatile u32 PR ;
	
}ECTI_t;


#define EXTI ((volatile ECTI_t *) EXTI_BASE_ADDRESS)

#endif