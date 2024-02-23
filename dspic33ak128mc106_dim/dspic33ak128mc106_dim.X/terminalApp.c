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
#include "application.h"
#include "bsp/led7.h"
#include "mcc_generated_files/uart/uart1.h"
#include "bsp/led_rgb.h"
#include "bsp/led_color.h"

void terminalAppStart(void){
    uint8_t dataRx;
    if(UART1_IsRxReady()){
        dataRx = UART1_Read();
        if(dataRx){
            ledRGB.on();
            switch(dataRx){
                case 'r': 
                    ledRGB.setColor(255,0,0); 
                    break;
                case 'g': 
                    ledRGB.setColor(0,255,0); 
                    break;   
                case 'b': 
                    ledRGB.setColor(0,0,255); 
                    break;
                default: break;
            }
        }
    }
    
    while(!UART1_IsTxReady()) {
        
    }
    UART1_Write(dataRx);
}

void terminalAppRun(void){
    terminalAppStart();
}

void terminalAppStop(void){
    ledRGB.off();
}

struct APPLICATION terminalApp = {
    &terminalAppStart,
    &terminalAppRun,
    &terminalAppStop
};
