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
#include "InterruptPWM.h"
#include "RGBStripsDriver.h"
//#include "PWM_RG.h"

CY_ISR (Custom_PWM_ISR)
{
    if (flag == 1)
    {
        flag = 0;
        if (PatternsVector[status].typeRed == 3) //if CMP is "GREATER THAN" 
            PWM_RG_SetCompareMode1(1); // set it "LESS THAN"
        else 
            PWM_RG_SetCompareMode1(3); // set it "GREATER THAN"
    
    }
    
    PWM_RG_ReadStatusRegister(); 
}

/* [] END OF FILE */
