/*
 * HAL_led.c
 *
 *  Created on: Oct 6, 2019
 *      Author: Abdelrahman.Elesh
 */

#include "std_types.h"
#include "DIO.h"
#include "HAL_led.h"
#include "HAL_led_cfg.h"

/*
 * Name:  initLed
 * brief: used to config. given pin where the led is connected as output
 * params:
 * 			IN: ledID : the name of the needed LED.
 *
 */
stdReturnType_t initLed(void)
{
	
	return SUCCESS;
}

/*
 * Name:  changeLedState
 * brief: used to write value to make given LED ON/OFF.
 * params:
 * 			IN: ledID : the name of the needed LED.
 * 			IN: pinState : the value of the pin HIGH/LOW.
 */
static stdReturnType_t changeLedState(u8 index, pinState_t pinState)
{
	stdReturnType_t retStatus = ERROR;
	
	retStatus = DIO_write(LedConfig_array[index].Port, LedConfig_array[index].Pin, pinState);

	return retStatus;
}

/*
 * Name:  changeLedState
 * brief: used to turn given LED ON.
 * params:
 * 			IN: ledID : the name of the needed LED.
 */
stdReturnType_t turnOnLed(ledX_t ledID)
{
	stdReturnType_t returnVal = ERROR;
	
	for(u8 i = 0;i < LedConfig_array_size;i++)
	{
		if(LedConfig_array[i].Led == ledID)
		{
			returnVal = changeLedState(i, PIN_IS_HIGH);
		}
	}
	
	return returnVal;
}

/*
 * Name:  changeLedState
 * brief: used to turn given LED OFF.
 * params:
 * 			IN: ledID : the name of the needed LED.
 */
stdReturnType_t turnOffLed(ledX_t ledID)
{
	stdReturnType_t returnVal = ERROR;
	
	for(u8 i = 0;i < LedConfig_array_size;i++)
	{
		if(LedConfig_array[i].Led == ledID)
		{
			returnVal = changeLedState(i, PIN_IS_LOW);
		}
	}
	
	return returnVal;
}

