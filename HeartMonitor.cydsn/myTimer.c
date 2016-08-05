/* ========================================

 * ========================================
*/

#include <project.h>
#include "myTimer.h"
#include "testSpeak.h"

static CY_ISR_PROTO(TimerIsr);

uint16 timerCount = 0;

uint16 offset = 0;

// (10ms interrupt)
static CY_ISR(TimerIsr)
{
    (void)Timer_1_ReadStatusRegister();
    timerCount++;
    
    if(timerCount >= 100)
    {
        timerCount=0;
        Pin_LED1_Write(!Pin_LED1_Read());
    }
    
    if (offset >= sin1000Size)
    {
        offset = 0;
    }
    VDAC8_SetValue( sin1000[offset ] );
    offset++;
    

} /* end of TimerIsr() */
//! @brief Initialize timer interrupt
//!
void InitTiming(void)
{
    isr_Timer_Start();
    /* set the interrupt's ISR function to be the one in this file */
    isr_Timer_SetVector(TimerIsr);
    
    
} /* end of InitTiming() */

/* [] END OF FILE */
