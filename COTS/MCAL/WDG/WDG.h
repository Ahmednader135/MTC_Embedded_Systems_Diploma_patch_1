/*
 * WDG.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Abdelrahman.Elesh
 */

#ifndef WDG_BUTTON_H_
#define WDG_BUTTON_H_

/************* Type def section ************/
typedef enum
{
	TIME_16_3_MS,
	TIME_32_5_MS,
	TIME_65_MS,
	TIME_130_MS,
	TIME_260_MS,
	TIME_520_MS,
	TIME_1000_MS,
	TIME_2100_MS,
	
}TimeConfig_t;



/************* Function declaration section ************/
extern stdReturnType_t WDG_Enable(TimeConfig_t timeConfiguration);
extern stdReturnType_t WDG_Disable(void);
extern stdReturnType_t WDG_Refresh(TimeConfig_t timeConfiguration);



#endif
