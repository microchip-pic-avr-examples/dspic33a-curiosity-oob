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

#include <xc.h>
#include "led_color.h"

#include "led_rgb.h"
#include "led_red.h"
#include "led_green.h"
#include "led_blue.h"

void LED_RGB_On(void)
{
    ledRed.on();
    ledGreen.on();
    ledBlue.on();
}

void LED_RGB_Off(void)
{
    ledRed.off();
    ledGreen.off();
    ledBlue.off();
}

void LED_RGB_Toggle(void)
{
    ledRed.toggle();
    ledGreen.toggle();
    ledBlue.toggle();
}

void LED_RGB_SetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    ledRed.setIntensity((uint16_t)red << 8u);
    ledGreen.setIntensity((uint16_t)green << 8u);
    ledBlue.setIntensity((uint16_t)blue << 8u);
}

const struct LED_COLOR ledRGB = 
{
    &LED_RGB_On,
    &LED_RGB_Off,
    &LED_RGB_Toggle,
    &LED_RGB_SetColor
};