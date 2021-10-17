/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 19 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H
/*
number of Groups and subgroups 	 Options
 MNVIC_GROUOP16_SUb0	4 bits for group 0 bits for sub
 MNVIC_GROUOP8_SUb2	    3 bits for group 1 bits for sub
 MNVIC_GROUOP4_SUb4	    2 bits for group 2 bits for sub
 MNVIC_GROUOP2_SUb8	    1 bits for group 3 bits for sub
 MNVIC_GROUOP0_SUb16	0 bits for group 4 bits for sub
 */


 
 #define MNVIC_NumGroupSub MNVIC_GROUOP4_SUb4
 
 
#endif
