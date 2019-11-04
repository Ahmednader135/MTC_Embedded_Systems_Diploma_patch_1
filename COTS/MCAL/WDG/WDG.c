/*
 * WDG.c
 *
 *  Created on: Oct 6, 2019
 *      Author: Abdelrahman.Elesh
 */

#include "LIB/std_types.h"
#include "LIB/bit_math.h"
#include "LIB/registers.h"
#include "WDG.h"
#include "WDG_cfg.h"

stdReturnType_t WDG_Enable(TimeConfig_t timeConfiguration)
{
	stdReturnType_t returnVal = SUCCESS;
	
	WDTCR &= ~0x07;
	
	switch(timeConfiguration)
	{
		case TIME_16_3_MS:	
			WDTCR |= (1<<3) | TIME_16_3_MS;	
		break;
		
		case TIME_32_5_MS:	
			WDTCR |= (1<<3) | TIME_32_5_MS;	
		break;
		
		case TIME_65_MS:	
			WDTCR |= (1<<3) | TIME_65_MS;	
		break;
		
		case TIME_130_MS:	
			WDTCR |= (1<<3) | TIME_130_MS;	
		break;
		
		case TIME_260_MS:	
			WDTCR |= (1<<3) | TIME_260_MS;	
		break;
		
		case TIME_520_MS:	
			WDTCR |= (1<<3) | TIME_520_MS;	
		break;
		
		case TIME_1000_MS:	
			WDTCR |= (1<<3) | TIME_1000_MS;	
		break;
		
		case TIME_2100_MS:	
			WDTCR |= (1<<3) | TIME_2100_MS;	
		break;
		
		default:
			returnVal = ERROR;
	}
	
	return returnVal;
	
	
}
stdReturnType_t WDG_Disable(void)
{
	WDTCR |= (1<<3) | (1<<4);
	WDTCR = 0;
	
	return SUCCESS;
}
stdReturnType_t WDG_Refresh(TimeConfig_t timeConfiguration)
{
	stdReturnType_t returnVal = SUCCESS;
	
	WDG_Disable();
	
	if(SUCCESS != WDG_Enable(timeConfiguration))
	{
		returnVal = ERROR;
	}
	
	return returnVal;
}
