/*
 * HAL_keypad.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Abdelrahman
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_



/************* Macros def section ************/
#define ROW0_MSK	0x01U
#define ROW1_MSK	0x02U
#define ROW2_MSK	0x04U
#define ROW3_MSK	0x08U

#define GET_ROW_PIN_VAL(ROW, MSK)	( !((( (1<<(ROW)) & (MSK)) >> ROW)) )

/************* Function declaration section ************/
extern stdReturnType_t initKeypad(void);
extern stdReturnType_t getPressedKey_keypad(char * pPressedKey);


#endif /* HAL_KEYPAD_H_ */
