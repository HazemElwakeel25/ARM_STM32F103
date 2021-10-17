/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 5 february 2021             */
/*****************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct
{
	volatile u32 CR1  		;
	volatile u32 CR2  		;
	volatile u32 SR   		;
	volatile u32 DR   		;
	volatile u32 CRCPR   	;
	volatile u32 RXCRCR   	;
	volatile u32 TXCRCR   	;
	volatile u32 I2SCFGR    ;
	volatile u32 I2SPR  	;

}SPI_Type;

#define     SPI_1    ((SPI_Type*)0x40013000)

#define     SPI_2    ((SPI_Type*)0x40003800)



#endif
