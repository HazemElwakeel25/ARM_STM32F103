/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 17 March  2021              */
/*****************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define Frequancy 						8000000			/* RCC Frequancy*/

#define Frequancy_Prescaler				1				/*	1: divides the source clock by 1
															2: divides the source clock by 2 */

#define FRAME_SIZE 						0 				/*	0: 1 Start bit, 8 Data bits, n Stop bit
															1: 1 Start bit, 9 Data bits, n Stop bit */
						  
#define PARITY_CONTROL_ENABLE  			0				/*	0: Parity control disabled
															1: Parity control enabled */


#define PARITY_SELECTION 				0				/*	0: Even parity
															1: Odd parity */


#define PARITY_ERROE_INTERRUPT			0				/*	0: Interrupt is inhibited
															1: A USART interrupt is generated whenever PE=1 in the USART_SR register */



#define TX_REGISTER_EMPTY_INTERRUPT		0				/*	0: Interrupt is inhibited
															1: A USART interrupt is generated whenever TXE=1 in the USART_SR register */


#define TX_COMPLETE_INTERRUPT			0				/*	0: Interrupt is inhibited
															1: A USART interrupt is generated whenever TC=1 in the USART_SR register */


#define RX_READY_TO_READ_INTERRUPT		0				/*	0: Interrupt is inhibited
															1: A USART interrupt is generated whenever RXNE=1 in the USART_SR register */


#define IDLE_LINE_INTERRUPT				0				/*	0: Interrupt is inhibited
															1: A USART interrupt is generated whenever IDLE=1 in the USART_SR register */

#define STOP_BIT_NUMBER					10				/*	00: 1 Stop bit
															01: 0.5 Stop bit
															10: 2 Stop bits
															11: 1.5 Stop bit*/





														
#endif 