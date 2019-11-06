/*
 * HAL_led.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Abdelrahman.Elesh
 */

#ifndef HAL_LED_H_
#define HAL_LED_H_

/************* Type def section ************/
typedef enum
{
	LED0,
	LED1,
	LED2,
	MAX_NUM_OF_LEDS
}ledX_t;


/************* Function declaration section ************/
extern stdReturnType_t initLed(void);
extern stdReturnType_t turnOnLed(ledX_t ledID);
extern stdReturnType_t turnOffLed(ledX_t ledID);


#endif /* HAL_LED_H_ */
