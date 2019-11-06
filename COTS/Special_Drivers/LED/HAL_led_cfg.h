/*
 * HAL_led_cfg.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Abdelrahman.Elesh
 */

#ifndef HAL_LED_CFG_H_
#define HAL_LED_CFG_H_

/************* Macros def section ************/


/* Pin data type */
typedef struct
{
	ledX_t Led;
	portX_t Port;
	pinX_t Pin;
	
}LedConfig_t;


extern LedConfig_t LedConfig_array[];
extern u16 LedConfig_array_size;


#endif /* HAL_LED_CFG_H_ */
