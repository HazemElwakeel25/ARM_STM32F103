/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 17 March  2021              */
/*****************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


/* Do not forget
 * 	MRCC_voidEnableClock (RCC_AFIO );
 *	MRCC_voidEnableClock (RCC_USART1 );
 * 	MGPIO_voidSetPinDirection(GPIOA, PIN9,  OUTPUT_50MHZ_AFPP);
 *	MGPIO_voidSetPinDirection(GPIOA, PIN10,  INPUT_FLOATING);
	*/

void MUSART1_voidInit(void);
void MUSART1_voidBaudRateInit(u32 copy_u32BaudRate);
void MUSART1_voidTransmit(u16 *Copy_u8DataPtr, ...);
void MUSART1_u8Receive(u8 * copy_u8DataToReceive);


#endif
