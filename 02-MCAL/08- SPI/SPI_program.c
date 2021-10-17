/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 5 february 2021             */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

static void (* SPI1_CallBack) (u8) = NULL ;
u8 SPI1_SlavePort ;
u8 SPI1_SlavePinNumber ;

static void (* SPI2_CallBack) (u8) = NULL ;
u8 SPI2_SlavePort ;
u8 SPI2_SlavePinNumber ;

/* SPI_1 Functions*/


void MSPI1_voidInit(void)
{
	SPI_1 -> CR1 = 0 ;   			/* Disabling the SPI */ 
	/*
		1- full-duplex
	*/
	#if DATA_SIZE == 1
		SET_BIT(SPI_1 -> CR1,11); 		/*16-bit data frame format is selected for transmission/reception*/
	#endif
	
	#if NSLAVESELECT == 1
		SET_BIT(SPI_1 -> CR1,9);		/*The external NSS pin remains free for other application uses.*/
	#endif
	
	#if DATA_ORDER == 1					/*LSB transmitted firs*/
		SET_BIT(SPI_1 -> CR1,7);
	#endif
	
	#if MASTER == 1						/* In the MASTER configuration   */
		SET_BIT(SPI_1 -> CR1,2);
	#endif

	#if CLOCK_POLARITY == 1				/*If Clock_POL is 1, the SCK pin has a high-level idle state. */
		SET_BIT(SPI_1 -> CR1,1);
	#endif
	
	#if CLOCK_PHASE == 1				/* the first edge on the SCK pin (falling edge if CLOCK_POL bit is set, rising edge if CLOCK_POL bit is reset) is the MSBit capture strobe.*/
		SET_BIT(SPI_1 -> CR1,0);
	#endif
	
	SET_BIT |= (FREQUENCY << 3);  /* Setting the Freq*/ 
	
	SET_BIT(SPI_1 -> CR1,6);			 /* Enable SPI */
	
	
	
}

void MSPI1_voidSimplexSendSynchNoSlaveSelect(u8 copy_u8DataToTransmit)  /* the slave Select is set to the ground*/
{
	/* the slave Select is set to the ground*/
	
	/* Send Data */ 
	SPI_1 -> DR = copy_u8DataToTransmit;
	 
}

void MSPI1_voidSendReceiveSynch(u8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive)
{
	/* clear for Slave Select */
	MGPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePinNumber, LOW);
	
	/* Send Data */ 
	SPI_1 -> DR = copy_u8DataToTransmit;
	
	/* waiting the Busy flag for the end of the send */ 
	while (GET_ BIT (SPI_1 -> SR, 7) == 1);
	
	/* Receive Data */ 
	*copy_u8DataToReceive = SPI_1 -> DR ;
	
	/* set for Slave Select */
	MGPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePinNumber, HIGH);
	 
}

void MSPI1_voidSendReceiveSynchNoSlaveSelect(u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive)
{
	/* the slave Select is set to the ground*/
	
	/* Send Data */ 
	SPI_1 -> DR = copy_u8DataToTransmit;
	
	/* waiting the Busy flag for the end of the send */ 
	while (GET_ BIT (SPI_1 -> SR, 7) == 1);
	
	/* Receive Data */ 
	*copy_u8DataToReceive = SPI_1 -> DR ;
	
}

void MSPI1_voidSendReceiveAsynch(U8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, void (*callback) (u8))
{
	/* clear for Slave Select */
	MGPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePinNumber, LOW);
	
	/* Send Data */ 
	SPI_1 -> DR = copy_u8DataToTransmit;
	
	/* Receive Data */ 
	SPI1_CallBack = callback ;
	SPI1_SlavePort = copy_u8SlavePort;
	SPI1_SlavePinNumber = copy_u8SlavePort;
} 

void SPI1_IQRHandler()
{
	/* set for Slave Select */
	MGPIO_voidSetPinValue(SPI1_SlavePort,SPI1_SlavePinNumber, HIGH);
	
	
	SPI1_CallBack(SPI_1 -> DR);

}

