/* =========================================================================================
    author: Davide Burchielli
 * =========================================================================================
*/
      

#ifndef _COLOR_PATTERNS_H
    #define _COLOR_PATTERNS_H
    
    #include "cytypes.h"

   // Create a new structure called Pattern which contains the PWM parameters
     typedef struct {
                    uint8_t period;  //PWM Period
                    uint8_t red;     //RED PWM channel Compare Value
                    uint8_t green;   //GREEN PWM channel Compare Value
                    uint8 typeRed;   //RED PWM channel Compare Mode
                    uint8 typeGreen; //GREEN PWM channel Compare Mode
                    } Pattern;  
    
#endif 


/* [] END OF FILE */
