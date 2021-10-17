/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  31 March 2020              */
/*****************************************/
#ifndef TIM_PRIVATE_H
#define TIM_PRIVATE_H

typedef struct
{
	volatile u32 CR1  	;
	volatile u32 CR2	;
	volatile u32 SMCR   ;
	volatile u32 DIER   ;
	volatile u32 SR   	;
	volatile u32 EGR   	;
	volatile u32 CCMR1  ;
	volatile u32 CCMR2  ;
	volatile u32 CCER  	;
	volatile u32 CNT   	;
	volatile u32 PSC   	;
	volatile u32 ARR   	;
	volatile u32 CCR1   ;
	volatile u32 CCR2   ;
	volatile u32 CCR3   ;
	volatile u32 CCR4   ;
	volatile u32 DCR   	;
	volatile u32 DMAR   ;

	
	
	
	
}TIMER_Type;

#define     TIMER1   ((TIMER_Type*)0x40012C00)

#define     TIMER2   ((TIMER_Type*)0x40000000)

#define     TIMER3   ((TIMER_Type*)0x40000400)

#define     TIMER4   ((TIMER_Type*)0x40000800)


#define		TIM1	 1
#define		TIM2	 2
#define		TIM3	 3
#define		TIM4	 4


#endif
