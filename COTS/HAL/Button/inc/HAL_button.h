/*
 * HAL_button.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Abdelrahman.Elesh
 */

#ifndef HAL_BUTTON_H_
#define HAL_BUTTON_H_

/************* Type def section ************/
typedef enum
{
	BUTTON0,
	BUTTON1,
	BUTTON2,
	MAX_NUM_OF_BUTTONS
}buttonX_t;

typedef enum
{
	BUTTON_NOT_PRESSED,
	BUTTON_PRESSED
}buttonState_t;


/************* Function declaration section ************/
extern stdReturnType_t initButton(buttonX_t buttonID);
extern stdReturnType_t getButtonState(buttonX_t buttonID, buttonState_t * pbuttonState);


#endif /* HAL_BUTTON_H_ */
