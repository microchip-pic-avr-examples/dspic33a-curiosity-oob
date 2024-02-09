/**
 * UART1 Generated Driver Source File
 * 
 * @file      uart1.c
 *            
 * @ingroup   uartdriver
 *            
 * @brief     This is the generated driver source file for the UART1 driver.
 *
 * @skipline @version   PLIB Version 1.0.0
 *            
 * @skipline  Device : dsPIC33AK512MPS512
*/

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

// Section: Included Files
#include <stdint.h>
#include <stddef.h>
#include <xc.h>
#include <stddef.h>
#include "../uart1.h"

// Section: Macro Definitions
#define UART1_CLOCK 8000000U
#define UART1_BAUD_TO_BRG_WITH_FRACTIONAL(x) (UART1_CLOCK/(x))
#define UART1_BAUD_TO_BRG_WITH_BRGH_1(x) (UART1_CLOCK/(4U*(x))-1U)
#define UART1_BAUD_TO_BRG_WITH_BRGH_0(x) (UART1_CLOCK/(16U*(x))-1U)
#define UART1_BRG_TO_BAUD_WITH_FRACTIONAL(x) (UART1_CLOCK/(x))
#define UART1_BRG_TO_BAUD_WITH_BRGH_1(x) (UART1_CLOCK/(4U*((x)+1U)))
#define UART1_BRG_TO_BAUD_WITH_BRGH_0(x) (UART1_CLOCK/(16U*((x)+1U)))

//#define BRGVAL ((UART1_CLOCK/153600)-1)

#define UART1_MIN_ACHIEVABLE_BAUD_WITH_FRACTIONAL 600U
#define UART1_MIN_ACHIEVABLE_BAUD_WITH_BRGH_1 300U

// Section: Driver Interface

const struct UART_INTERFACE UART1_Drv = {
    .Initialize = &UART1_Initialize,
    .Deinitialize = &UART1_Deinitialize,
    .Read = &UART1_Read,
    .Write = &UART1_Write,
    .IsRxReady = &UART1_IsRxReady,
    .IsTxReady = &UART1_IsTxReady,
    .IsTxDone = &UART1_IsTxDone,
    .TransmitEnable = &UART1_TransmitEnable,
    .TransmitDisable = &UART1_TransmitDisable,
    .AutoBaudSet = &UART1_AutoBaudSet,
    .AutoBaudQuery = &UART1_AutoBaudQuery,
    .AutoBaudEventEnableGet = &UART1_AutoBaudEventEnableGet,
    .BRGCountSet = &UART1_BRGCountSet,
    .BRGCountGet = &UART1_BRGCountGet,
    .BaudRateSet = &UART1_BaudRateSet,
    .BaudRateGet = &UART1_BaudRateGet,
    .ErrorGet = &UART1_ErrorGet,
    .TxCompleteCallbackRegister = NULL,
    .RxCompleteCallbackRegister = NULL,
    .TxCollisionCallbackRegister = NULL,
    .FramingErrorCallbackRegister = NULL,
    .OverrunErrorCallbackRegister = NULL,
    .ParityErrorCallbackRegister = NULL,
    .EventCallbackRegister = NULL,
};

// Section: Private Variable Definitions
static union
{
    struct
    {
        uint16_t frammingError :1;
        uint16_t parityError :1;
        uint16_t overrunError :1;
        uint16_t txCollisionError :1;
        uint16_t autoBaudOverflow :1;
        uint16_t reserved :11;
    };
    size_t status;
} uartError;

// Section: UART1 APIs

void UART1_Initialize(void)
{
/*    
     Set the UART1 module to the options selected in the user interface.
     Make sure to set LAT bit corresponding to TxPin as high before UART initialization
*/
    // URXEN disabled; RXBIMD RXBKIF flag when Break makes low-to-high transition after being low for at least 23/11 bit periods; UARTEN enabled; MOD Asynchronous 8-bit UART; UTXBRK disabled; BRKOVR TX line driven by shifter; UTXEN disabled; USIDL disabled; WAKE disabled; ABAUD disabled; BRGH enabled; 
    U1CON = 0x02000080;
    // OERIE disabled; RXBKIF disabled; RXBKIE disabled; ABDOVF disabled; OERR disabled; TXCIE disabled; TXCIF disabled; FERIE disabled; TXMTIE disabled; ABDOVE disabled; CERIE disabled; CERIF disabled; PERIE disabled; 
    U1STAT = 0x002E0080;
    // BaudRate 9600; Frequency 8000000 Hz; BRG 207; 
    U1BRG = 0xCF;
    
    U1CONbits.ON = 1;   // enabling UART ON bit
    U1CONbits.TXEN = 1;
    U1CONbits.RXEN = 1;
    
}

void UART1_Deinitialize(void)
{
    U1CON = 0x0;
    U1STAT = 0x0;
    U1BRG = 0x0;
}

