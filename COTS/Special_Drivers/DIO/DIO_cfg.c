#include "std_types.h"
#include "DIO.h"
#include "DIO_cfg.h"


PinConfig_t PinConfig_array[] = 
							{
								{PORT_D, PIN5, OUTPUT},

							};

u16 PinConfig_array_size = sizeof(PinConfig_array)/sizeof(PinConfig_t);
