#include "std_types.h"
#include "OS.h"
#include "OS_cfg.h"
#include "Tasks.h"


TaskTCB_t TaskTCB_Tasks[] =
						{
							{LED_task,1000,TASK_READY}	
						};

u8 TaskCounter = sizeof(TaskTCB_Tasks)/sizeof(TaskTCB_t);