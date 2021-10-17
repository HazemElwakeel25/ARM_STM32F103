/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 19 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

typedef struct
{
	s8 Copy_s8IntNumber ;     		// the Interrupt number
	u32 copy_u32NumGroupSub;		// the number of the group of subgroups
	u8 Copy_u8GroupPriority;  		// the priority of the group
	u8 Copy_u8SubGroupPriority;		// the priority of the subgroup

}NVIC_PriorityInit;

#define NVIC_RCC		5
#define NVIC_EXTI0		6
#define NVIC_EXTI1		7
#define NVIC_EXTI2		8
#define NVIC_EXTI3		9
#define NVIC_EXTI4		10
#define NVIC_EXTI5		23
#define NVIC_EXTI6		23
#define NVIC_EXTI7		23
#define NVIC_EXTI8		23
#define NVIC_EXTI9		23
#define NVIC_EXTI10		40
#define NVIC_EXTI11		40
#define NVIC_EXTI12		40
#define NVIC_EXTI13		40
#define NVIC_EXTI14		40
#define NVIC_EXTI15		40
#define NVIC_DMA1_CH1	11
#define NVIC_DMA1_CH2	12
#define NVIC_DMA1_CH3	13
#define NVIC_DMA1_CH4	14
#define NVIC_DMA1_CH5	14
#define NVIC_DMA1_CH6	16
#define NVIC_DMA1_CH7	17
#define NVIC_ADC1_2		18
#define NVIC_SPI1		35
#define NVIC_SPI2		36
#define NVIC_USART1		37
#define NVIC_USART2		38

void MNVIC_voidEnableInterpput  (u8 Copy_u8IntNumber);

void MNVIC_voidDisableInterpput (u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);

u8   MNVIC_u8GetActiveFlag      (u8 Copy_u8IntNumber);

void MNVIC_voidSCBInit(void);

void MNVIC_voidSetPriority (NVIC_PriorityInit * PriorityInit);

#endif
