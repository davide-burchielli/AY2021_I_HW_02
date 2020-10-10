/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "ColorPatterns.h"
#include "RGBStripsDriver.h"
#include "InterruptPWM.h"
#include "InterruptButton.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_RG_Start();
    
    isr_BUTTON_StartEx(Custom_BUTTON_ISR);
    isr_PWM_StartEx(Custom_PWM_ISR);
    
    for(;;)
    {
        
    }
}

/* [] END OF FILE */
