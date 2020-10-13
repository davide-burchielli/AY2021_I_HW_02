/* ==================================================================================================
    author: Davide Burchielli

    This file defines Custom_PWM_ISR, whose aim is to invert the value of RED_LED from HIGH to LOW 
    and vice versa, changing the RED Compare value(compare1) ONLY in the case of the 7° pattern. 
    Custom_PWM_ISR is called when isr_PWM is triggered by the rising edge of the 'On Terminal Count
    Event'. This happens when the Period parameter is = 0. Therefore, every time the Period is = 0,
    the value on the RED_LED is inverted, thus obtaing a PWM regulation with a period double of the
    GREEN_LED one, with a DutyCycle = 50%. 
 * ==================================================================================================
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
    
    if (flag == 1)  // if flag == 1 means that the current pattern is the 7° (Note: flag is reset on "InterruptButton.c" file)
    {
        if (PWM_RG_ReadCompare1() == 127) // If the PWM1 signal is LOW (note: CompareMode1 for pattern 7 = GREATER and Period=127)
            PWM_RG_WriteCompare1(0);      // then change the Compare value 1 to make PWM1 signal HIGH.
        else 
            PWM_RG_WriteCompare1(127);    // Otherwise the PWM1 signal is HIGH, change the Compare value to make PWM signal LOW.
    }
     
}

/* [] END OF FILE */
