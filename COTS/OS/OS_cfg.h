
#ifndef OS_CFG_H_
#define OS_CFG_H_

/************* Type def section ************/

/* Task data type */
typedef struct
{
	TaskRef_t TaskRef;
	u16 Periodicity;
	TaskState_t TaskState;

}TaskTCB_t;


extern TaskTCB_t TaskTCB_Tasks[];
extern u8 TaskCounter;

#endif
