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

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include <xc.h>

#ifndef TASK_MAX_COUNT
#define TASK_MAX_COUNT 10u
#endif

struct TASK
{
    void (*task)(void);
    uint32_t rate;
    uint32_t count;
};

static struct TASK tasks[TASK_MAX_COUNT];

void TASK_Initialize(void)
{
    T1CON = 0;
    
    (void)memset(tasks, 0, sizeof(tasks));
    
    PR1 = 0x000007DA;

    IEC1bits.T1IE = 1;
    T1CONbits.ON = 1;
}

bool TASK_Request(void (*task)(void), uint32_t milliseconds)
{
    unsigned int i;
    bool status = false;
    
    for(i=0; i<TASK_MAX_COUNT; i++)
    {
        if(tasks[i].rate == 0u)
        {
            tasks[i].rate = milliseconds;
            tasks[i].task = task;
            tasks[i].count = 0;
            
            status = true;
            break;
        }
    }
    
    return status;
}

void TASK_Cancel(void (*task)(void))
{
    unsigned int i;
    
    for(i=0; i<TASK_MAX_COUNT; i++)
    {
        if(tasks[i].task == task)
        {
            tasks[i].rate = 0;
        }
    }
}

void __attribute__ ( ( __interrupt__ , auto_psv ) ) _T1Interrupt ( void )
{
    unsigned int i ;

    for (i=0; i<TASK_MAX_COUNT; i++)
    {
        if (tasks[i].rate != 0)
        {
            tasks[i].count++ ;

            if (tasks[i].count == tasks[i].rate)
            {
                tasks[i].task() ;
                tasks[i].count = 0 ;
            }
        }
    }

    IFS1bits.T1IF = 0 ;
}


