/* =========================================================================================
    author: Davide Burchielli

    Custom_BUTTON_ISR is called every time the Switch Button is pressed.
    Its aim is to pass from the current configuration to the next one changing the Period,
    the Compare values and the Compare Mode of the 2 channels.
 * =========================================================================================
*/
#include "InterruptButton.h"
#include "ColorPatterns.h"
#include "PWM_RG.h"
#include "ChangeParameters.h"
#include "stdio.h" //////////////


// Global variables
extern uint8_t status ;
extern uint8_t flag ;
extern Pattern PatternsVector[7];

extern char mess[20]; /////////////////////

// Define the Button ISR
CY_ISR (Custom_BUTTON_ISR)
{
    sprintf(mess, "status prima: %d \r\n", status); /////////////////
    UART_PutString(mess);
    
    status = (status +1) %8;  // Switch to the next pattern. 
                               // The modulus operation is applied so that when the current pattern is the 7°,
                               // status is set = 1 and so the 1° pattern is loaded.
    sprintf(mess, "status dopo: %d \r\n", status); /////////////////
    UART_PutString(mess);
    if (status == 7)  // If the pattern is the 7°, flag = 1 so that the operation in Custom_PWM_ISR can be performed
    {
        flag = 1;
       sprintf(mess, "FLAGGGG: %d \r\n", flag); /////////////////
         UART_PutString(mess); 
    }
    else flag=0;
    
    // NB: it is used [status-1] since the first element of the array is in position 0 and
    // it corresponds to the 1° pattern
    PWM_RG_Stop();
    SwitchPattern (PatternsVector[status-1]);
    PWM_RG_Start();
}

/* [] END OF FILE */
