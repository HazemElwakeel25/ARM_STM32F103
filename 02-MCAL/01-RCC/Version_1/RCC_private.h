/******************************************************************************************************************************/
/* Auther    : Hazem El-Wakeel                                                                                                */
/* Date      : 08 Aug 2020                                                                                                    */
/* version   : V01                                                                                                            */
/******************************************************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*Rigester Definition*/

#define Base_Address 0x40021000

#define RCC_CR          *((volatile u32 *)(0X00 + Base_Address))
#define RCC_CFGR        *((volatile u32 *)(0X04 + Base_Address))
#define RCC_CIR         *((volatile u32 *)(0X08 + Base_Address))
#define RCC_APB2RSTR    *((volatile u32 *)(0X0C + Base_Address))
#define RCC_APB1RSTR    *((volatile u32 *)(0X10 + Base_Address))
#define RCC_AHBENR      *((volatile u32 *)(0X14 + Base_Address))
#define RCC_APB2ENR     *((volatile u32 *)(0X18 + Base_Address))
#define RCC_APB1ENR     *((volatile u32 *)(0X1C + Base_Address))
#define RCC_BDCR        *((volatile u32 *)(0X20 + Base_Address))
#define RCC_CSR         *((volatile u32 *)(0X24 + Base_Address))

/* the Macros for the bus types */
#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

/* Clock Types*/
#define RCC_HSE_CRYSTAL 0
#define RCC_HSE_RC 1
#define RCC_HSI 2
#define RCC_PLL 3

/* PLL OPtion */
#define RCC_PLL_IN_HSI_DIV_2 0
#define RCC_PLL_IN_HSE_DIV_2 1
#define RCC_PLL_IN_HSE       2
#endif
