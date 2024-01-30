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

#ifndef LED_GREEN_H
#define LED_GREEN_H

#include "led_dimmable.h"
#include <stdbool.h>
#include <stdint.h>

void LED_GREEN_Initialize(void);
void LED_GREEN_On(void);
void LED_GREEN_Off(void);
void LED_GREEN_Toggle(void);
void LED_GREEN_Set(bool on);
void LED_GREEN_SetIntensity(uint16_t intensity);

extern struct LED_DIMMABLE ledGreen;

#endif