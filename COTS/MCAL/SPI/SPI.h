

#ifndef SPI_H_
#define SPI_H_

#define SPI_TX_BUFFER_SIZE 100
#define SPI_RX_BUFFER_SIZE 100

extern stdReturnType_t SPI_init (void) ;
extern stdReturnType_t SPI_transmit (u8 data); 
extern stdReturnType_t SPI_recieve (u8 *data);
extern stdReturnType_t SPI_transmitAsynchronous(u8 * data, u8 size);
extern stdReturnType_t SPI_recieveAsynchronous(u8 * data, u8 * size);
extern stdReturnType_t SPI_TransferIntStatus(u8 status);


#endif /* SPI_H_ */
