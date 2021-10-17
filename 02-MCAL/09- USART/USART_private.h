/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 17 March  2021              */
/*****************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct
{
	volatile u32 SR  	;
	volatile u32 DR 	;
	volatile u32 BRR  	;
	volatile u32 CR1   	;
	volatile u32 CR2   	;
	volatile u32 CR3   	;
	volatile u32 GTPR   ;


}USART_TYPE;

#define     USART1    ((USART_TYPE*) 0x40013800)



#endif
