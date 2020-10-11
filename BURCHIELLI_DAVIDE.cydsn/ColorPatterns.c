/* =========================================================================================
    author: Davide Burchielli/
    This file creates an array of 'Pattern' variables containing the 7 patterns 
 * =========================================================================================
*/

#include "ColorPatterns.h"

//NB for Compare mode values:
// 2 : PWM__B_PWM__LESS_THAN_OR_EQUAL
// 3 : PWM__B_PWM__GREATER_THAN

Pattern PatternsVector[7] = {
                                     { 255,   0,   0, 3, 3 } ,  // 1° pattern
                                     { 255,   0, 127, 3, 3 },   // 2° pattern
                                     { 255, 127,   0, 2, 3 },   // 3° pattern
                                     { 127,  63,  63, 2, 3 },   // 4° pattern
                                     { 63,   31,  31, 3, 2 },   // 5° pattern
                                     { 255, 192, 127, 2, 2 },  // 6° pattern
                                     { 127, 127,  63, 3, 2 }    // 7° pattern
                            };
            
     
/* [] END OF FILE */
