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
#include "led2.h"

void LED2_Initialize(void)
{
    TRISCbits.TRISC5 = 0;
}

void LED2_On(void)
{
    LATCbits.LATC5 = 1;
}

void LED2_Off(void)
{
    LATCbits.LATC5 = 0;
}

void LED2_Toggle(void)
{
    LATCbits.LATC5 ^= 1;
}

void LED2_Set(bool on)
{
    LATCbits.LATC5 = on;
}

struct LED_SIMPLE led2 = 
{
    &LED2_Initialize,
    &LED2_On,
    &LED2_Off,
    &LED2_Toggle,
    &LED2_Set
};