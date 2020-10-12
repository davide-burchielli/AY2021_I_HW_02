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
extern uint8_t state ;
extern uint8_t flag ;
extern Pattern PatternsVector[7];


// Define Custom_PWM_ISR
CY_ISR (Custom_PWM_ISR)
{
    
    PWM_RG_ReadStatusRegister(); // The interrupt line is brought low reading the PWN Status Resister
    
    if (flag == 1)  // if flag == 1 means that the current pattern is the 7°
    {
        if (PWM_RG_ReadCompare1() == 127) // If the PWM signal is LOW (note: CompareMode for pattern 7 = GREATER and Period=127)
            PWM_RG_WriteCompare1(0);      // then change the Compare value to make the PWM signal HIGH          
        else 
            PWM_RG_WriteCompare1(127);    // Otherwise the PWM signal is HIGH, change the Compare value to make the PWM signal LOW
    }
     
}

/* [] END OF FILE */
