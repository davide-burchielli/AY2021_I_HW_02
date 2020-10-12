/* =========================================================================================
    author: Davide Burchielli
    
    This file creates a new structure called 'Pattern' which contains the PWM parameters.
 * =========================================================================================
*/
      
#ifndef _COLOR_PATTERNS_H
    #define _COLOR_PATTERNS_H
    
    #include "cytypes.h"

     typedef struct {
                    uint8_t period;  //PWM Period
                    uint8_t red;     //RED PWM channel (PWM1) Compare Value
                    uint8_t green;   //GREEN PWM channel (PWM2) Compare Value
                    uint8 typeRed;   //RED PWM channel (PWM1) Compare Mode
                    uint8 typeGreen; //GREEN PWM channel (PWM1) Compare Mode
                    } Pattern;  
    
#endif 

/* [] END OF FILE */
