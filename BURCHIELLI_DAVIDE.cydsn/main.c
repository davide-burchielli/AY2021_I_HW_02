/* =====================================================================================
    author: Davide Burchielli
   
    The aim of this project is to drive a RGB LED strip with different blinking patterns.
 * =====================================================================================
*/
#include "project.h"
#include "ColorPatterns.h"
#include "InterruptPWM.h"
#include "InterruptButton.h"
#include "ChangeParameters.h"
#include "stdio.h"

    
uint8_t status ; // status variable identify the current configuration, ie. the current colors patterns:
                 //status=1 --> 1° pattern , status=2 --> 2° pattern ...

uint8_t flag ;  // flag variable is used in order to notify Custom_PWM_ISR, in the case of the 7° pattern,
                // when the period of the PWM is finished so that is possible to deal with the 2 patterns
                // of the RED and GREEN channels that have different PWM periods but using just one PWN component

// Global variable 
extern  Pattern PatternsVector[7];
char mess[20] = {'\0'};

int main(void)
{
    CyGlobalIntEnable; // Enable global interrupts
    
    UART_Start();
    UART_PutString("Acceso\r\n");
    
    status = 1;        // When the system is switched on the first pattern is loaded
    flag = 0;          // flag is = 1 only when the 7° pattern is loaded
    
    PWM_RG_Start();    // Start PWM connected to RED and GREEN channels
    SwitchPattern (PatternsVector[status-1]);  //Set the PWM parameters for the 1° pattern
    
    sprintf(mess, "status: %d \r\n", status);
    UART_PutString(mess);
    
    
    isr_BUTTON_StartEx(Custom_BUTTON_ISR); //Start the ISR of the button
    
    isr_PWM_StartEx(Custom_PWM_ISR);       //Start the ISR of the PWN
    
    
    for(;;)
    {
        
        
    }
}

/* [] END OF FILE */

