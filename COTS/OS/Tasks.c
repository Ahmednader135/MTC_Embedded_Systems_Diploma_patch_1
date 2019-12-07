/*
 * Tasks.c
 *
 *  Created on: Dec 7, 2019
 *      Author: admin
 */

#include "registers.h"
#include "Tasks.h"


void LED_task(void)
{
	/* Toggle LED 0 */
	PORTD ^= (1<<5);
}


