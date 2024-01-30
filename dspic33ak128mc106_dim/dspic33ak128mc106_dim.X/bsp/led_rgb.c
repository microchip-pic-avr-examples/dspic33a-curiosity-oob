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
#include "led_color.h"

#include "led_rgb.h"
#include "led_red.h"
#include "led_green.h"
#include "led_blue.h"

void LED_RGB_Initialize(void)
{
    ledRed.initialize();
    ledGreen.initialize();
    ledBlue.initialize();
}

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

void LED_RGB_Set(bool on)
{
    ledRed.set(on);
    ledGreen.set(on);
    ledBlue.set(on);
}

void LED_RGB_SetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    ledRed.setIntensity(red << 8);
    ledGreen.setIntensity(green << 8);
    ledBlue.setIntensity(blue << 8);
}

struct LED_COLOR ledRGB = 
{
    &LED_RGB_Initialize,
    &LED_RGB_On,
    &LED_RGB_Off,
    &LED_RGB_Toggle,
    &LED_RGB_Set,
    &LED_RGB_SetColor
};