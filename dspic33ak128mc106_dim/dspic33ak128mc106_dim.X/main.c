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
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/adc/adc1.h"
#include "bsp/led_red.h"
#include "bsp/led_blue.h"
#include "bsp/led_green.h"
#include "bsp/led_color.h"
#include "bsp/led_rgb.h"
#include "mcc_generated_files/uart/uart1.h"
#include "bsp/task.h"
#include <stdio.h>

static bool potentiometerPrintRequired = false;
static uint16_t potentiometerReading = 200;

static void setRGBIntensity(uint16_t potentiometerReading)
{
    ledRed.setIntensity(potentiometerReading);
    ledGreen.setIntensity(potentiometerReading);
    ledBlue.setIntensity(potentiometerReading); 
}

static void clearTerminalScreen(void)
{
    printf("\033[2J"); 
}

static void moveCursor(int row)
{
    printf("\033[%d;0f", row);
}

static void hideCursor()
{
    printf("\033[?25l");
}

static void printMenu(void)
{
    clearTerminalScreen();
    hideCursor();
    moveCursor(1);
    printf("------------------------------------ \r\n");
    printf("dsPIC33AK128MC106 Out of Box Demo\r\n");
    printf("------------------------------------ \r\n");   
    printf("Hold Switch S1 - LED7 turns on \r\n");
    printf("Hold Switch S2 - LED6 turns on \r\n");
    printf("Hold Switch S3 - LED5 turns on \r\n");
    printf("Press 'r', 'g', 'b' will toggle red, green, and blue states of the RGB LED "
            "respectively \r\n");
    printf("Turning the potentiometer will adjust the intensity of the RGB LED \r\n");

}

static void printPotentiometer(void)
{
    potentiometerPrintRequired = true;
}
 
static void checkUartApp(void)
{
    if(UART1_IsRxReady())
    {
        uint8_t dataRx = UART1_Read();
        if(dataRx)
        {
            switch(dataRx)
            {
                case 'r': 
                case 'R': 
                    ledRed.toggle();
                    break;
                case 'g': 
                case 'G': 
                    ledGreen.toggle();
                    break;   
                case 'b': 
                case 'B': 
                    ledBlue.toggle();
                    break;
                default: 
                    break;
            }
        }   

        while(!UART1_IsTxReady()) 
        {     
        }

        UART1_Write(dataRx);       
    }
}
 
static void checkButtonS1(void)
{
    if(IO_RB5_GetValue() == 0) 
    {
        IO_RC10_SetHigh();
    } 
    else 
    {
        IO_RC10_SetLow();
    }
}
 
static void checkButtonS2(void)
{
    if(IO_RB4_GetValue() == 0) 
    {
        IO_RC9_SetHigh();
    } 
    else 
    {
        IO_RC9_SetLow();
    }    
}
 
static void checkButtonS3(void)
{
    if(IO_RA6_GetValue() == 0) 
    {
        IO_RC8_SetHigh();
    } 
    else 
    {
        IO_RC8_SetLow();
    } 
}

int main(void)
{       
    SYSTEM_Initialize();
    TASK_Initialize();
    ledRGB.on();
    printMenu();
    TASK_Request(printPotentiometer, 200);

    while (1) 
    {
        ADC1.SoftwareTriggerEnable();
        potentiometerReading = ADC1.ConversionResultGet(ADC1_Channel0);
        setRGBIntensity(potentiometerReading);
        if(potentiometerPrintRequired)
        {
            potentiometerPrintRequired = false;
            moveCursor(10);
            printf("Potentiometer: 0x%04X\r\n", potentiometerReading);
        }
        
        checkUartApp();
        checkButtonS1();
        checkButtonS2();
        checkButtonS3();
    }
}
