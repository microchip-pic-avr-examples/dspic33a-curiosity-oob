/**
 * UART_NULL Generated Driver Source File
 * 
 * @file      uart1.c
 *            
 * @ingroup   uartdriver
 *            
 * @brief     This is the generated driver source file for the UART_NULL driver.
 *
 * @skipline @version   PLIB Version 1.0.0
 *            
 * @skipline  Device : dsPIC33AK512MPS512
*/

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

// Section: Included Files
#include <stdint.h>
#include <stddef.h>
#include <xc.h>
#include <stddef.h>
#include "../mcc_generated_files/uart/uart_interface.h"
#include "uart_null.h"


// Section: Driver Interface

const struct UART_INTERFACE UART_NULL_Drv = {
    .Initialize = &UART_NULL_Initialize,
    .Deinitialize = &UART_NULL_Deinitialize,
    .Read = &UART_NULL_Read,
    .Write = &UART_NULL_Write,
    .IsRxReady = &UART_NULL_IsRxReady,
    .IsTxReady = &UART_NULL_IsTxReady,
    .IsTxDone = &UART_NULL_IsTxDone,
    .TransmitEnable = &UART_NULL_TransmitEnable,
    .TransmitDisable = &UART_NULL_TransmitDisable,
    .TransmitInterruptEnable = NULL,
    .TransmitInterruptDisable = NULL,
    .AutoBaudSet = &UART_NULL_AutoBaudSet,
    .AutoBaudQuery = &UART_NULL_AutoBaudQuery,
    .AutoBaudEventEnableGet = &UART_NULL_AutoBaudEventEnableGet,
    .BRGCountSet = &UART_NULL_BRGCountSet,
    .BRGCountGet = &UART_NULL_BRGCountGet,
    .BaudRateSet = &UART_NULL_BaudRateSet,
    .BaudRateGet = &UART_NULL_BaudRateGet,
    .ErrorGet = &UART_NULL_ErrorGet,
    .RxCompleteCallbackRegister = NULL,
    .TxCompleteCallbackRegister = NULL,
    .TxCollisionCallbackRegister = NULL,
    .FramingErrorCallbackRegister = NULL,
    .OverrunErrorCallbackRegister = NULL,
    .ParityErrorCallbackRegister = NULL,
};

// Section: UART_NULL APIs

void UART_NULL_Initialize(void)
{
}

void UART_NULL_Deinitialize(void)
{
}

uint8_t UART_NULL_Read(void)
{
    return 0x00;
}

void UART_NULL_Write(uint8_t txData)
{
}

bool UART_NULL_IsRxReady(void)
{
    return false;
}

bool UART_NULL_IsTxReady(void)
{
    return true;
}

bool UART_NULL_IsTxDone(void)
{
    return true;
}

void UART_NULL_TransmitEnable(void)
{
}

void UART_NULL_TransmitDisable(void)
{
}

void UART_NULL_AutoBaudSet(bool enable)
{
}

bool UART_NULL_AutoBaudQuery(void)
{
    return false;
}

bool UART_NULL_AutoBaudEventEnableGet(void)
{ 
    return false;
}

size_t UART_NULL_ErrorGet(void)
{
    return 0;
}

void UART_NULL_BRGCountSet(uint32_t brgValue)
{
}

uint32_t UART_NULL_BRGCountGet(void)
{
    return 0;
}

void UART_NULL_BaudRateSet(uint32_t baudRate)
{
}

uint32_t UART_NULL_BaudRateGet(void)
{
    return 0;
}
