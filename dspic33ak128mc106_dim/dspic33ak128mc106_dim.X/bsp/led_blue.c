/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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
#include "led_blue.h"
#include "../mcc_generated_files/pwm/sccp3.h"

static bool issccp3Enabled = false;

void LED_BLUE_On(void)
{
    SCCP3_PWM_Enable();
    issccp3Enabled = true;
}

void LED_BLUE_Off(void)
{
    SCCP3_PWM_Disable();
    issccp3Enabled = false;
}

void LED_BLUE_Toggle(void)
{
    if (issccp3Enabled == true) 
    {
        LED_BLUE_Off();
    } 
    else 
    {
        LED_BLUE_On();
    }
}

void LED_BLUE_SetIntensity(uint16_t request)
{  
    SCCP3_PWM_DutyCycleSet(request);
} 

const struct LED_DIMMABLE ledBlue = 
{
    &LED_BLUE_On,
    &LED_BLUE_Off,
    &LED_BLUE_Toggle,
    &LED_BLUE_SetIntensity
};