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
#include "bsp/led7.h"
#include "bsp/led6.h"
#include "bsp/led5.h"
#include "bsp/led4.h"
#include "bsp/led3.h"
#include "bsp/led2.h"
#include "bsp/led1.h"
#include "bsp/led0.h"
#include "bsp/led_color.h"
#include "bsp/led_rgb.h"
#include "bsp/s1.h"
#include "bsp/s2.h"
#include "bsp/s3.h"
#include "application.h"
#include "s1App.h"
#include "s2App.h"
#include "s3App.h"
#include "terminalApp.h"
#include "mcc_generated_files/uart/uart1.h"
#include <stdio.h>

void initializeAllLEDs(void){
    ledRGB.initialize();
    led0.initialize();
    led1.initialize();
    led2.initialize();
    led3.initialize();
    led4.initialize();
    led5.initialize();
    led6.initialize();
    led7.initialize();
}

void initializeAllButtons(void){
    s1.initialize();
    s2.initialize();
    s3.initialize();
}

void turnOffAllLEDs(void){
    led0.off();
    led1.off();
    led2.off();
    led3.off();
    led4.off();
    led5.off();
    led6.off();
    led7.off();
}

int main(void)
{       
    SYSTEM_Initialize();
    initializeAllLEDs();
    initializeAllButtons();
    
    struct APPLICATION *currentApp = NULL;
    bool isUARTRunning = false;
    while (1) {     
        if(UART1_IsRxReady()){
            if(currentApp != &terminalApp){
                if(currentApp != NULL){
                    currentApp ->stop();
                } 
                terminalApp.start();
                currentApp = &terminalApp;
                isUARTRunning = true;
            }
            if(currentApp == &terminalApp){
                terminalApp.run();
            }
        }
        if(s1.isPressed()){
            if(currentApp != &s1App){
                if(currentApp != NULL){
                    currentApp ->stop();
                } 
                s1App.start();
                currentApp = &s1App;
                isUARTRunning = false;
            }
        }
        else if(s2.isPressed()){
            if(currentApp != &s2App){
                if(currentApp != NULL){
                    currentApp->stop();
                }
                s2App.start();
                currentApp = &s2App;
                isUARTRunning = false;
            }
        }
        else if(s3.isPressed()){
            if(currentApp != &s3App){
                if(currentApp != NULL){
                    currentApp->stop();
                }
                s3App.start();
                currentApp = &s3App;
                isUARTRunning = false;
            }
        }
        else
        {
            if(currentApp != NULL && !isUARTRunning){
                currentApp->stop();
                turnOffAllLEDs();
                currentApp = NULL;
            }
        }
    }
}
