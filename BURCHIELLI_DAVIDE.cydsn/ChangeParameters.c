/* ========================================
    author: Davide Burchielli
 * ========================================
*/


#include "ChangeParameters.h"
#include "project.h"

void SwitchPattern ( Pattern p)
{
    // Change the PWM parameters :
    PWM_RG_WritePeriod ( p.period );
    PWM_RG_WriteCompare1( p.period - p.red );   // Subtract the Compare value from the period parameter since the LED is in common anode configuration
    PWM_RG_WriteCompare2( p.period - p.green ); // Subtract the Compare value from the period parameter since the LED is in common anode configuration
    PWM_RG_SetCompareMode1( p.typeRed );
    PWM_RG_SetCompareMode2( p.typeGreen );
    
}



/* [] END OF FILE */
