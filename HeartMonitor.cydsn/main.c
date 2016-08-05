/* ========================================
    Talking Heart Rate Monitor
 * ========================================
*/
#include <project.h>
#include "myTimer.h"
#include "testSpeak.h"
int main()
{
    uint16 i=0;
    Opamp_1_Start();
    VDAC8_Start();
    LCD_Char_Start();
    Timer_1_Start();
    Clock_Timer_Start();
    InitTiming();

    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Char_ClearDisplay();
    LCD_Char_Position(0,0);
    LCD_Char_PrintString("hello");
    for(;;)
    {
        //LCD_Char_Position(1,0);
        //LCD_Char_PrintHexUint8(23);
        //VDAC8_SetValue( (uint8) 0x127 );

    }
}

/* [] END OF FILE */
