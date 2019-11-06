#include "std_types.h"
#include "HAL_led.h"
#include "DIO.h"
#include "HAL_led_cfg.h"


LedConfig_t LedConfig_array[] = 
							{
								{LED0 , PORT_D, PIN5},
	
							};
u16 LedConfig_array_size = sizeof(LedConfig_array)/sizeof(LedConfig_t);
