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

#ifndef BUTTON_T3_H
#define BUTTON_T3_H

#include <stdbool.h>
#include "button_simple.h"

/**
 * @ingroup  s1
 * @brief    Initializes the T3 button.  Must be called before other functions can be used.
 * @param    none
 * @return   none
 */
void BUTTON_T3_Initialize(void);

/**
 * @ingroup  s1
 * @brief    Detects if the T3 button is pressed
 * @param    none
 * @return   bool - true = pressed, false = not pressed
 */
bool BUTTON_T3_IsPressed(void);

/**
 @ingroup  s1
 @brief    Declaration of BUTTON_SIMPLE structure for T3 button.
*/
extern const struct BUTTON_SIMPLE t3;

#endif