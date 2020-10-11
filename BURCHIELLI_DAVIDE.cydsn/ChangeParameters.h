/* ============================
     author: Davide Burchielli
 * ============================
*/

#ifndef _CHANGE_PARAMETERS_H
    #define _CHANGE_PARAMETERS_H
    
    #include "ColorPatterns.h"
    /*
    #include "cytypes.h"

   // Create a new structure called Pattern which contains the PWM parameters
     typedef struct {
                    uint8_t period;  //PWM Period
                    uint8_t red;     //RED PWM channel Compare Value
                    uint8_t green;   //GREEN PWM channel Compare Value
                    uint8 typeRed;   //RED PWM channel Compare Mode
                    uint8 typeGreen; //GREEN PWM channel Compare Mode
                    } Pattern;   
    */
    void SwitchPattern (Pattern p); // Function prototype 

#endif



/* [] END OF FILE */
