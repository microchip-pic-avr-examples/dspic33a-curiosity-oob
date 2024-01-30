/*******************************************************************************
Copyright 2024 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

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


