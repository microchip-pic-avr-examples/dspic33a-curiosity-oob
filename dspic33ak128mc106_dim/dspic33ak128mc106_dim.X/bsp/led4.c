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
#include "led4.h"

void LED4_Initialize(void)
{
    TRISCbits.TRISC7 = 0;
}

void LED4_On(void)
{
    LATCbits.LATC7 = 1;
}

void LED4_Off(void)
{
    LATCbits.LATC7 = 0;
}

void LED4_Toggle(void)
{
    LATCbits.LATC7 ^= 1;
}

void LED4_Set(bool on)
{
    LATCbits.LATC7 = on;
}

struct LED_SIMPLE led4 = 
{
    &LED4_Initialize,
    &LED4_On,
    &LED4_Off,
    &LED4_Toggle,
    &LED4_Set
};