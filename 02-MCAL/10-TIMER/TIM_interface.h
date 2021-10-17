/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  31 March 2020              */
/*****************************************/
#ifndef TIM_INTERFACE_H
#define TIM_INTERFACE_H


void TIM_voidInit(u8 copy_u8TimerNumber);




void MSTK_Delay( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif