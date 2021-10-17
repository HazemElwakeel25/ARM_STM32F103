/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  24 March 2021              */
/*****************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 CCR1  			;
	volatile u32 CNDTR  		;
	volatile u32 CPAR  			;
	volatile u32 CMAR  			;
	volatile u32 RESERVED  		;

}DMA_Channel;

typedef struct
{
	volatile u32 ISR  			;
	volatile u32 IFCR  			;
	DMA_Channel CHANNEL[7]   	;
}DMA_Type;

#define     DMA    ((DMA_Type*)0x40020000)



#endif
