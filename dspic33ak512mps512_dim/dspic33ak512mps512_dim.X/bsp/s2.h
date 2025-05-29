/*
� [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef BUTTON_S2_H
#define BUTTON_S2_H

#include <stdbool.h>
#include "button_simple.h"

/**
 * @ingroup  s2
 * @brief    Initializes the S2 button.  Must be called before other functions can be used.
 * @param    none
 * @return   none
 */
void BUTTON_S2_Initialize(void);

/**
 * @ingroup  s2
 * @brief    Detects if the S2 button is pressed (not debounced)
 * @param    none
 * @return   bool - true = pressed, false = not pressed
 */
bool BUTTON_S2_IsPressed(void);

/**
 @ingroup  s2
 @brief    Declaration of BUTTON_SIMPLE structure for S2 button.
*/
extern const struct BUTTON_SIMPLE s2;

#endif