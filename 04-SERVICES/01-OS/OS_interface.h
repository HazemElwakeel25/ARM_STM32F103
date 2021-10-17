/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 05 sep 2020                 */
/*****************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask( u8 copy_u8Priorty , u16 copy_u16Priodicity , void (*ptr) (void) , u8 copy_u8FristDelay); // copy_u8Priorty in msec

void SOS_voidOSStart(void);

#endif