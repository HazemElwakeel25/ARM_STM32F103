/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 17 Aug 2020       ************/
/* *********** version   : V01               ************/
/********************************************************/


/********************************************************/
/*************** gaurd for the file .c  *****************/
/********************************************************/
#ifndef SEVENSEGMSNT_CONFIG_H
#define SEVENSEGMSNT_CONFIG_H

#define COM_ANODE 1
#define COM_CATHOD 0

typedef struct {
	
	u8 type ; /* [COM_ANODE - COM_CATHOD] */
	
	u8 PORT ;
	
	u8 A ;
	u8 B ;
	u8 C ;
	u8 D ;
	u8 E ;
	u8 F ;
	u8 G ;
}SevenSegegmanInit;


#endif