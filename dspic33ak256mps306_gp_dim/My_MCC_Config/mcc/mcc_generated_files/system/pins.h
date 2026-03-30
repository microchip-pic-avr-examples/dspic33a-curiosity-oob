/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   PLIB Version 1.0.5
 *
 * @skipline  Device : dsPIC33AK256MPS306
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

/**
 * @ingroup  pinsdriver
 * @brief    Locks all the Peripheral Remapping registers and cannot be written.
 * @return   none  
 */
#define PINS_PPSLock()           (RPCONbits.IOLOCK = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Unlocks all the Peripheral Remapping registers and can be written.
 * @return   none  
 */
#define PINS_PPSUnlock()         (RPCONbits.IOLOCK = 0)

// Section: Device Pin Macros
/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC2 GPIO Pin which has a custom name of CAN_FD_Transceiver to High
 * @pre      The RC2 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define CAN_FD_Transceiver_SetHigh()          (_LATC2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC2 GPIO Pin which has a custom name of CAN_FD_Transceiver to Low
 * @pre      The RC2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define CAN_FD_Transceiver_SetLow()           (_LATC2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC2 GPIO Pin which has a custom name of CAN_FD_Transceiver
 * @pre      The RC2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define CAN_FD_Transceiver_Toggle()           (_LATC2 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC2 GPIO Pin which has a custom name of CAN_FD_Transceiver
 * @param    none
 * @return   none  
 */
#define CAN_FD_Transceiver_GetValue()         _RC2

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC2 GPIO Pin which has a custom name of CAN_FD_Transceiver as Input
 * @param    none
 * @return   none  
 */
#define CAN_FD_Transceiver_SetDigitalInput()  (_TRISC2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC2 GPIO Pin which has a custom name of CAN_FD_Transceiver as Output
 * @param    none
 * @return   none  
 */
#define CAN_FD_Transceiver_SetDigitalOutput() (_TRISC2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
