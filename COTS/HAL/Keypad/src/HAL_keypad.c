/*
 * HAL_keypad.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Abdelrahman
 */

#include "std_types.h"
#include "DIO.h"
#include "HAL_keyad_cfg.h"
#include "HAL_keypad.h"

#if (NUM_OF_COL == 4U)
const char KeyPad_4x4[NUM_OF_ROW][NUM_OF_COL] = {
								{'1','2','3','A'},
								{'4','5','6','B'},
								{'7','8','9','C'},
								{'*','0','#','D'}
							  };
//
//static const char KeyPad_4x4[NUM_OF_ROW][NUM_OF_COL] = {
//								{1,2,3,'A'},
//								{4,5,6,'B'},
//								{7,8,9,'C'},
//								{'*',0,'#','D'}
//							  };

static const pinX_t colPins[NUM_OF_COL] = {
									(pinX_t)KEYPAD_COL0_PIN, (pinX_t)KEYPAD_COL1_PIN,
									(pinX_t)KEYPAD_COL2_PIN, (pinX_t)KEYPAD_COL3_PIN
								   };

#elif (NUM_OF_COL == 3)

const char KeyPad_4x3[NUM_OF_ROW][NUM_OF_COL] =
							  {
								{1,2,3},
								{4,5,6},
								{7,8,9},
								{'*',0,'#'}
							  };
const pinX_t colPins[NUM_OF_COL] = {
									(pinX_t)KEYPAD_COL0_PIN, (pinX_t)KEYPAD_COL1_PIN,
									(pinX_t)KEYPAD_COL2_PIN
								   };

#endif

/*
 * Name:  initKeypad
 * brief: used to config and init the keypad pins.
 * params:
 * 			None.
 *
 */
stdReturnType_t initKeypad(void)
{
	stdReturnType_t retStatus = ERROR;

	/* Set the columns' directions as inputs */
	retStatus = DIO_init(KEYPAD_PORT, KEYPAD_COL0_PIN, INPUT);
    retStatus |= DIO_init(KEYPAD_PORT, KEYPAD_COL1_PIN, INPUT);
    retStatus |= DIO_init(KEYPAD_PORT, KEYPAD_COL2_PIN, INPUT);

	#if (NUM_OF_COL == 4U)
    retStatus |= DIO_init(KEYPAD_PORT, KEYPAD_COL3_PIN, INPUT);
	#endif

    /* enable internal pull-up for the columns */
    retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_COL0_PIN, PIN_IS_HIGH);
    retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_COL1_PIN, PIN_IS_HIGH);
    retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_COL2_PIN, PIN_IS_HIGH);

	#if (NUM_OF_COL == 4U)
    retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_COL3_PIN, PIN_IS_HIGH);
	#endif

    /* Set the rows as directions outputs */
	retStatus |= DIO_init(KEYPAD_PORT, KEYPAD_ROW0_PIN, OUTPUT);
    retStatus |= DIO_init(KEYPAD_PORT, KEYPAD_ROW1_PIN, OUTPUT);
    retStatus |= DIO_init(KEYPAD_PORT, KEYPAD_ROW2_PIN, OUTPUT);
    retStatus |= DIO_init(KEYPAD_PORT, KEYPAD_ROW3_PIN, OUTPUT);

    /* Set*/
	retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_ROW0_PIN, PIN_IS_HIGH);
    retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_ROW1_PIN, PIN_IS_HIGH);
    retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_ROW2_PIN, PIN_IS_HIGH);
    retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_ROW3_PIN, PIN_IS_HIGH);


    return retStatus;
}

/*
 * Name:  getPressedKey_keypad
 * brief: used to get the pressed button of keypad.
 * params:
 * 			OUT: buttonID : pointer to the value of pressed key.
 *
 */
stdReturnType_t getPressedKey_keypad(char * pPressedKey)
{
	stdReturnType_t retStatus = ERROR;
	u8 col = 0; /* index for columns */
	u8 row = 0; /* index for rows */
	pinState_t pinstate;

	*pPressedKey = 'H'; /* Initialized to some invalid char */


	/* loop on keypad matrix to get pressed key if any */
	for(row = 0; row < NUM_OF_ROW; row++)
	{
		retStatus  = DIO_write(KEYPAD_PORT, KEYPAD_ROW0_PIN, GET_ROW_PIN_VAL(row, ROW0_MSK));
		retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_ROW1_PIN, GET_ROW_PIN_VAL(row, ROW1_MSK));
		retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_ROW2_PIN, GET_ROW_PIN_VAL(row, ROW2_MSK));
		retStatus |= DIO_write(KEYPAD_PORT, KEYPAD_ROW3_PIN, GET_ROW_PIN_VAL(row, ROW3_MSK));

		for(col = 0; col < NUM_OF_COL; col++)
		{

			retStatus |= DIO_read(KEYPAD_PORT, colPins[col], &pinstate);

			/* check if key is  pressed in this column */
			if(PIN_IS_LOW == pinstate)
			{
				#if (NUM_OF_COL == 4)
				*pPressedKey = KeyPad_4x4[row][col];
				#elif (NUM_OF_COL == 3)
				*pPressedKey = KeyPad_4x3[row][col];
				#endif

				/* break from loops */
				row = NUM_OF_ROW;
				col = NUM_OF_COL;
			}
			else
			{
				/* Do nothing S*/
			}


		}
	}


	return retStatus;
}
