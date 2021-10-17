/******************************************************************************************************************************/
/* Auther    : Hazem El-Wakeel                                                                                                */
/* Date      : 08 Aug 2020                                                                                                    */
/* version   : V01                                                                                                            */
/******************************************************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* RCC Clock Option :
		RCC_HSE_CRYSTAL 
		RCC_HSE_RC 
		RCC_HSI 
		RCC_PLL 
*/
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL 






#if RCC_CLOCK_TYPE == RCC_PLL
/* note Select this value only if pll is enabled*/
/* Option :
		RCC_PLL_IN_HSI_DIV_2 
		RCC_PLL_IN_HSI_DIV_2 
		RCC_PLL_IN_HSE 
*/
#define RCC_PLL_INPUT RCC_PLL_IN_HSE

/* option 2 to 16*/
#define RCC_PLL_MUL_VAL 2
#endif


#endif
