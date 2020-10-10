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
#ifndef _RGB_STRIPS_DRIVER_H
    #define _RGB_STRIPS_DRIVER_H
    
    #include "cytypes.h"
    
    typedef struct {
        uint8_t period;
        uint8_t red;
        uint8_t green;
        uint8 typeRed;
        uint8 typeGreen;
    } Pattern;
    
    Pattern PatternsVector[7];
    
    uint8_t status ;
    uint8_t flag ;
         
    void RGBStrips_SetPattern(Pattern p);
      
    
#endif



/* [] END OF FILE */
