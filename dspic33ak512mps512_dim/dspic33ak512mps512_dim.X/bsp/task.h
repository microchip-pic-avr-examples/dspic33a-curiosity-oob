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

#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @ingroup  task
 * @brief    Initializes the task scheduler.  Must be called before all other functions.
 * @param    none
 * @return   none
 */
void TASK_Initialize(void);

/**
 * @ingroup  task
 * @brief    Request a function to be called after specified number of millseconds.
 * @param[in] void (*task)(void) - function to call
 * @param[in] uint32_t milliseconds - how frequently to call the function
 * @return   bool - true: was able to set request, false: unable to handle request
 */
bool TASK_Request(void (*task)(void), uint32_t milliseconds);

/**
 * @ingroup  task
 * @brief    Stop a previous request from triggering again.
 * @param[in] void (*task)(void) - function representing the task to cancel
 * @return   none
 */
void TASK_Cancel(void (*task)(void));

/**
 * @ingroup  task
 * @brief    Interrupt handler - needs to be called once per millisecond
 * @return   none
 */
void TASK_InterruptHandler(void);

#endif