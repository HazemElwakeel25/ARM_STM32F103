/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  31 March 2020              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"


/* Define Callback Global Variable */
static void(*TIM1_CallBack)(void);
static void(*TIM2_CallBack)(void);
static void(*TIM3_CallBack)(void);
static void(*TIM4_CallBack)(void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void TIM_voidTimerInit(u8 copy_u8TimerNumber)
{
/* Selecting Prescaler to make the counter count at 1 MicroSec Interval */

	switch (copy_u8TimerNumber)
	{
		case 1 :
		{
			TIMER1->PSC = (FREQUANCY / COUNTING_VALUE);   /* Setting prescaler to count 1 Microsec */
			break;
		}
		case 2 :
		{
			TIMER2->PSC = (FREQUANCY / COUNTING_VALUE);	/* Setting prescaler to count 1 Microsec */
			break;
		}
		case 3 :
		{
			TIMER3->PSC = (FREQUANCY / COUNTING_VALUE);	/* Setting prescaler to count 1 Microsec */
			break;
		}
		case 4 :
		{
			TIMER4->PSC = (FREQUANCY / COUNTING_VALUE);	/* Setting prescaler to count 1 Microsec */
			break;
		}
		default :
		{
			/* wrong timer */
			break;
		}
		
	}

}


void TIM_AutoReloadTimer(u8 copy_u8TimerNumber, u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	
	switch (copy_u8TimerNumber)
	{
		case 1 :
		{
			/* 	-Counter used as upcounter
				-Counter overflow Interrupt */
			TIMER1->CR1 = 0;
			
			/* Save CallBack */
			TIM1_CallBack = Copy_ptr;
			
			/* Load ticks to auto-reload register */
			TIMER1->ARR = Copy_u32Ticks;
			
			/* Counter Enable */
			TIMER1->CR1 = 1;
			break;
		}
		case 2 :
		{
			/* 	-Counter used as upcounter
				-Counter overflow Interrupt */
			TIMER2->CR1 = 0;
			
			/* Save CallBack */
			TIM2_CallBack = Copy_ptr;
			
			/* Load ticks to auto-reload register */
			TIMER2->ARR = Copy_u32Ticks;
			
			/* Counter Enable */
			TIMER1->CR1 = 1;
			break;
		}
		case 3 :
		{
			/* 	-Counter used as upcounter
				-Counter overflow Interrupt */
			TIMER3->CR1 = 0;
			
			/* Save CallBack */
			TIM3_CallBack = Copy_ptr;
			
			/* Load ticks to auto-reload register */
			TIMER3->ARR = Copy_u32Ticks;
			
			/* Counter Enable */
			TIMER1->CR1 = 1;
			break;
		}
		case 4 :
		{
			/* 	-Counter used as upcounter
				-Counter overflow Interrupt */
			TIMER4->CR1 = 0;
			
			/* Save CallBack */
			TIM4_CallBack = Copy_ptr;
			
			/* Load ticks to auto-reload register */
			TIMER4->ARR = Copy_u32Ticks;
			
			/* Counter Enable */
			TIMER1->CR1 = 1;
			break;
		}
		default :
		{
			/* wrong timer */
			break;
		}
		
	}

	
	
}




void TIM_voidPWMInit(u8 copy_u8TimerNumber)
{
/* Selecting Prescaler to make the counter count at 1 MicroSec Interval */

	switch (copy_u8TimerNumber)
	{
		case 1 :
		{
			/* PWM_Freq = CLK/(PSC*ARR)    */	
			/* PWM_DUTY = CCR / ARR  if ccr = 512 arr = 1024 DUTY = 50 %*/
			TIMER1 -> ARR = DUTY_CYCLE;	
			TIMER1-> PSC = PWM_PSC;
			break;
		}
		case 2 :
		{
			/* PWM_Freq = CLK/(PSC*ARR)    */	
			/* PWM_DUTY = CCR / ARR  if ccr = 512 arr = 1024 DUTY = 50 %*/
			TIMER2 -> ARR = DUTY_CYCLE;	
			TIMER2 -> PSC = PWM_PSC;
			break;
		}
		case 3 :
		{
			/* PWM_Freq = CLK/(PSC*ARR)    */	
			/* PWM_DUTY = CCR / ARR  if ccr = 512 arr = 1024 DUTY = 50 %*/
			TIMER3 -> ARR = DUTY_CYCLE;	
			TIMER3 -> PSC = PWM_PSC;
			break;
		}
		case 4 :
		{
			/* PWM_Freq = CLK/(PSC*ARR)    */	
			/* PWM_DUTY = CCR / ARR  if ccr = 512 arr = 1024 DUTY = 50 %*/
			TIMER4 -> ARR = DUTY_CYCLE;	
			TIMER4 -> PSC = PWM_PSC;
			break;
		}
		default :
		{
			/* wrong timer */
			break;
		}
		
	}
}


void TIM_PWM(u8 copy_u8TimerNumber, u8 Copy_u8TimerChannel, u16 Copy_u16PWMValue )
{
	
	switch (copy_u8TimerNumber)
	{
		case 1 :
		{
			switch (Copy_u8TimerChannel)
			{
				case 1 :
				{
					
					CLR_BIT(TIMER1 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER1 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER1 -> CCER ,0);					/* output enable*/
					
					TIMER1 -> CCMR1 |= (1101 << 3);				/* PWM mode 1 -In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER1 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER1 -> CCER ,1);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */

					TIMER1 -> CCR1 = Copy_u16PWMValue;
					
					SET_BIT(TIMER1 -> CR1 ,0);					/* TIM enable*/ 
					
					break;
				}
				case 2 :
				{
					CLR_BIT(TIMER1 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER1 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER1 -> CCER ,4);					/* output enable*/
					
					TIMER1 -> CCMR1 |= (1101 << 11);				/* PWM mode 1 - 	In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER1 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER1 -> CCER ,5);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */
																	
					TIMER1 -> CCR2 = Copy_u16PWMValue;

					SET_BIT(TIMER1 -> CR1 ,0);					/* TIM enable*/ 
					break;
				}
				case 3 :
				{
					CLR_BIT(TIMER1 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER1 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER1 -> CCER ,8);					/* output enable*/
					
					TIMER1 -> CCMR2 |= (1101 << 3);				/* PWM mode 1 -In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER1 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER1 -> CCER ,9);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */

					TIMER1 -> CCR3 = Copy_u16PWMValue;
					
					SET_BIT(TIMER1 -> CR1 ,0);					/* TIM enable*/ 
					break;
				}
				case 4 :
				{
					CLR_BIT(TIMER1 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER1 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER1 -> CCER ,12);					/* output enable*/
					
					TIMER1 -> CCMR2 |= (1101 << 11);				/* PWM mode 1 - 	In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER1 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER1 -> CCER ,12);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */
																	
					TIMER1 -> CCR4 = Copy_u16PWMValue;

					SET_BIT(TIMER1 -> CR1 ,0);					/* TIM enable*/ 
					break;
				}
				default :
				{
					/* wrong timer */
					break;
				}
				
			}
		}
		case 2 :
		{
			switch (Copy_u8TimerChannel)
			{
				case 1 :
				{
					
					CLR_BIT(TIMER2 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER2 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER2 -> CCER ,0);					/* output enable*/
					
					TIMER2 -> CCMR1 |= (1101 << 3);				/* PWM mode 1 -In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER2 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER2 -> CCER ,1);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */

					TIMER2 -> CCR1 = Copy_u16PWMValue;
					
					SET_BIT(TIMER2 -> CR1 ,0);					/* TIM enable*/ 
					
					break;
				}
				case 2 :
				{
					CLR_BIT(TIMER2 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER2 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER2 -> CCER ,4);					/* output enable*/
					
					TIMER2 -> CCMR1 |= (1101 << 11);				/* PWM mode 1 - 	In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER2 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER2 -> CCER ,5);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */
																	
					TIMER2 -> CCR2 = Copy_u16PWMValue;

					SET_BIT(TIMER2 -> CR1 ,0);					/* TIM enable*/ 
					break;
				}
				case 3 :
				{
					CLR_BIT(TIMER2 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER2 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER2 -> CCER ,8);					/* output enable*/
					
					TIMER2 -> CCMR2 |= (1101 << 3);				/* PWM mode 1 -In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER2 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER2 -> CCER ,9);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */

					TIMER2 -> CCR3 = Copy_u16PWMValue;
					
					SET_BIT(TIMER2 -> CR1 ,0);					/* TIM enable*/ 
					break;
				}
				case 4 :
				{
					CLR_BIT(TIMER2 -> CR1 ,4);					/* upcounter*/
					SET_BIT(TIMER2 -> CR1 ,7);					/* TIMx_ARR register is buffered*/
					
					SET_BIT(TIMER2 -> CCER ,12);					/* output enable*/
					
					TIMER2 -> CCMR2 |= (1101 << 11);				/* PWM mode 1 - 	In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. Output compare 1 preload enable*/
																  
					SET_BIT(TIMER2 -> EGR ,0);					/* by setting the UG bit*/
					
					CLR_BIT(TIMER2 -> CCER ,12);					/* the pwm is active High if active low set SET_BIT(TIMER1->CCER ,1) */
																	
					TIMER2 -> CCR4 = Copy_u16PWMValue;

					SET_BIT(TIMER2 -> CR1 ,0);					/* TIM enable*/ 
					break;
				}
				default :
				{
					/* wrong timer */
					break;
				}
				
			}
		}
		case 3 :
		{
			
		}
		case 4 :
		{
			
		}
		default :
		{
			/* wrong timer */
			break;
		}
		
	}
}

void TIM1_IRQHandler(void)
{
	if ( GET_BIT(TIMER1->SR,0) == 1)
	{
		/* Callback notification */
		TIM1_CallBack();
	}
	

}

void TIM2_IRQHandler(void)
{
	if ( GET_BIT(TIMER2->SR,0) == 1)
	{
		/* Callback notification */
		TIM2_CallBack();
	}
	
}

void TIM3_IRQHandler(void)
{
	if ( GET_BIT(TIMER3->SR,0) == 1)
	{
		/* Callback notification */
		TIM3_CallBack();
	}
	
}

void TIM4_IRQHandler(void)
{
	if ( GET_BIT(TIMER4->SR,0) == 1)
	{
		/* Callback notification */
		TIM4_CallBack();
	}
	
}








void MSTK_Delay( u32 Copy_u32Ticks )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	
	/* Wait till flag is raised */
	while( (GET_BIT(MSTK->CTRL,16)) == 0);
	
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
	
}

void MSTK_voidSetIntervalSingle ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
}

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
}

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = MSTK -> LOAD - MSTK -> VAL ;
	
	return Local_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = MSTK -> VAL ;
	
	return Local_u32RemainTime;
}
