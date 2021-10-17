/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 5 february 2021             */
/*****************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/* SPI1 Functions */
void MSPI1_voidInit(void);

/* Simplex contol */
void MSPI1_voidSimplexSendSynchNoSlaveSelect(u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive);  /* the slave Select is set to the ground*/

/* Send Recive FullDuplix */
/* Synch mean that the function will wait till it send and receive before return */
void MSPI1_voidSendReceiveSynchNoSlaveSelect(u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive);  /* the slave Select is set to the ground*/
void MSPI1_voidSendReceiveSynch(u8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive); 
void MSPI1_voidSendReceiveAsynch(U8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, void (*callback) (u8)) ;



/* SPI2 Functions */
void MSPI2_voidInit(void);

/* Simplex contol */
void MSPI2_voidSimplexSendSynchNoSlaveSelect(u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive);  /* the slave Select is set to the ground*/

/* Send Recive FullDuplix */
/* Synch mean that the function will wait till it send and receive before return */
void MSPI2_voidSendReceiveSynchNoSlaveSelect(u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive);  /* the slave Select is set to the ground*/
void MSPI2_voidSendReceiveSynch(u8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive); 
void MSPI2_voidSendReceiveAsynch(U8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, void (*callback) (u8)) ;
#endif