/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "mcc_generated_files/touch/include/qtm_common_components_api.h"
#include "mcc_generated_files/touch/include/touch_api.h"

#include "bsp/led0.h"
#include "bsp/led1.h"
#include "bsp/led2.h"
#include "bsp/led3.h"
#include "bsp/led4.h"
#include "bsp/led5.h"
#include "bsp/led6.h"
#include "bsp/led7.h"

#include "bsp/led_rgb.h"
#include "bsp/led_red.h"
#include "bsp/led_blue.h"
#include "bsp/led_green.h"

#include "bsp/t1.h"
#include "bsp/t2.h"
#include "bsp/t3.h"

#include "bsp/s1.h"
#include "bsp/s2.h"
#include "bsp/s3.h"

#include "bsp/task.h"
#include "mcc_generated_files/timer/tmr1.h"
#include "bsp/led_color.h"

#include "bsp/pot.h"

#include "mcc_generated_files/uart/uart1.h"
#include "bsp/uart_null.h"

#include "mcc_generated_files/touch/datastreamer/datastreamer.h"
#include "console.h"

#include <stdbool.h>
#include <stdio.h>

#include "mcc_generated_files/can/can1.h"

static volatile bool potentiometerPrintRequired = false;
static char printBuffer[100];

#define CAN_TX_MESSAGE_ID 0xA2

static struct CAN_MSG_OBJ canRxMessage;
static uint8_t canRxData[8];
static struct CAN_MSG_OBJ canTxMessage;
static uint8_t canTxData[8];

static void UpdateLEDOnButtonPress(const struct BUTTON_SIMPLE *button, const struct LED_SIMPLE *led)
{
    if(button->isPressed())
    {
        led->on();
    }
    else
    {
        led->off();
    }
}

static void AliveToggle(void)
{
    led3.toggle();
}

static void printMenu(void)
{
    console.clear();
    console.cursorHide();
    console.cursorRowSet(1);
    console.print("------------------------------------ \r\n");
    console.print("dsPIC33AK512MPS512 Out of Box Demo\r\n");
    console.print("------------------------------------ \r\n");   
    console.print("Hold Switch S1 - LED7 turns on \r\n");
    console.print("Hold Switch S2 - LED6 turns on \r\n");
    console.print("Hold Switch S3 - LED5 turns on \r\n");
    console.print("Hold Switch T1 - LED2 turns on \r\n");
    console.print("Hold Switch T2 - LED1 turns on \r\n");
    console.print("Hold Switch T3 - LED0 turns on \r\n");
    console.print("LED3 blinks every second\r\n");
    console.print("Press 'r', 'g', 'b' will toggle states of the RGB LED\r\n");
    console.print("Turning the potentiometer will adjust the intensity of the RGB LED \r\n");

}

static void UpdateRGB(char command)
{
    switch(command)
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

static void UpdateRGBIntensity(uint16_t intensity)
{
    ledRed.setIntensity(intensity);
    ledGreen.setIntensity(intensity);
    ledBlue.setIntensity(intensity); 
}

static void printPotentiometer(void)
{
    potentiometerPrintRequired = true;
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

/*
    Main application
*/

static void ScanCAN(void)
{    
    uint8_t index = 0;
    
    if(CAN1_ReceivedMessageCountGet() > 0)
    {
        CAN1_ReceiveMessageGet(CAN1_FIFO_1, &canRxMessage);
        while(index < 8)
        {
            UpdateRGB(canRxMessage.data[index]);
            index++;
        }
    }
}

static void BoardInitialize(void)
{
    /* 
     * The pin connected to the shield provided for the capacitive buttons is not one of the ITC pins
     * and cannot be used. The pin cannot be floating and should be grounded
     */
    _TRISE4 = 0u;
    _LATE4 = 0u;

    /* LEDs */
    led0.initialize();
    led1.initialize();
    led2.initialize();
    led3.initialize();
    led4.initialize();
    led5.initialize();
    led6.initialize();
    led7.initialize();
    
    ledRGB.initialize();
    
    ledRed.setIntensity(0);
    ledRed.on();
    
    ledGreen.setIntensity(0);
    ledGreen.on();
    
    ledBlue.setIntensity(0);
    ledBlue.on();
    
    /* Touch buttons */
    t1.initialize();
    t2.initialize();
    t3.initialize();
    
    /* Switches */
    s1.initialize();
    s2.initialize();
    s3.initialize();

    pot.initialize();
}

int main(void)
{
    char input;

    TASK_Initialize();

    SYSTEM_Initialize();          

    TMR1_TimeoutCallbackRegister(&TASK_InterruptHandler);
    
    BoardInitialize();
    
    /* If all three buttons are pressed on reset, then switch to data visualizer
     * mode instead of console mode. */
    if(s1.isPressed() && s2.isPressed() && s3.isPressed())
    {
        datastreamer_init(&UART1_Drv);
        console.initialize(&UART_NULL_Drv);
    }
    else
    {
        datastreamer_init(&UART_NULL_Drv);
        console.initialize(&UART1_Drv);
    }
        
    initializeCanMessage();
        
    /* Scan touch every millisecond */
    TASK_Request(&touch_timer_handler, 1);
    
    /* Blink alive once a second */
    TASK_Request(&AliveToggle, 1000);
    
    /* Print the potentiometer value every 200ms */
    TASK_Request(&printPotentiometer, 200);
    
    TMR1_Start();
    
    touch_init();
        
    printMenu();

    while(1)
    {
        CAN1_Tasks();
        
        touch_process();

        uint16_t potentiometerReading = pot.read();
        
        UpdateRGBIntensity(potentiometerReading);
        
        UpdateLEDOnButtonPress(&t1, &led2);
        UpdateLEDOnButtonPress(&t2, &led1);
        UpdateLEDOnButtonPress(&t3, &led0);
        
        UpdateLEDOnButtonPress(&s1, &led7);
        UpdateLEDOnButtonPress(&s2, &led6);
        UpdateLEDOnButtonPress(&s3, &led5);
            
        if(potentiometerPrintRequired)
        {
            potentiometerPrintRequired = false;
            
            sprintf(printBuffer, "Potentiometer: 0x%04X\r\n", pot.read());
            
            console.cursorRowSet(14);
            console.print(printBuffer);
            
            canTxMessage.data[0] = potentiometerReading >> 8;
            canTxMessage.data[1] = potentiometerReading;
            CAN1_Transmit(CAN1_TXQ, &canTxMessage);
        }
        
        if(console.scan(&input))
        {
            console.cursorRowSet(15);
            UpdateRGB(input);
        }
        
        ScanCAN();
    }    
}