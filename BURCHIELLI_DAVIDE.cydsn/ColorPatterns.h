/* =========================================================================================
    author: Davide Burchielli
 * =========================================================================================
*/
/*
#include "ChangeParameters.h"

// Create an array of Pattern varaibles containing the 7 patterns 
//NB for Compare mode values:
// 2 : PWM__B_PWM__LESS_THAN_OR_EQUAL
// 3 : PWM__B_PWM__GREATER_THAN
 const Pattern PatternsVector[7] = {
                                     { 255,   0,   0, 3, 3 } ,  // 1° pattern
                                     { 255,   0, 127, 3, 3 },   // 2° pattern
                                     { 255, 127,   0, 2, 3 },   // 3° pattern
                                     { 127,  63,  63, 3, 2 },   // 4° pattern
                                     { 63,   31,  31, 2, 3 },   // 5° pattern
                                     { 255,  63, 127, 3, 3 },   // 6° pattern
                                     { 127, 127,  63, 3, 3 }    // 7° pattern
                                  };
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
