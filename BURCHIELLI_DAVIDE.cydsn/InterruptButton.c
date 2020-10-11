/* =========================================================================================
    author: Davide Burchielli

    Custom_BUTTON_ISR is called every time the Switch Button is pressed.
    Its aim is to pass from the current configuration to the next one changing the Period,
    the Compare values and the Compare Mode of the 2 channels.
 * =========================================================================================
*/
#include "InterruptButton.h"
#include "ColorPatterns.h"
#include "PWM_RG.h"
#include "ChangeParameters.h"


// Global variables
extern uint8_t status ;
extern uint8_t flag ;
extern Pattern PatternsVector[7];

// Define the Button ISR
CY_ISR (Custom_BUTTON_ISR)
{
    status = (status +1) %7;  // Switch to the next pattern. 
                               // The modulus operation is applied so that when the current pattern is the 7°,
                               // status is set = 1 and so the 1° pattern is loaded.
    
    if (status == 6)  // If the pattern is the 7°, flag = 1 so that the operation in Custom_PWM_ISR can be performed
    {
        flag = 1;
    }
    
    // NB: it is used [status-1] since the first element of the array is in position 0 and
    // it corresponds to the 1° pattern
    PWM_RG_Stop();
    SwitchPattern (PatternsVector[status]);
    PWM_RG_Start();
}

/* [] END OF FILE */
