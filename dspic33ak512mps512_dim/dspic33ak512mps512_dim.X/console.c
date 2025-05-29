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

#include "console.h"

#include <stdio.h>

static void Print(char*);
static void Initialize(const struct UART_INTERFACE*);
static void Clear(void);
static void CursorRowSet(int row);
static void CursorHide(void);
static bool Scan(char* c);

static const struct UART_INTERFACE* uart = NULL;
static bool echo = true;
static char printBuffer[40];

struct CONSOLE console = {
    .initialize = Initialize,
    .print = Print,
    .clear = Clear,
    .cursorRowSet = CursorRowSet,
    .cursorHide = CursorHide,
    .scan = Scan
};

static void Print(char* data)
{
    while(*data != 0)
    {
        uart->Write(*data);
        data++;
    }
}

static void Clear(void)
{
    Print("\033[2J"); 
}

static void CursorRowSet(int row)
{    
    sprintf(printBuffer,"\033[%d;0f", row);
    Print(printBuffer);
}

static void CursorHide()
{
    Print("\033[?25l");
}

static void Initialize(const struct UART_INTERFACE* newUart)
{
    uart = newUart;
}

static bool Scan(char* c)
{
    bool readData = false;
    
    if(uart->IsRxReady())
    {
        *c = uart->Read();
        readData = true;
        
        if(true == echo)
        {
            while(!uart->IsTxReady()) 
            {     
            }

            uart->Write(*c);       
        }
    }
    
    return readData;
}