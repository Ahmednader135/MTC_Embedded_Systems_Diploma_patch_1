#include "std_types.h"
#include "OS.h"
#include "OS_cfg.h"
#include "TIM0.h"



u32 TickCounter = 0;
u8 TickFlag = 0;


stdReturnType_t OS_init(void)
{
	/* Ensure that lookup table is not empty */
	/* Set OS callback for sysTick */
	TIM0_setCmIntCallback(OS_tickHandler);

	return SUCCESS;
}
stdReturnType_t OS_startScheduler(void)
{
	while(1)
	{
		if(TickFlag == 1)
		{
			TickFlag = 0;

			for(u8 i = 0;i < TaskCounter;i++)
			{
				/* Check task state is ready */
				if(TaskTCB_Tasks[i].TaskState == TASK_READY)
				{
					/* Check periodicity */

					if(TickCounter % TaskTCB_Tasks[i].Periodicity == 0)
					{
						/* Task in running */
						TaskTCB_Tasks[i].TaskState = TASK_RUNNING;
						/* Call the task */
						TaskTCB_Tasks[i].TaskRef();
						/* Task in running */
						TaskTCB_Tasks[i].TaskState = TASK_READY;
					}
				}
			}

		}
	}
	return SUCCESS;
}
stdReturnType_t OS_taskSuspend(TaskRef_t taskRef)
{
	for(u8 i = 0;i < TaskCounter;i++)
	{
		/* Find the task */
		if(TaskTCB_Tasks[i].TaskRef == taskRef)
		{
			TaskTCB_Tasks[i].TaskState = TASK_SUSPENDED;
		}
	}
	return SUCCESS;	
}
stdReturnType_t OS_taskResume(TaskRef_t taskRef)
{
	for(u8 i = 0;i < TaskCounter;i++)
	{
		/* Find the task */
		if(TaskTCB_Tasks[i].TaskRef == taskRef)
		{
			TaskTCB_Tasks[i].TaskState = TASK_READY;
		}
	}
	return SUCCESS;
}


void OS_tickHandler(void)
{
	/* Increment tickCounter */
	TickCounter++;
	/* Incidate sysTick occured */
	TickFlag = 1;
}
