/********************************************************/
/* *********** Auther    : Hazem El-Wakeel   ************/
/* *********** Date      : 25 feb 2021       ************/
/* *********** version   : V01               ************/
/********************************************************/


#ifndef HLEDMAT_CONFIG_H
#define HLEDMAT_CONFIG_H


#ifndef STP_CONFIG_H
#define STP_CONFIG_H

/* Please Write PINS in pair (PORT,PIN) EX : GPIOA,0 */  
#define HSTP_SERIAL_DATA  GPIOA,0
#define HSTP_SHIFT_CLOCK  GPIOA,1
#define HSTP_STORE_CLOCK  GPIOA,2

#endif