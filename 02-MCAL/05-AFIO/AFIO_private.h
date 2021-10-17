/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 22 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/


#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

#define AFIO_PORTA 0x0000 
#define AFIO_PORTB 0x0001 
#define AFIO_PORTC 0x0010 

			/*		REGESTERS BASE POT ADDRESSES 		*/
#define AFIO_BASE_ADDRESS 0x40010000

typedef struct 
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_t;

#define AFIO ((volatile AFIO_t *) AFIO_BASE_ADDRESS)

#endif