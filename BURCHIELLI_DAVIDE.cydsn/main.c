/* =====================================================================================
    author: Davide Burchielli
   
    The aim of this project is to drive a RGB LED strip with different blinking patterns.

    This main.c file defines and initializes flag and state global variables, starts the 
    PWM and ISRs and manages the uploading of the first pattern (state=1).
    Then, every other operations are managed by the ISRs, so the infinite loop is empty.
 * =====================================================================================
*/

#include "project.h"
#include "ColorPatterns.h"
#include "InterruptPWM.h"
#include "InterruptButton.h"
#include "ChangeParameters.h"

    
uint8_t state ;  // state variable identifies the current configuration, ie. the current colors patterns:
                 //state=1 --> 1° pattern , state=2 --> 2° pattern ...

uint8_t flag ;  // flag variable is used in order to notify Custom_PWM_ISR that the current pattern is 
                // the 7° (state = 7).

extern  Pattern PatternsVector[7]; // Patterns global variable 

int main(void)
{
    CyGlobalIntEnable; // Enable global interrupts
    
    state = 1;        // When the system is switched on, the 1° pattern must be loaded
    flag = 0;         // flag = 0 since state != 7

    PWM_RG_Start();    // Start PWM connected to RED and GREEN channels
    isr_BUTTON_StartEx(Custom_BUTTON_ISR); //Start the ISR of the button
    isr_PWM_StartEx(Custom_PWM_ISR);       //Start the ISR of the PWN
    
    SwitchPattern (PatternsVector[state-1]);  //Set the PWM parameters for the 1° pattern
    // NB: it is used [state-1] since the 1° pattern corresponds to the first element of the PatternsVector array,
    // which is in position/index 0.
    
    for(;;)  // empty infinite loop
    { }
}

/* [] END OF FILE */

