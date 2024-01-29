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

void LED_GREEN_Initialize()
{
    TRISDbits.TRISD0 = 0;
    
    /* PWM control register configuration */
    PCLKCONbits.MCLKSEL = 0b1;
    
    PG2CON = 0;
    PG2CONbits.CLKSEL = 1;
    PG2CONbits.MODSEL = 0b000;      /* Independent edge triggered mode */
       
    PG2IOCON = 0;
    PG2IOCONbits.PMOD = 0b10;       /* Independent mode */
    PG2IOCONbits.PENH = 1;          /* High output enabled */ 
    
    /* PWM uses PG2DC, PG2PER, PG2PHASE registers */
    /* PWM Generator does not broadcast UPDATE status bit state or EOC signal */
    /* Update the data registers at start of next PWM cycle (SOC) */
    /* PWM Generator operates in Single Trigger mode */
    /* Start of cycle (SOC) = local EOC */
    /* Write to DATA REGISTERS */
    PG2PER = 0x10000; /* PWM frequency */
    PG2DC = 0x8000;   /* 50% duty */

    PG2CONbits.ON = 0;
}

void LED_GREEN_On()
{
    PG2CONbits.ON = 1;
}

void LED_GREEN_Off()
{
    PG2CONbits.ON = 0;
}

void LED_GREEN_Toggle()
{
    PG2CONbits.ON ^= 1;
}

void LED_GREEN_Set(bool on)
{
    PG2CONbits.ON = on;
}

void LED_GREEN_SetIntensity(uint16_t request)
{  
    while(PG2STATbits.UPDATE == 1)
    {
    }
    
    PG2DC = request;
    
    PG2STATbits.UPDREQ = 1;
} 

struct LED_DIMMABLE ledGreen = 
{
    &LED_GREEN_Initialize,
    &LED_GREEN_On,
    &LED_GREEN_Off,
    &LED_GREEN_Toggle,
    &LED_GREEN_Set,
    &LED_GREEN_SetIntensity
};