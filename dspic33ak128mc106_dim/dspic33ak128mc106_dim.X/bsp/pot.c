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

#include "pot.h"
#include <xc.h>

void POT_Initialize(void)
{
    // In this example channel 4 will be used.
    // Oversampling conversion mode.
    AD1CHCON1bits.MODE = 3;
    // Set number of conversions accumulated to 256.
    AD1CHCON1bits.ACCNUM = 2;
    // The oversampling if started cannot be interrupted
    // by a high priority channels conversion requests.
    AD1CHCON1bits.ACCBRST = 1;

    // Software trigger will start a conversion.
    AD1CHCON1bits.TRG1SRC = 1; 
    
     // Re-trigger back to back.
    AD1CHCON1bits.TRG2SRC = 2;
    
    // Use a single ended input.
    AD1CHCON1bits.DIFF = 0;
    // Select the AN6 analog positive input/pin for the signal.
    AD1CHCON1bits.PINSEL = 6;
    // Select the GND as negative input/pin for the signal.
    AD1CHCON1bits.NINSEL = 0;
    // Select signal sampling time (6.5 TADs = 81 nS).
    AD1CHCON1bits.SAMC = 3;
    // Set ADC to RUN mode.
    AD1CONbits.MODE = 2;
    // Enable ADC.
    AD1CONbits.ON = 1;
    
    // Wait when ADC will be ready/calibrated.
    while(AD1CONbits.ADRDY == 0);
}

uint16_t POT_Read(void)
{
    // Trigger channel #1 in software and wait for the result.
    AD1SWTRGbits.CH1TRG = 1;
    // Wait for a conversion ready flag.
    while(AD1STATbits.CH1RDY == 0);
    // Read result. It will clear the conversion ready flag.
    return AD1DATA1;
}

struct POT pot = 
{
    &POT_Initialize,
    &POT_Read
};

