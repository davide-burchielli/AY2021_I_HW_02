/* ==============================================================================================
    author: Davide Burchielli

    Custom_PWM_ISR is called when TC is = 1, so when the period is = 0, since the interrupt 
    of the PWN is set on "Interrupt On Terminal Count Event".
    The aim of this ISR is to invert the value of the RED channel from HIGH to LOW or viceversa,
    changing the CompareMode.
 * ==============================================================================================
*/
#include "InterruptPWM.h"
#include "ColorPatterns.h"
#include "PWM_RG.h"
#include "stdio.h" //////////////

// Global variables
extern uint8_t status ;
extern uint8_t flag ;
extern  Pattern PatternsVector[7];
extern char mess[20]; /////////////////////

// Define PWN ISR:
CY_ISR (Custom_PWM_ISR)
{
    UART_PutString("ISR_PWM CHIAMATA\n");
    PWM_RG_ReadStatusRegister(); // The interrupt line is brought down reading the PWN StatusResister
    if (flag == 1)  // if flag == 1 means that the current pattern is the 7°
    {
         UART_PutString("!!!!sono entrato\n");
 
         
        sprintf(mess, "DENTRO, FLAGGGG: %d \r\n", flag); /////////////////
         UART_PutString(mess); 
        if (PWM_RG_ReadCompare1() == 127) // If CMPType is "GREATER THAN", then
           {// PWM_RG_Stop();
            PWM_RG_WriteCompare1(0); 
            UART_PutString(".....cambio stato\n");
            //PWM_RG_Start();
            }// compare mode is set "LESS THAN"
        else 
         {// PWM_RG_Stop();
            PWM_RG_WriteCompare1(127); 
            UART_PutString("++++++++cambio stato\n");
           // PWM_RG_Start();
            }
            // Otherwise CMPType is "LESS THAN", so it is changed
                                       // in "GREATER THAN"
    }
    
    else UART_PutString("**non sono entrato\n");

    
}

/* [] END OF FILE */
