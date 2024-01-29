/*******************************************************************************
Copyright 2024 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <xc.h>
#include "led_dimmable.h"

void LED_BLUE_Initialize()
{
    TRISDbits.TRISD2 = 0;
    
    /* PWM control register configuration */
    PCLKCONbits.MCLKSEL = 0b1;
    
    PG1CON = 0;
    PG1CONbits.CLKSEL = 1;
    PG1CONbits.MODSEL = 0b000;      /* Independent edge triggered mode */
       
    PG1IOCON = 0;
    PG1IOCONbits.PMOD = 0b10;       /* Independent mode */
    PG1IOCONbits.PENH = 1;          /* High output enabled */ 
    
    /* PWM uses PG1DC, PG1PER, PG1PHASE registers */
    /* PWM Generator does not broadcast UPDATE status bit state or EOC signal */
    /* Update the data registers at start of next PWM cycle (SOC) */
    /* PWM Generator operates in Single Trigger mode */
    /* Start of cycle (SOC) = local EOC */
    /* Write to DATA REGISTERS */
    PG1PER = 0x10000; /* PWM frequency */
    PG1DC = 0x8000;   /* 50% duty */

    PG1CONbits.ON = 0;
}

void LED_BLUE_On()
{
    PG1CONbits.ON = 1;
}

void LED_BLUE_Off()
{
    PG1CONbits.ON = 0;
}

void LED_BLUE_Toggle()
{
    PG1CONbits.ON ^= 1;
}

void LED_BLUE_Set(bool on)
{
    PG1CONbits.ON = on;
}

void LED_BLUE_SetIntensity(uint16_t request)
{  
    while(PG1STATbits.UPDATE == 1)
    {
    }
    
    PG1DC = request;
    
    PG1STATbits.UPDREQ = 1;
} 

struct LED_DIMMABLE ledBlue = 
{
    &LED_BLUE_Initialize,
    &LED_BLUE_On,
    &LED_BLUE_Off,
    &LED_BLUE_Toggle,
    &LED_BLUE_Set,
    &LED_BLUE_SetIntensity
};