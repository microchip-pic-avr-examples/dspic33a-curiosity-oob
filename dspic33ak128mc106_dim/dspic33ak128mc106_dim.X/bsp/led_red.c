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
#include "led_red.h"

void LED_RED_Initialize(void)
{
    TRISCbits.TRISC2 = 0;
    
    /* PWM control register configuration */
    PCLKCONbits.MCLKSEL = 0b1;
    
    PG4CON = 0;
    PG4CONbits.CLKSEL = 1;
    PG4CONbits.MODSEL = 0b000;      /* Independent edge triggered mode */
       
    PG4IOCON = 0;
    PG4IOCONbits.PMOD = 0b10;       /* Independent mode */
    PG4IOCONbits.PENH = 1;          /* High output enabled */ 
    
    /* PWM uses PG4DC, PG4PER, PG4PHASE registers */
    /* PWM Generator does not broadcast UPDATE status bit state or EOC signal */
    /* Update the data registers at start of next PWM cycle (SOC) */
    /* PWM Generator operates in Single Trigger mode */
    /* Start of cycle (SOC) = local EOC */
    /* Write to DATA REGISTERS */
    PG4PER = 0x10000; /* PWM frequency */
    PG4DC = 0x8000;   /* 50% duty */

    PG4CONbits.ON = 0;
}

void LED_RED_On(void)
{
    PG4CONbits.ON = 1;
}

void LED_RED_Off(void)
{
    PG4CONbits.ON = 0;
}

void LED_RED_Toggle(void)
{
    PG4CONbits.ON ^= 1;
}

void LED_RED_Set(bool on)
{
    PG4CONbits.ON = on;
}

void LED_RED_SetIntensity(uint16_t request)
{  
    while(PG4STATbits.UPDATE == 1)
    {
    }
    
    PG4DC = request;
    
    PG4STATbits.UPDREQ = 1;
} 

struct LED_DIMMABLE ledRed = 
{
    &LED_RED_Initialize,
    &LED_RED_On,
    &LED_RED_Off,
    &LED_RED_Toggle,
    &LED_RED_Set,
    &LED_RED_SetIntensity
};