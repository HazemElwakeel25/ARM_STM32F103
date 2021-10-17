/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 22 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/* the Prephrals to Remap */
#define AFIO_SPI1 		0    		/* change SPI1 	 From (NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7) to 	(NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5) */
#define AFIO_I2C1 		1 			/* change I2C1 	 From (SCL/PB6, SDA/PB7) 					 to 	(SCL/PB8, SDA/PB9) 						*/ 
#define AFIO_USART1		2			/* change USART1 From (TX/PA9, RX/PA10) 					 to 	(TX/PB6, RX/PB7) 						*/ 
#define AFIO_CAN 		13			/* chang  CAN    From (CAN_RX/PB8, CAN_TX/PB9)				 to     (CAN_RX/PA11, CAN_TX/PA12)              */


/* Timer Remaping bit1,bit2,remapValue*/ 

#define AFIO_TIM1				6,1			/* change TIM1 	From (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15) 
															to	  (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1)*/ 

#define AFIO_TIM2_Partial_1		8,1			/* change TIM2 	From (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
															to   (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)  	 */
#define AFIO_TIM2_Partial_2		8,2			/* change TIM2 	From (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
															to   ((CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)     */
#define AFIO_TIM2_Full   		8,3			/* change TIM2 	From (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
															to   (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)	 */


#define AFIO_TIM3_Partial_1		10,2		/* change TIM3  From (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
															to   (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)  			 */
#define AFIO_TIM3_Full   		10,3		/* change TIM3 	From (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
															to   (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)			 */


void MAFIO_voidSetEXTIConfiguration (u8 copy_u8line, u8 copy_u8PortMapp);
void MAFIO_voidRemapPrephrals (u8 copy_u8Prephral);
void MAFIO_voidRemapTimers (u8 copy_u8TimerBit, u8 copy_u8RemapValue);




#endif
