/* ==============================================================================================
    author: Davide Burchielli

    Custom_PWM_ISR is called when TC is = 1, so when the period is = 0, since the interrupt 
    of the PWN is set on "Interrupt On Terminal Count Event".
    The aim of this ISR is to invert the value of the RED channel from HIGH to LOW or viceversa,
    changing the CompareMode.
 * ==============================================================================================
*/
#include "InterruptPWM.h"
#include "ColorPatterns.h"

// Global variables
extern uint8_t status ;
extern uint8_t flag ;

// Define PWN ISR:
CY_ISR (Custom_PWM_ISR)
{
    PWM_RG_ReadStatusRegister(); // The interrupt line is brought down reading the PWN StatusResister
    
    if (flag == 1)  // if flag == 1 means that the current pattern is the 7°
    {
        flag = 0;  
        if (PatternsVector[status-1].typeRed == 3) // If CMPType is "GREATER THAN", then
            PWM_RG_SetCompareMode1(2);             // compare mode is set "LESS THAN"
        else 
            PWM_RG_SetCompareMode1(3); // Otherwise CMPType is "LESS THAN", so it is changed
                                       // in "GREATER THAN"
    }

}

/* [] END OF FILE */