uint8_t UART1_Read(void)
{
    while((U1STATbits.RXBE == 1))
    {
        
    }

    if ((U1STATbits.RXFOIF == 1))
    {
        U1STATbits.RXFOIF = 0;
    }
    
    return U1RXB;
}

void UART1_Write(uint8_t txData)
{
    while(U1STATbits.TXBF == 1)
    {
        
    }

    U1TXB = txData;    // Write the data byte to the USART.
}

bool UART1_IsRxReady(void)
{
    return (U1STATbits.RXBE == 0);
}

bool UART1_IsTxReady(void)
{
    return ((!U1STATbits.TXBF) && U1CONbits.TXEN);
}

bool UART1_IsTxDone(void)
{
    return (bool)(U1STATbits.TXMTIF && U1STATbits.TXBE);
}

void UART1_TransmitEnable(void)
{
    U1CONbits.TXEN = 1;
}

void UART1_TransmitDisable(void)
{
    U1CONbits.TXEN = 0;
}

void UART1_AutoBaudSet(bool enable)
{
    U1UIRbits.ABDIF = 0U;
    U1UIRbits.ABDIE = enable;
    U1CONbits.ABDEN = enable;
}

bool UART1_AutoBaudQuery(void)
{
    return U1CONbits.ABDEN;
}

bool UART1_AutoBaudEventEnableGet(void)
{ 
    return U1UIRbits.ABDIE; 
}

size_t UART1_ErrorGet(void)
{
    uartError.status = 0;
    if(U1STATbits.FERIF == 1U)
    {
        uartError.status = uartError.status|UART_ERROR_FRAMING_MASK;
    }
    if(U1STATbits.PERIF== 1U)
    {
        uartError.status = uartError.status|UART_ERROR_PARITY_MASK;
    }
    if(U1STATbits.RXFOIF== 1U)
    {
        uartError.status = uartError.status|UART_ERROR_RX_OVERRUN_MASK;
        U1STATbits.RXFOIF = 0;
    }
    if(U1STATbits.TXCIF== 1U)
    {
        uartError.status = uartError.status|UART_ERROR_TX_COLLISION_MASK;
        U1STATbits.TXCIF = 0;
    }
    if(U1STATbits.ABDOVF== 1U)
    {
        uartError.status = uartError.status|UART_ERROR_AUTOBAUD_OVERFLOW_MASK;
        U1STATbits.ABDOVF = 0;
    }
    
    return uartError.status;
}

void UART1_BRGCountSet(uint32_t brgValue)
{
    U1BRG = brgValue;
}

uint32_t UART1_BRGCountGet(void)
{
    uint32_t brgValue;
    brgValue = U1BRG;
    return brgValue;
}

void UART1_BaudRateSet(uint32_t baudRate)
{
    uint32_t brgValue;
    
    if((baudRate >= UART1_MIN_ACHIEVABLE_BAUD_WITH_FRACTIONAL) && (baudRate != 0u))
    {
        U1CONbits.CLKMOD = 1;
        U1CONbits.BRGS = 0;
        brgValue = UART1_BAUD_TO_BRG_WITH_FRACTIONAL(baudRate);
    }
    else if(baudRate >= UART1_MIN_ACHIEVABLE_BAUD_WITH_BRGH_1)
    {
        U1CONbits.CLKMOD = 0;
        U1CONbits.BRGS = 1;
        brgValue = UART1_BAUD_TO_BRG_WITH_BRGH_1(baudRate);
    }
    else
    {
        U1CONbits.CLKMOD = 0;
        U1CONbits.BRGS = 0;
        brgValue = UART1_BAUD_TO_BRG_WITH_BRGH_0(baudRate);
    }
    U1BRG = brgValue;
}

uint32_t UART1_BaudRateGet(void)
{
    uint32_t brgValue;
    uint32_t baudRate;
    
    brgValue = UART1_BRGCountGet();
    if((U1CONbits.CLKMOD == 1) && (brgValue != 0u))
    {
        baudRate = UART1_BRG_TO_BAUD_WITH_FRACTIONAL(brgValue);
    }
    else if(U1CONbits.BRGS == 1)
    {
        baudRate = UART1_BRG_TO_BAUD_WITH_BRGH_1(brgValue);
    }
    else
    {
        baudRate = UART1_BRG_TO_BAUD_WITH_BRGH_0(brgValue);
    }
    return baudRate;
}

int __attribute__((__section__(".libc.write"))) write(int handle, void *buffer, unsigned int len) {
    unsigned int numBytesWritten = 0 ;
    while(!UART1_IsTxDone())
    {
        
    }
    while(numBytesWritten<len)
    {
        while(!UART1_IsTxReady())
        {
            
        }
        UART1_Write(*((uint8_t *)buffer + numBytesWritten++));
    }
    return numBytesWritten;
}
