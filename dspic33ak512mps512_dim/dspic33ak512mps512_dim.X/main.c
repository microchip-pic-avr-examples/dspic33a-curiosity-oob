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

#include "mcc_generated_files/system/system.h"
#include "bsp/led0.h"
#include "bsp/led1.h"
#include "bsp/led2.h"
#include "bsp/led3.h"
#include "bsp/led4.h"
#include "bsp/led5.h"
#include "bsp/led6.h"
#include "bsp/led7.h"
#include "bsp/s1.h"
#include "bsp/s2.h"
#include "bsp/s3.h"
#include "bsp/led_blue.h"
#include "bsp/led_green.h"
#include "bsp/led_red.h"
#include "bsp/pot.h"
#include <stdio.h>

int main(void)
{       
    SYSTEM_Initialize();
    
    led0.initialize();
    led1.initialize();
    led2.initialize();
    led3.initialize();
    led4.initialize();
    led5.initialize();
    led6.initialize();
    led7.initialize();
    s1.initialize();
    s2.initialize();
    s3.initialize();
    
    ledBlue.initialize();
    ledGreen.initialize();
    ledRed.initialize();
    
    pot.initialize();
    
    //ledBlue.on();
    //ledGreen.on();
    ledRed.on();
    
    while(1)
    {  
        ledRed.setIntensity(pot.read());
    }    
}