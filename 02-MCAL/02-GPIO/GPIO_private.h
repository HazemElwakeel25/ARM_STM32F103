/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 12 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


			/*		REGESTERS BASE POT ADDRESSES 		*/
#define GPIOA_BASE_ADDRESS 0x40010800
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIOC_BASE_ADDRESS 0x40011000


			/*		REGESTERS ADDRESSES FOR PORTA  		*/
#define GPIOA_CRL           *((volatile u32 *)(0X00000000 + GPIOA_BASE_ADDRESS))
#define GPIOA_CRH           *((volatile u32 *)(0X00000004 + GPIOA_BASE_ADDRESS))
#define GPIOA_IDR           *((volatile u32 *)(0X00000008 + GPIOA_BASE_ADDRESS))
#define GPIOA_ODR           *((volatile u32 *)(0X0000000C + GPIOA_BASE_ADDRESS))
#define GPIOA_BSRR          *((volatile u32 *)(0X00000010 + GPIOA_BASE_ADDRESS))
#define GPIOA_BRR           *((volatile u32 *)(0X00000014 + GPIOA_BASE_ADDRESS))
#define GPIOA_LCKR          *((volatile u32 *)(0X00000018 + GPIOA_BASE_ADDRESS))


			/*		REGESTERS ADDRESSES FOR PORTA  		*/
#define GPIOB_CRL           *((volatile u32 *)(0X00000000 + GPIOB_BASE_ADDRESS))
#define GPIOB_CRH           *((volatile u32 *)(0X00000004 + GPIOB_BASE_ADDRESS))
#define GPIOB_IDR           *((volatile u32 *)(0X00000008 + GPIOB_BASE_ADDRESS))
#define GPIOB_ODR           *((volatile u32 *)(0X0000000C + GPIOB_BASE_ADDRESS))
#define GPIOB_BSRR          *((volatile u32 *)(0X00000010 + GPIOB_BASE_ADDRESS))
#define GPIOB_BRR           *((volatile u32 *)(0X00000014 + GPIOB_BASE_ADDRESS))
#define GPIOB_LCKR          *((volatile u32 *)(0X00000018 + GPIOB_BASE_ADDRESS))


			/*		REGESTERS ADDRESSES FOR PORTA  		*/
#define GPIOC_CRL           *((volatile u32 *)(0X00000000 + GPIOC_BASE_ADDRESS))
#define GPIOC_CRH           *((volatile u32 *)(0X00000004 + GPIOC_BASE_ADDRESS))
#define GPIOC_IDR           *((volatile u32 *)(0X00000008 + GPIOC_BASE_ADDRESS))
#define GPIOC_ODR           *((volatile u32 *)(0X0000000C + GPIOC_BASE_ADDRESS))
#define GPIOC_BSRR          *((volatile u32 *)(0X00000010 + GPIOC_BASE_ADDRESS))
#define GPIOC_BRR           *((volatile u32 *)(0X00000014 + GPIOC_BASE_ADDRESS))
#define GPIOC_LCKR          *((volatile u32 *)(0X00000018 + GPIOC_BASE_ADDRESS))


#endif