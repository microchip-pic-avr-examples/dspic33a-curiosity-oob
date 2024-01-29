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

#include "button_simple.h"
#include <stdbool.h>
#include <xc.h>

void BUTTON_S3_Initialize(void)
{
    ANSELAbits.ANSELA6 = 0;
    TRISAbits.TRISA6 = 1;
}

bool BUTTON_S3_IsPressed(void)
{
    return PORTAbits.RA6 == 0;      //Active low
}

struct BUTTON_SIMPLE s3 = 
{
    &BUTTON_S3_Initialize,
    &BUTTON_S3_IsPressed
};