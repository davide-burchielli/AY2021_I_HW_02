/* ===============================================================================
    author: Davide Burchielli

    This file defines the function SwitchPattern which takes as input a Pattern
    variable p (an element of the PatternsVector array) and updates PWM
    parameters.
    
    NB: for WriteCompare1 and WriteCompare2 function, the Compare value is
    subtracted from the Period since the LEDs are in common anode configuration
 * ===============================================================================
*/

#include "ChangeParameters.h"
#include "project.h"

void SwitchPattern ( Pattern p)
{
    // Change PWM parameters :

    PWM_RG_WritePeriod  ( p.period );  //Chage the PWM period
    PWM_RG_WriteCompare1( p.period - p.red );  //Chage the pwm1 (RED) Compare value
    PWM_RG_WriteCompare2( p.period - p.green ); //Chage the pwm2 (GREEN) Compare value
    PWM_RG_SetCompareMode1( p.typeRed ); //Chage the pwm1 (RED) Compare mode
    PWM_RG_SetCompareMode2( p.typeGreen ); //Chage the pwm2 (GREEN) Compare mode

}

/* [] END OF FILE */