/* SPI_2 Functions*/


void MSPI2_voidInit(void)
{
	SPI_2 -> CR1 = 0 ;   			/* Disabling the SPI */ 
	/*
		1- full-duplex
	*/
	#if DATA_SIZE == 1
		SET_BIT(SPI_2 -> CR1,11); 		/*16-bit data frame format is selected for transmission/reception*/
	#endif
	
	#if NSLAVESELECT == 1
		SET_BIT(SPI_2 -> CR1,9);		/*The external NSS pin remains free for other application uses.*/
	#endif
	
	#if DATA_ORDER == 1					/*LSB transmitted firs*/
		SET_BIT(SPI_2 -> CR1,7);
	#endif
	
	#if MASTER == 1						/* In the MASTER configuration   */
		SET_BIT(SPI_2 -> CR1,2);
	#endif

	#if CLOCK_POLARITY == 1				/*If Clock_POL is 1, the SCK pin has a high-level idle state. */
		SET_BIT(SPI_2 -> CR1,1);
	#endif
	
	#if CLOCK_PHASE == 1				/* the first edge on the SCK pin (falling edge if CLOCK_POL bit is set, rising edge if CLOCK_POL bit is reset) is the MSBit capture strobe.*/
		SET_BIT(SPI_2 -> CR1,0);
	#endif
	
	SET_BIT |= (FREQUENCY << 3);  /* Setting the Freq*/ 
	
	SET_BIT(SPI_2 -> CR1,6);			 /* Enable SPI */
	
	
	
}

void MSPI2_voidSimplexSendSynchNoSlaveSelect(u8 copy_u8DataToTransmit)  /* the slave Select is set to the ground*/
{
	/* the slave Select is set to the ground*/
	
	/* Send Data */ 
	SPI_2 -> DR = copy_u8DataToTransmit;
	 
}

void MSPI2_voidSendReceiveSynch(u8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive)
{
	/* clear for Slave Select */
	MGPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePinNumber, LOW);
	
	/* Send Data */ 
	SPI_2 -> DR = copy_u8DataToTransmit;
	
	/* waiting the Busy flag for the end of the send */ 
	while (GET_ BIT (SPI_2 -> SR, 7) == 1);
	
	/* Receive Data */ 
	*copy_u8DataToReceive = SPI_2 -> DR ;
	
	/* set for Slave Select */
	MGPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePinNumber, HIGH);
	 
}

void MSPI2_voidSendReceiveSynchNoSlaveSelect(u8 copy_u8DataToTransmit, u8 * copy_u8DataToReceive)
{
	/* the slave Select is set to the ground*/
	
	/* Send Data */ 
	SPI_2 -> DR = copy_u8DataToTransmit;
	
	/* waiting the Busy flag for the end of the send */ 
	while (GET_ BIT (SPI_2 -> SR, 7) == 1);
	
	/* Receive Data */ 
	*copy_u8DataToReceive = SPI_2 -> DR ;
	
}

void MSPI2_voidSendReceiveAsynch(U8 copy_u8SlavePort, u8 copy_u8SlavePinNumber, u8 copy_u8DataToTransmit, void (*callback) (u8))
{
	/* clear for Slave Select */
	MGPIO_voidSetPinValue(copy_u8SlavePort, copy_u8SlavePinNumber, LOW);
	
	/* Send Data */ 
	SPI_2 -> DR = copy_u8DataToTransmit;
	
	/* Receive Data */ 
	SPI2_CallBack = callback ;
	SPI2_SlavePort = copy_u8SlavePort;
	SPI2_SlavePinNumber = copy_u8SlavePort;
} 

void SPI2_IQRHandler()
{
	/* set for Slave Select */
	MGPIO_voidSetPinValue(SPI2_SlavePort,SPI2_SlavePinNumber, HIGH);
	
	
	SPI1_CallBack(SPI_2 -> DR);

}
