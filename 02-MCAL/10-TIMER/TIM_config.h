/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    :  31 March 2020              */
/*****************************************/
#ifndef TIM_CONFIG_H
#define TIM_CONFIG_H

/* The RCC Frequancy */

#define FREQUANCY 8000000

/* 1 MICROSEC = 1000000 if you want 1 mili = 1000*/
#define COUNTING_VALUE 1000000  

/* The ARR value is The Duty Cycle of the PWM 256[0-255] or 1024[0-1023] Range to 2^16 [65536] */
#define DUTY_CYCLE 1024

/* The Frequancy of the PWM  PWM_Freq = CLK/(PSC*ARR) */

#define PWM_PSC 0			/*the frequancy = 7,812.5 hz*/



#endif