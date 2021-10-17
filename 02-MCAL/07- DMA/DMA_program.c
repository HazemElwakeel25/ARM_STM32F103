/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  24 March 2021              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_voidChannelInit(DMA_Channel_config *Channel)
{
	(DMA ->CHANNEL[(Channel->ID)-1].CCR) = 0;
	
	#if Channel->Diriction == 1
		SET_BIT((DMA ->CHANNEL[(Channel->ID)-1].CCR) ,4); 							/* Read from memory */
	#endif					
						
	#if (Channel->Circular == 1) &&  (Channel->MEM2MEM == 0)    					/* Circular cannot work with memory to memory */
		SET_BIT((DMA ->CHANNEL[(Channel->ID)-1].CCR) ,5); 							/* Read from memory */
	#endif					
						
	#if	Channel->PINC == 1	  					
		SET_BIT((DMA ->CHANNEL[(Channel->ID)-1].CCR) ,6); 							/* Peripheral increment mode enabled */
	#endif					
						
	#if	Channel->MINC == 1	  					
		SET_BIT((DMA ->CHANNEL[(Channel->ID)-1].CCR) ,7); 							/* Memory increment mode enabled */
	#endif					
						
	#if	Channel->MEM2MEM == 1	  					
		SET_BIT((DMA ->CHANNEL[(Channel->ID)-1].CCR) ,14); 							/* Memory to memory mode enabled */
	#endif
	
	(DMA ->CHANNEL[(Channel->ID)-1].CCR) |= ((Channel->Peripheral_size) << 8); 		/*Set Peripheral data size */
	
	(DMA ->CHANNEL[(Channel->ID)-1].CCR) |= ((Channel->Peripheral_size) << 10); 	/*Set Memory data size */
	
	(DMA ->CHANNEL[(Channel->ID)-1].CCR) |= ((Channel->priority) << 12); 			/*Set Channel priority */
	
}


