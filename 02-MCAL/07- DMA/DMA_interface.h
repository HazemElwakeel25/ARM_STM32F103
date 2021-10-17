/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  24 March 2021              */
/*****************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef struct {
	u8 ID 		;			/*  Channel number[1-7] */
		
	u8 Diriction ;			/*  Data transfer direction 0: Read from peripheral						
														1: Read from memory		*/
														
	u8 Circular ;			/*  0: Circular mode disabled
								1: Circular mode enabled*/
								
	u8 PINC		;			/*	0: Peripheral increment mode disabled
								1: Peripheral increment mode enabled   */
		
									
	u8 MINC		;			/*	0: Memory increment mode disabled
								1: Memory increment mode enabled 		*/
								
								
	u8 Peripheral_size		/*	0: 8-bits
								1: 16-bits
								2: 32-bits	*/
								
	u8 Memory_size		/*	0: 8-bits
								1: 16-bits
								2: 32-bits	*/

	u8 priority				/*  0: Low
								1: Medium
								2: High
								3: Very high */
	u8 MEM2MEM				/*  0: Memory to memory mode disabled
								1: Memory to memory mode enabled */
	
}DMA_Channel_config;


void DMA_voidChannelInit(DMA_Channel_config *Channel);



#endif