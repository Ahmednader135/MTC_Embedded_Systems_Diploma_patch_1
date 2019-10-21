/*
 * HAL_keyad_cfg.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Abdelrahman
 */

#ifndef HAL_KEYAD_CFG_H_
#define HAL_KEYAD_CFG_H_


/************* Macros def section ************/

#define	NUM_OF_ROW	4U
#define NUM_OF_COL	4U


#define KEYPAD_PORT	PORT_A

//#define KEYPAD_ROW0_PIN PIN0
//#define KEYPAD_ROW1_PIN PIN1
//#define KEYPAD_ROW2_PIN PIN2
//#define KEYPAD_ROW3_PIN PIN3
//
//#define KEYPAD_COL0_PIN PIN4
//#define KEYPAD_COL1_PIN PIN5
//#define KEYPAD_COL2_PIN PIN6
//#define KEYPAD_COL3_PIN PIN7


#define KEYPAD_ROW0_PIN	PIN7
#define KEYPAD_ROW1_PIN PIN6
#define KEYPAD_ROW2_PIN PIN5
#define KEYPAD_ROW3_PIN PIN4

#define KEYPAD_COL0_PIN	PIN3
#define KEYPAD_COL1_PIN	PIN2
#define KEYPAD_COL2_PIN PIN1
#define KEYPAD_COL3_PIN PIN0

#endif /* HAL_KEYAD_CFG_H_ */
