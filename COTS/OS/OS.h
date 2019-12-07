
#ifndef OS_H_
#define OS_H_

/************* Type def section ************/


typedef void (*TaskRef_t)(void);

typedef enum
{
	TASK_READY,
	TASK_RUNNING,
	TASK_SUSPENDED,
	TASK_BLOCKED,	
}TaskState_t;




/************ Function declaration section ***********/

extern stdReturnType_t OS_init(void);
extern stdReturnType_t OS_startScheduler(void);
extern stdReturnType_t OS_taskSuspend(TaskRef_t taskRef);
extern stdReturnType_t OS_taskResume(TaskRef_t taskRef);
extern void OS_tickHandler(void);




#endif 
