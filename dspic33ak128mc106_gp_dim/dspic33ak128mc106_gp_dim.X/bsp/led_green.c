/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <xc.h>
#include "led_green.h"
#include "../mcc_generated_files/pwm/sccp2.h"

static bool issccp2Enabled = false;

void LED_GREEN_Initialize(void)
{
    
}

void LED_GREEN_On(void)
{
    SCCP2_PWM_Enable();
    issccp2Enabled = true;
}

void LED_GREEN_Off(void)
{
    SCCP2_PWM_Disable();
    issccp2Enabled = false;
}

void LED_GREEN_Toggle(void)
{
    if (issccp2Enabled == true) 
    {
        LED_GREEN_Off();
    } 
    else 
    {
        LED_GREEN_On();
    }
}

void LED_GREEN_Set(bool on)
{
    
}

void LED_GREEN_SetIntensity(uint16_t request)
{  
    SCCP2_PWM_DutyCycleSet(request);
} 

const struct LED_DIMMABLE ledGreen = 
{
    &LED_GREEN_Initialize,
    &LED_GREEN_On,
    &LED_GREEN_Off,
    &LED_GREEN_Toggle,
    &LED_GREEN_Set,
    &LED_GREEN_SetIntensity
};