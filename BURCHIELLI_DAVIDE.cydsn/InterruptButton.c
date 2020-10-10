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
#include "InterruptButton.h"
#include "PWM_RG.h"
#include "RGBStripsDriver.h"
extern uint8_t status ;
extern uint8_t flag ;

CY_ISR (Custom_BUTTON_ISR)
{
    status = (status +1) % 8;
    
    if (status == 7)
    {
        flag = 1;
    }
    
    PWM_RG_WritePeriod(PatternsVector[status].period);
    PWM_RG_WriteCompare1(PatternsVector[status].red);
    PWM_RG_WriteCompare2(PatternsVector[status].green);
    PWM_RG_SetCompareMode1(PatternsVector[status].typeRed);
    PWM_RG_SetCompareMode1(PatternsVector[status].typeGreen);
    
}

/* [] END OF FILE */
