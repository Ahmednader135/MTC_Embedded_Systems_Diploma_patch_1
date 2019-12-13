
#ifndef ICU_INT_H
#define ICU_INT_H


typedef enum
{
	ICU_FALLING_EDGE = 0,
	ICU_RISING_EDGE = 1

}EdgeTrigger_t;


extern void ICU_init(void);
extern stdReturnType_t ICU_getTimerCaptureVal(u16 * data);
extern stdReturnType_t ICU_isCaptureUpdated(u8 * status);
extern stdReturnType_t ICU_clearCaptureIntFlag(void);
extern stdReturnType_t ICU_captureIntStatus(u8 status);
extern stdReturnType_t ICU_setEdgeTrigger(EdgeTrigger_t edge);
extern void ICU_setCallBack(void (*ptrCpy) (void));

#endif
