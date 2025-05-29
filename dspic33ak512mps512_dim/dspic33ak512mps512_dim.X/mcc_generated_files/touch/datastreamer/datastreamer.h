/*******************************************************************************
  @Company
    Microchip Technology Inc.

  @File Name
    datastreamer.h

  @Summary
    QTouch Modular Library

  @Description
    Provides the datastreamer APIs to data visualizer software.
	
*******************************************************************************/
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

/*******************************************************************************
 * NOTE: The touch library contains pre-release code intended solely for
 * demonstration purposes. It is not intended for production use.
 *******************************************************************************/

#ifndef __DATASTREAMER_H_
#define __DATASTREAMER_H_

/*----------------------------------------------------------------------------
 *     include files
 *----------------------------------------------------------------------------*/
#include "../touch.h"
#include "../../uart/uart_interface.h"

#if (DEF_TOUCH_DATA_STREAMER_ENABLE == 1u)
/*----------------------------------------------------------------------------
 *   prototypes
 *----------------------------------------------------------------------------*/
void datastreamer_init(const struct UART_INTERFACE * newUart);
void datastreamer_output(void);

#endif

#endif
