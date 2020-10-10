/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef _COLOR_PATTERNS_H
    #define _COLOR_PATTERNS_H
    
    #include "cytypes.h"

     typedef struct {
                    uint8_t period;
                    uint8_t red;
                    uint8_t green;
                    uint8 typeRed;
                    uint8 typeGreen;
                    } Pattern;   

#endif

 Pattern PatternsVector[7] = {
                                 { 255,   0,   0, 3, 3 } ,
                                 { 255,   0, 127, 3, 3 },
                                 { 255, 127,   0, 1, 3 },
                                 { 127,  63,  63, 3, 1 },
                                 { 63,   31,  31, 1, 3 },
                                 { 255,  63, 127, 3, 3 },
                                 { 127, 127,  63, 3, 3 }
                              };

/* [] END OF FILE */
