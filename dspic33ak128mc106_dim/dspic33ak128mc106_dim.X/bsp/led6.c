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
#include "led6.h"

void LED6_Initialize(void)
{
    TRISCbits.TRISC9 = 0;
}

void LED6_On(void)
{
    LATCbits.LATC9 = 1;
}

void LED6_Off(void)
{
    LATCbits.LATC9 = 0;
}

void LED6_Toggle(void)
{
    LATCbits.LATC9 ^= 1;
}

void LED6_Set(bool on)
{
    LATCbits.LATC9 = on;
}

struct LED_SIMPLE led6 = 
{
    &LED6_Initialize,
    &LED6_On,
    &LED6_Off,
    &LED6_Toggle,
    &LED6_Set
};