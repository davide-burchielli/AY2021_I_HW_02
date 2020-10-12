/* =========================================================================================
    author: Davide Burchielli

    This file creates an array of 'Pattern' variables containing the 7 patterns 
    //NB for Compare mode values (defined in PWM_RG.h file)
    // 2 : PWM__B_PWM__LESS_THAN_OR_EQUAL
    // 3 : PWM__B_PWM__GREATER_THAN
 * =========================================================================================
*/

#include "ColorPatterns.h"

Pattern PatternsVector[7] = {
                                     { 255,   0,   0, 3, 3 } ,  // 1° pattern
                                     { 255,   0, 127, 3, 2 },   // 2° pattern
                                     { 255, 127,   0, 3, 3 },   // 3° pattern
                                     { 127,  63,  63, 2, 3 },   // 4° pattern
                                     { 63,   31,  31, 3, 2 },   // 5° pattern
                                     { 255, 192, 127, 2, 2 },   // 6° pattern
                                     { 127, 127,  63, 3, 2 }    // 7° pattern
                            };

/* [] END OF FILE */
