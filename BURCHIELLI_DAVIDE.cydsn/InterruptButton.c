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
extern uint8_t state ;
extern uint8_t flag ;
extern Pattern PatternsVector[7];


// Define the Button ISR
CY_ISR (Custom_BUTTON_ISR)
{
    state = (state +1) %8;  // Switch to the next pattern. 
                               // The modulus operation is applied so that when the current pattern is the 7°,
                               // state is set = 1 and so the 1° pattern is loaded.
    
    if (state == 0) //If the state = 0, it is then set = 1 to switch to the 1° pattern
        state=1;
    
    if (state == 7)  // If the pattern is the 7°, flag = 1 so that the operation in Custom_PWM_ISR can be performed
        flag = 1;
    else
        flag = 0;   //Otherwise set it = 0
    
   
    SwitchPattern (PatternsVector[state-1]);  // Call the function PatternVector to switch to the next pattern
    // NB: it is used [state-1] since the first element of the array is in position 0 and
    // it corresponds to the 1° pattern
}

/* [] END OF FILE */
