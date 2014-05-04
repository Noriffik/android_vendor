/*******************************************************************************
 * $Copyright ST-Ericsson 2009 $
 ******************************************************************************/
#ifndef _R_TIME_UTILITIES_H_
#define _R_TIME_UTILITIES_H_
/**
 * @addtogroup ldr_time_utilities Timer utilities
 * Can be created and handled 255 timers. Every timer can be the periodical or
 * non-periodical. The maximum time that can be set is 0xFFFFFFFF seconds.
 * Timer is count-down counter and when time is 0 the timer will finish and can
 * be called callback function if is defined, when timer is registered.
 *
 * @{
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include  "t_time_utilities.h"
#include  "error_codes.h"

/*******************************************************************************
 * Declaration of functions
 ******************************************************************************/

/**
 * Initialization of the Timers handler.
 *
 * @param [in] Object_p   pointer to LCM instance context.
 * @param [in] Timers     Numbers of defined timers.
 *
 * @retval  E_SUCCESS   After successful execution.
 * @retval  E_INVALID_INPUT_PARAMETERS If no timer s for initialization.
 */
ErrorCode_e Do_Timer_TimersInit(void *Object_p, uint32 Timers);

/**
 * Reserve new timer.
 *
 * @param [in] Object_p   pointer to LCM instance context.
 * @param [in] Timer_p    pointer to the timer data.
 *
 * @return Index of reserved timer.
 * @return Index 0 if no free timers.
 */
uint32 Do_Timer_TimerGet(void *Object_p, Timer_t *Timer_p);

/**
 * Release reserved timer.
 *
 * @param [in] Object_p   pointer to LCM instance context.
 * @param [in] TimerKey   Index of reserved timer.
 *
 * @retval E_SUCCESS    After successful execution.
 * @retval E_INVALID_INPUT_PARAMETERS If one of the input.
 * @retval E_NONEXIST_TIMER non exist timer.
 */
ErrorCode_e Do_Timer_TimerRelease(void *Object_p, uint32 TimerKey);

/**
 * Read the current time of timer.
 *
 * @param [in] Object_p   pointer to LCM instance context.
 * @param [in] TimerKey   Index of reserved timer.
 *
 * @return current time.
 */
uint32 Do_Timer_ReadTime(void *Object_p, uint32 TimerKey);

/**
 * Get current system time.
 *
 * @param [in] Object_p   pointer to LCM instance context.
 *
 * @return System Time.
 */
uint32 Do_Timer_GetSystemTime(void *Object_p);


/**
 * On every 10mS, timer interrurpt handler will execute this timer handler.
 *
 * @return none.
 */
#ifdef CFG_ENABLE_LOADER_TYPE
void Do_Timer_TimersHandler(void);
#else
void Do_Timer_TimersHandler(void *Object_p);
#endif

/** @} */
#endif /*_R_TIME_UTILITIES_H_*/