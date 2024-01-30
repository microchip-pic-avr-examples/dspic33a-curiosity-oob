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
#include "led3.h"

void LED3_Initialize(void)
{
    TRISCbits.TRISC6 = 0;
}

void LED3_On(void)
{
    LATCbits.LATC6 = 1;
}

void LED3_Off(void)
{
    LATCbits.LATC6 = 0;
}

void LED3_Toggle(void)
{
    LATCbits.LATC6 ^= 1;
}

void LED3_Set(bool on)
{
    LATCbits.LATC6 = on;
}

struct LED_SIMPLE led3 = 
{
    &LED3_Initialize,
    &LED3_On,
    &LED3_Off,
    &LED3_Toggle,
    &LED3_Set
};