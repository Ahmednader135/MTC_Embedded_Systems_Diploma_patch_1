/*
 * DIO.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Abdelrahman Elesh
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/************* Type def section ************/

typedef struct
{
	portX_t Port;
	pinX_t Pin;
	pinDir_t Direction;
	
}PinConfig_t;


extern PinConfig_t PinConfig_array[];
extern u16 PinConfig_array_size;




#endif /* DIO_MCAL_INC_DIO_H_ */
