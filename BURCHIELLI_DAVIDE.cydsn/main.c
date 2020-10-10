/* =====================================================================================
    author: Davide Burchielli
   
    The aim of this project is to drive a RGB LED strip with different blinking patterns.
 * =====================================================================================
*/
#include "project.h"
#include "ColorPatterns.h"
#include "InterruptPWM.h"
#include "InterruptButton.h"

    
uint8_t status ; // status variable identify the current configuration, ie. the current colors patterns. 
uint8_t flag ;  // flag variable is used in order to notify Custom_PWM_ISR, in the case of the 7° pattern,
                // When the period of the PWM is finished so that is possible to deal with the 2 patterns
                // of the RED and GREEN channels that have different PWM periods but using just one PWN component
//extern const Pattern PatternsVector[7];

int main(void)
{
    CyGlobalIntEnable; // Enable global interrupts
    
    status = 1;        // When the system is switched on the first pattern is loaded
    flag = 0;          // flag is = 1 only when the 7° pattern is loaded
    
    PWM_RG_Start();    // Start PWM connected to RED and GREEN channels
    
    PWM_RG_WritePeriod(127);
    PWM_RG_WriteCompare1(127);   // Subtract from 255 the Compare value since the LED is in common anode configuration
    PWM_RG_WriteCompare2(127); // Subtract from 255 the Compare value since the LED is in common anode configuration
    PWM_RG_SetCompareMode1(2);
    PWM_RG_SetCompareMode2(2);
    
    
    isr_BUTTON_StartEx(Custom_BUTTON_ISR); //Start the ISR of the button
    isr_PWM_StartEx(Custom_PWM_ISR);       //Start the ISR of the PWN
    
    for(;;)
    {
        
    }
}

/* [] END OF FILE */

