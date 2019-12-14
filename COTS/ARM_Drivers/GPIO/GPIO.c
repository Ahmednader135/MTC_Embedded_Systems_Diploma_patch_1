/*
 * GPIO.c
 *
 *  Created on: Dec 14, 2019
 *      Author: admin
 */

#include <stdint.h>
#include "GPIO.h"

void GPIO_init(GPIO_Type * PORT, uint8_t pinNumber,PinDirection_t direction,PinPullUpAndDown_t pullUpDown)
{


    if(direction == OUTPUT)
    {
        PORT->DIR |= (1<<pinNumber);
    }
    else
    {
        PORT->DIR &= ~(1<<pinNumber);
    }

    PORT->DEN |= (1<<pinNumber);

    if(pullUpDown == PULL_UP)
    {
        PORT->PUR |= (1<<pinNumber);
    }
    else if(pullUpDown == PULL_DOWN)
    {
        PORT->PDR |= (1<<pinNumber);
    }
    else
    {

    }
}


void GPIO_write(GPIO_Type * PORT, uint8_t pinNumber,PinState_t state)
{
    if(state == HIGH)
    {
        PORT->DATA |= (1<<pinNumber);
    }
    else
    {
        PORT->DATA &= ~(1<<pinNumber);
    }

}
PinState_t GPIO_read(GPIO_Type * PORT, uint8_t pinNumber)
{
    if( (PORT->DATA & (1<<pinNumber)) != 0)
    {
        return HIGH;
    }
    else
    {
        return LOW;
    }
}



