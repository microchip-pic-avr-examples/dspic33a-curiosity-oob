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
#include "led0.h"

void LED0_Initialize(void)
{
    TRISCbits.TRISC3 = 0;
}

void LED0_On(void)
{
    LATCbits.LATC3 = 1;
}

void LED0_Off(void)
{
    LATCbits.LATC3 = 0;
}

void LED0_Toggle(void)
{
    LATCbits.LATC3 ^= 1;
}

void LED0_Set(bool on)
{
    LATCbits.LATC3 = on;
}

struct LED_SIMPLE led0 = 
{
    &LED0_Initialize,
    &LED0_On,
    &LED0_Off,
    &LED0_Toggle,
    &LED0_Set
};