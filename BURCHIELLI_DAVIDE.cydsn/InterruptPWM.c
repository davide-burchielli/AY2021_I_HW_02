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
#include "PWM_RG.h"


// Global variables
extern uint8_t status ;
extern uint8_t flag ;
extern  Pattern PatternsVector[7];

// Define PWN ISR:
CY_ISR (Custom_PWM_ISR)
{
    
    
    if (flag == 1)  // if flag == 1 means that the current pattern is the 7°
    {
        flag = 0;  
        if (PWM_RG_ReadCompare1() == 127) // If CMPType is "GREATER THAN", then
           PWM_RG_WriteCompare1(0);             // compare mode is set "LESS THAN"
        else 
           PWM_RG_WriteCompare1(127); // Otherwise CMPType is "LESS THAN", so it is changed
                                       // in "GREATER THAN"
    }

    PWM_RG_ReadStatusRegister(); // The interrupt line is brought down reading the PWN StatusResister
}

/* [] END OF FILE */
