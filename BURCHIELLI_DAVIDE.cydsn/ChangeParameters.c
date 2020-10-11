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


#include "ChangeParameters.h"
#include "project.h"

void SwitchPattern ( Pattern p)
{
    // Change the PWM parameters :
    
    PWM_RG_WritePeriod(p.period);
    PWM_RG_WriteCompare1(255 - p.red);   // Subtract from 255 the Compare value since the LED is in common anode configuration
    PWM_RG_WriteCompare2(255 - p.green); // Subtract from 255 the Compare value since the LED is in common anode configuration
    PWM_RG_SetCompareMode1(p.typeRed);
    PWM_RG_SetCompareMode2(p.typeGreen);

}



/* [] END OF FILE */
