/******************************************************************************************************************************/
/* Auther    : Hazem El-Wakeel                                                                                                */
/* Date      : 12 feb 2021                                                                                                    */
/* version   : V02                                                                                                            */
/******************************************************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


// the Macros for the bus types 
#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

/* the Macros for the bus types */
#define RCC_DMA		0,0
#define RCC_AFIO 	2,0
#define RCC_GPIOA 	2,2
#define RCC_GPIOB 	2,3
#define RCC_GPIOC 	2,4
#define RCC_TIMER1 	2,11
#define RCC_SPI1 	2,12
#define RCC_USART 	2,14
#define RCC_SPI2 	1,14



/* Clock Types*/
#define RCC_HSE_CRYSTAL 0
#define RCC_HSE_RC 1
#define RCC_HSI 2
#define RCC_PLL 3

typedef struct {
	u8 ClockType ;		/* Option : [RCC_HSE_CRYSTAL - RCC_HSE_RC  - RCC_HSI ] */
	u8 PLLEnable ;		/*    0-1   */
	u8 PllValue ;		/* Option : [RCC_PLL_IN_HSI_DIV_2 - RCC_PLL_IN_HSE_DIV_2 - RCC_PLL_IN_HSE ]*/
	u8 PllMULLVal;		/* option 2 to 16*/
	
}RCC_Clock_config;


void MRCC_voidInitSysClock (RCC_Clock_config *Clock_config);

void MRCC_voidEnableClock (u8 copy_u8BusId, u8 copy_u8PerId);
void MRCC_voidDisableClock (u8 copy_u8BusId, u8 copy_u8PerId);




#endif
