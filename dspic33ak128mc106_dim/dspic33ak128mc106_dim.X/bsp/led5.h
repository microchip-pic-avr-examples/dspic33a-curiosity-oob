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

#ifndef LED_5_H
#define LED_5_H

#include "led_simple.h"
#include <stdbool.h>

void LED5_Initialize(void);
void LED5_On(void);
void LED5_Off(void);
void LED5_Toggle(void);
void LED5_Set(bool on);

extern struct LED_SIMPLE led5;

#endif