/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

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
    while(AD1CONbits.ADRDY == 0)
    {
    }
}

uint16_t POT_Read(void)
{
    // Trigger channel #1 in software and wait for the result.
    AD1SWTRGbits.CH1TRG = 1;
    // Wait for a conversion ready flag.
    while(AD1STATbits.CH1RDY == 0)
    {
    }
    
    // Read result. It will clear the conversion ready flag.
    return AD1DATA1;
}

struct POT pot = 
{
    &POT_Initialize,
    &POT_Read
};

