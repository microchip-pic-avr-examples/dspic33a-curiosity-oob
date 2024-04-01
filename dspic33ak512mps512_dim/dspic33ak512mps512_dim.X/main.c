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
#include "bsp/led_red.h"
#include "bsp/led_blue.h"
#include "bsp/led_green.h"
#include "bsp/led_color.h"
#include "bsp/led_rgb.h"
#include "bsp/s1.h"
#include "bsp/s2.h"
#include "bsp/s3.h"
#include "mcc_generated_files/uart/uart1.h"
#include "bsp/pot.h"
#include "bsp/task.h"
#include "mcc_generated_files/can/can1.h"
#include "mcc_generated_files/can/can_types.h"
#include <stdio.h>

#define CAN_TX_MESSAGE_ID 0xA2

static bool potentiometerPrintRequired = false;
static struct CAN_MSG_OBJ canRxMessage;
static uint8_t canRxData[8];
static struct CAN_MSG_OBJ canTxMessage;
static uint8_t canTxData[8];

static void initializeAllLEDs(void)
{
    ledRGB.initialize();
    led5.initialize();
    led6.initialize();
    led7.initialize();
}

static void initializeAllButtons(void)
{
    s1.initialize();
    s2.initialize();
    s3.initialize();
}

static void initializeCanMessage(void)
{
    canRxMessage.data = canRxData;
    canTxMessage.msgId = CAN_TX_MESSAGE_ID;
    canTxMessage.data = canTxData;
    canTxMessage.field.idType = CAN_FRAME_STD;
    canTxMessage.field.frameType = CAN_FRAME_DATA;
    canTxMessage.field.dlc = DLC_8;
    canTxMessage.field.formatType = CAN_FD_FORMAT;
    canTxMessage.field.brs = CAN_BRS_MODE;
}

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
    printf("dsPIC33AK512MPS512 Out of Box Demo\r\n");
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

static void checkCANApp(void)
{    
    uint8_t index = 0;
    
    if(CAN1_ReceivedMessageCountGet() > 0)
    {
        CAN1_ReceiveMessageGet(CAN1_FIFO_1, &canRxMessage);
        while(index < 8)
        {
            switch(canRxMessage.data[index])
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
            index++;
        }
    }
}

static void checkButtonS1(void)
{
    if(s1.isPressed()) 
    {
        led7.on();
    } 
    else 
    {
        led7.off();
    }
}
 
static void checkButtonS2(void)
{
    if(s2.isPressed()) 
    {
       led6.on();
    } 
    else 
    {
       led6.off();
    }    
}
 
static void checkButtonS3(void)
{
    if(s3.isPressed()) 
    {
        led5.on();
    } 
    else {
        led5.off();
    } 
}

int main(void)
{    
    SYSTEM_Initialize();
    initializeCanMessage();
    initializeAllLEDs();
    initializeAllButtons();
    TASK_Initialize();
    pot.initialize();
    ledRGB.on();
    printMenu();
    TASK_Request(printPotentiometer, 200);
    TASK_Request(CAN1_Tasks, 200);
    
    while (1) 
    {
        uint16_t potentiometerReading = pot.read();
        setRGBIntensity(potentiometerReading);
        if(potentiometerPrintRequired)
        {
            potentiometerPrintRequired = false;
            moveCursor(10);
            printf("Potentiometer: 0x%04X\r\n", pot.read());
            canTxMessage.data[0] = potentiometerReading >> 8;
            canTxMessage.data[1] = potentiometerReading;
            CAN1_Transmit(CAN1_TXQ, &canTxMessage);
        }
        checkUartApp();
        checkCANApp();
        checkButtonS1();
        checkButtonS2();
        checkButtonS3();
    }
}