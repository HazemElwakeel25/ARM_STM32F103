/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 05 sep 2020                 */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#include "STK_interface.h"

#define NULL   (void *)0

/* Array of Tasks "Array of structures" */

static Task OS_Tasks[NUMBER_OF_TASK] = {NULL};



void SOS_voidCreateTask( u8 copy_u8Priorty , u16 copy_u16Priodicity , void (*ptr) (void) , u16 copy_u8FristDelay)
{
	OS_Tasks[copy_u8Priorty].priodicity  = copy_u16Priodicity ;
	OS_Tasks[copy_u8Priorty].Fptr = ptr ;
	OS_Tasks[copy_u8Priorty].FristDelay = copy_u8FristDelay ;
}

void SOS_voidOSStart(void)
{
	/* Intialization */
	MSTK_voidInit();
	
	/* TICk => 1 msec */
	/* HSE 8MHZ /8 ==> 1000 Micro sec */
	MSTK_voidSetIntervalPeriodic( 1000, Scheduler);
	
}

void Scheduler(void)
{
	for (u8 i = 0; i < NUMBER_OF_TASK ; i++)
	{
		if (OS_Tasks[i].Fptr != NULL )// OS_Tasks[i].state == READY
		{
			if ( OS_Tasks[i].FristDelay == 0)
			{
				OS_Tasks[i].FristDelay = OS_Tasks[i].priodicity - 1 ; 
				OS_Tasks[i].Fptr();
			}
			else 
			{
				OS_Tasks[i].FristDelay --;
			}
		}

	}
}