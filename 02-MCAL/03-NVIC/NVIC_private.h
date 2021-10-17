/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 19 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


				/* 				REGESTERS BASE PORT ADDRESSES 	       	*/
#define NVIC_BASE_ADDRESS           0xE000E100
#define NVIC_BASE_ADDRESS_FOR_STIR  0xE000EF00    /* STIR has different base address */

				/*		Interrupt set-enable registers ADDRESSES 		*/
#define NVIC_ISER0           *((volatile u32 *)(0X00000000 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 00 to 31 */
#define NVIC_ISER1           *((volatile u32 *)(0X00000004 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 32 to 63 */

				/*		Interrupt clear-enable registers ADDRESSES 		*/
#define NVIC_ICER0           *((volatile u32 *)(0X00000080 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 00 to 31 */
#define NVIC_ICER1           *((volatile u32 *)(0X00000084 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 32 to 63 */

				/*		Interrupt set-pending registers ADDRESSES 		*/
#define NVIC_ISPR0           *((volatile u32 *)(0X00000100 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 00 to 31 */
#define NVIC_ISPR1           *((volatile u32 *)(0X00000104 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 32 to 63 */

				/*		Interrupt clear-pending registers ADDRESSES 	*/
#define NVIC_ICPR0           *((volatile u32 *)(0X00000180 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 00 to 31 */
#define NVIC_ICPR1           *((volatile u32 *)(0X00000184 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 32 to 63 */

				/*		Interrupt active bit registers ADDRESSES 		*/
#define NVIC_IABR0           *((volatile u32 *)(0X00000200 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 00 to 31 */
#define NVIC_IABR1           *((volatile u32 *)(0X00000204 + NVIC_BASE_ADDRESS))	/* Enable External Interrupt 32 to 63 */

				/*		Interrupt priority registers ADDRESSES 			*/
#define NVIC_IPR              ((volatile  u8 *)(0X00000300 + NVIC_BASE_ADDRESS)) /* using u8 to be apply to access byte by byte and D refrance it NVIC_IPR[x] */


			    /*		Software trigger interrupt register ADDRESSES 	*/
#define NVIC_STIR            *((volatile u32 *)(0X00000E00 + NVIC_BASE_ADDRESS_FOR_STIR))  /* STIR has different base address */



/*		number of Groups and subgroups 	 Options
				MNVIC_GROUOP16_SUb0
				MNVIC_GROUOP8_SUb2
				MNVIC_GROUOP4_SUb4
				MNVIC_GROUOP2_SUb8
				MNVIC_GROUOP0_SUb16
*/
				/*		number of Groups and subgroups 		*/
#define MNVIC_GROUOP16_SUb0	 0x05FA0300 		//4 bits for group 0 bits for sub
#define MNVIC_GROUOP8_SUb2	 0x05FA0400 		//3 bits for group 1 bits for sub
#define MNVIC_GROUOP4_SUb4	 0x05FA0500		    //2 bits for group 2 bits for sub
#define MNVIC_GROUOP2_SUb8	 0x05FA0600		    //1 bits for group 3 bits for sub
#define MNVIC_GROUOP0_SUb16	 0x05FA0700 		//0 bits for group 4 bits for sub

#endif
