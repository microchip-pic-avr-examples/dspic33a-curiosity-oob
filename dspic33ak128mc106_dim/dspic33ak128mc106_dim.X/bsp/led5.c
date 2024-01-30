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
#include "led5.h"

void LED5_Initialize(void)
{
    TRISCbits.TRISC8 = 0;
}

void LED5_On(void)
{
    LATCbits.LATC8 = 1;
}

void LED5_Off(void)
{
    LATCbits.LATC8 = 0;
}

void LED5_Toggle(void)
{
    LATCbits.LATC8 ^= 1;
}

void LED5_Set(bool on)
{
    LATCbits.LATC8 = on;
}

struct LED_SIMPLE led5 = 
{
    &LED5_Initialize,
    &LED5_On,
    &LED5_Off,
    &LED5_Toggle,
    &LED5_Set
};