/* =========================================================================================
    author: Davide Burchielli

    Custom_BUTTON_ISR is called every time the Switch Button is pressed.
    Its aim is to pass from the current configuration to the next one changing the Period,
    the Compare values and the Compare Mode of the 2 channels.
 * =========================================================================================
*/
#include "InterruptButton.h"
#include "PWM_RG.h"
#include "ColorPatterns.h"

// Global variables
extern uint8_t status ;
extern uint8_t flag ;

// Define the Button ISR
CY_ISR (Custom_BUTTON_ISR)
{
    status = (status +1) % 8;  // Switch to the next pattern. 
                               // The modulus operation is applied so that when the current pattern is the 7°,
                               // status is set = 1 and so the 1° pattern is loaded.
    
    if (status == 7)  // If the pattern is the 7°, flag = 1 so that the operation in Custom_PWM_ISR can be performed
    {
        flag = 1;
    }
    
    
    // Change the PWM parameters :
    // NB: it is used [status-1] since the first element of the array is in position 0 and
    // it corresponds to the 1° pattern
    
    PWM_RG_WritePeriod(PatternsVector[status-1].period);
    PWM_RG_WriteCompare1(255 - PatternsVector[status-1].red);   // Subtract from 255 the Compare value since the LED is in common anode configuration
    PWM_RG_WriteCompare2(255 - PatternsVector[status-1].green); // Subtract from 255 the Compare value since the LED is in common anode configuration
    PWM_RG_SetCompareMode1(PatternsVector[status-1].typeRed);
    PWM_RG_SetCompareMode2(PatternsVector[status-1].typeGreen);
    
}

/* [] END OF FILE */
