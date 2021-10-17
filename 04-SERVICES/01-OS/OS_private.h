/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 05 sep 2020                 */
/*****************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct 
{
	u16 priodicity      ;
	void (*Fptr) (void) ;
	u16 FristDelay 		;
	//u8 state 			;
	
}Task;

void Scheduler(void);

#endif
