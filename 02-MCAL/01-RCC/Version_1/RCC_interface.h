/******************************************************************************************************************************/
/* Auther    : Hazem El-Wakeel                                                                                                */
/* Date      : 08 Aug 2020                                                                                                    */
/* version   : V01                                                                                                            */
/******************************************************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/* the Macros for the bus types */
#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2


/* RCC_APB2 Option :
		RCC_APB2_PORTA
		RCC_APB2_PORTB
		RCC_APB2_PORTC
*/
#define RCC_APB2_PORTA 2
#define RCC_APB2_PORTB 3
#define RCC_APB2_PORTC 4


void MRCC_voidEnableClock (u8 copy_u8BusId, u8 copy_u8PerId);
void MRCC_voidDisableClock (u8 copy_u8BusId, u8 copy_u8PerId);
void MRCC_voidInitSysClock ();



#endif
