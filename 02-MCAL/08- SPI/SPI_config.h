/*****************************************/
/* Author  :  Hazem Khaled               */
/* Version :  V01                        */
/* Date    : 5 february 2021             */
/*****************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/* NSS bit is free to be used as an IO bit */

#define NSLAVESELECT       1		/*If NSS is 1, The external NSS pin remains free for other application uses.
									  If NSS is 0,in master mode. The NSS signal is driven low when the master starts the communication and is kept low until the SPI is disabled.
                                                  as slave mode, the NSS pin acts as a classical NSS input: the slave is selected when NSS is low and deselected when NSS high */

#define CLOCK_POLARITY     1        /* If Clock_POL is 0, the SCK pin has a low-level idle state. 
									   If Clock_POL is 1, the SCK pin has a high-level idle state. */


#define CLOCK_PHASE			1		/* If Clock_PH is 0, The first clock transition is the first data capture edge.
									   If Clock_PH is 1, The second clock transition is the first data capture edge */


#define MASTER 				1     	/* If MASTER is 0, In the SLAVE configuration
                                       If MASTER is 1, In the MASTER configuration   */


#define DATA_SIZE			0		/*  0: 8-bit data frame format is selected for transmission/reception
										1: 16-bit data frame format is selected for transmission/reception*/

#define DATA_ORDER 			0		/* 	0: MSB transmitted first
										1: LSB transmitted firs*/


/*The FREQUENCY Table
		0: fPCLK/2
		1: fPCLK/4
		2: fPCLK/8
		3: fPCLK/16
		4: fPCLK/32
		5: fPCLK/64
		6: fPCLK/128
		7: fPCLK/256
*/
#define FREQUENCY 			0

#endif 