/* =========================================================================================
    author: Davide Burchielli

    Custom_BUTTON_ISR is called every time the Switch_Button is pressed.
    Its aim is to manage the switch from the current configuration to the next one, calling
    the SwitchPattern function to which it passes as input the pattern that must be update.
 * =========================================================================================
*/

#include "InterruptButton.h"
#include "ColorPatterns.h"
#include "ChangeParameters.h"


// Global variables
extern uint8_t state ;
extern uint8_t flag ;
extern Pattern PatternsVector[7];


// Define Custom_BUTTON_ISR
CY_ISR (Custom_BUTTON_ISR)
{
    state ++;       // Increment the state.
    if (state == 8) // If the state = 8, means that the last pattern was the 7° 
        state = 1;  // so set state = 1 to switch to the 1° pattern.
        
    
    if (state == 7)  // If the pattern is the 7°, flag = 1 so that the operation in Custom_PWM_ISR can be performed
        flag = 1;
    else
        flag = 0;   //Otherwise (every time state !=7) set flag = 0  (to reset it and therefore being sure that it is not = 1)
    
    SwitchPattern (PatternsVector[state-1]);  // Call the function PatternVector to switch to the next pattern
   
    // NB: it is used [state-1] since the state-th pattern corresponds to the state-th element of the array, which is in position [state-1].

}

/* [] END OF FILE */
