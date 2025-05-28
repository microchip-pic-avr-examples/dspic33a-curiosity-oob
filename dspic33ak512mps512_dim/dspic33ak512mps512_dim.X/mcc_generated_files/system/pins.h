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
 * @skipline @version   PLIB Version 1.0.1
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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC8 GPIO Pin which has a custom name of IO_RC8 to High
 * @pre      The RC8 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC8_SetHigh()          (_LATC8 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC8 GPIO Pin which has a custom name of IO_RC8 to Low
 * @pre      The RC8 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC8_SetLow()           (_LATC8 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC8 GPIO Pin which has a custom name of IO_RC8
 * @pre      The RC8 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC8_Toggle()           (_LATC8 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC8 GPIO Pin which has a custom name of IO_RC8
 * @param    none
 * @return   none  
 */
#define IO_RC8_GetValue()         _RC8

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC8 GPIO Pin which has a custom name of IO_RC8 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC8_SetDigitalInput()  (_TRISC8 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC8 GPIO Pin which has a custom name of IO_RC8 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC8_SetDigitalOutput() (_TRISC8 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC9 GPIO Pin which has a custom name of IO_RC9 to High
 * @pre      The RC9 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC9_SetHigh()          (_LATC9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC9 GPIO Pin which has a custom name of IO_RC9 to Low
 * @pre      The RC9 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC9_SetLow()           (_LATC9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC9 GPIO Pin which has a custom name of IO_RC9
 * @pre      The RC9 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC9_Toggle()           (_LATC9 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC9 GPIO Pin which has a custom name of IO_RC9
 * @param    none
 * @return   none  
 */
#define IO_RC9_GetValue()         _RC9

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC9 GPIO Pin which has a custom name of IO_RC9 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC9_SetDigitalInput()  (_TRISC9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC9 GPIO Pin which has a custom name of IO_RC9 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC9_SetDigitalOutput() (_TRISC9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC10 GPIO Pin which has a custom name of IO_RC10 to High
 * @pre      The RC10 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC10_SetHigh()          (_LATC10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC10 GPIO Pin which has a custom name of IO_RC10 to Low
 * @pre      The RC10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC10_SetLow()           (_LATC10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC10 GPIO Pin which has a custom name of IO_RC10
 * @pre      The RC10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC10_Toggle()           (_LATC10 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC10 GPIO Pin which has a custom name of IO_RC10
 * @param    none
 * @return   none  
 */
#define IO_RC10_GetValue()         _RC10

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC10 GPIO Pin which has a custom name of IO_RC10 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC10_SetDigitalInput()  (_TRISC10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC10 GPIO Pin which has a custom name of IO_RC10 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC10_SetDigitalOutput() (_TRISC10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC11 GPIO Pin which has a custom name of IO_RC11 to High
 * @pre      The RC11 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC11_SetHigh()          (_LATC11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC11 GPIO Pin which has a custom name of IO_RC11 to Low
 * @pre      The RC11 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC11_SetLow()           (_LATC11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC11 GPIO Pin which has a custom name of IO_RC11
 * @pre      The RC11 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC11_Toggle()           (_LATC11 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC11 GPIO Pin which has a custom name of IO_RC11
 * @param    none
 * @return   none  
 */
#define IO_RC11_GetValue()         _RC11

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC11 GPIO Pin which has a custom name of IO_RC11 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC11_SetDigitalInput()  (_TRISC11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC11 GPIO Pin which has a custom name of IO_RC11 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC11_SetDigitalOutput() (_TRISC11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC12 GPIO Pin which has a custom name of IO_RC12 to High
 * @pre      The RC12 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetHigh()          (_LATC12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC12 GPIO Pin which has a custom name of IO_RC12 to Low
 * @pre      The RC12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetLow()           (_LATC12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC12 GPIO Pin which has a custom name of IO_RC12
 * @pre      The RC12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC12_Toggle()           (_LATC12 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC12 GPIO Pin which has a custom name of IO_RC12
 * @param    none
 * @return   none  
 */
#define IO_RC12_GetValue()         _RC12

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC12 GPIO Pin which has a custom name of IO_RC12 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetDigitalInput()  (_TRISC12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC12 GPIO Pin which has a custom name of IO_RC12 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC12_SetDigitalOutput() (_TRISC12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC13 GPIO Pin which has a custom name of IO_RC13 to High
 * @pre      The RC13 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetHigh()          (_LATC13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC13 GPIO Pin which has a custom name of IO_RC13 to Low
 * @pre      The RC13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetLow()           (_LATC13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC13 GPIO Pin which has a custom name of IO_RC13
 * @pre      The RC13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC13_Toggle()           (_LATC13 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC13 GPIO Pin which has a custom name of IO_RC13
 * @param    none
 * @return   none  
 */
#define IO_RC13_GetValue()         _RC13

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC13 GPIO Pin which has a custom name of IO_RC13 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetDigitalInput()  (_TRISC13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC13 GPIO Pin which has a custom name of IO_RC13 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC13_SetDigitalOutput() (_TRISC13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC14 GPIO Pin which has a custom name of IO_RC14 to High
 * @pre      The RC14 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC14_SetHigh()          (_LATC14 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC14 GPIO Pin which has a custom name of IO_RC14 to Low
 * @pre      The RC14 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC14_SetLow()           (_LATC14 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC14 GPIO Pin which has a custom name of IO_RC14
 * @pre      The RC14 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC14_Toggle()           (_LATC14 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC14 GPIO Pin which has a custom name of IO_RC14
 * @param    none
 * @return   none  
 */
#define IO_RC14_GetValue()         _RC14

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC14 GPIO Pin which has a custom name of IO_RC14 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC14_SetDigitalInput()  (_TRISC14 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC14 GPIO Pin which has a custom name of IO_RC14 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC14_SetDigitalOutput() (_TRISC14 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC15 GPIO Pin which has a custom name of IO_RC15 to High
 * @pre      The RC15 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RC15_SetHigh()          (_LATC15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RC15 GPIO Pin which has a custom name of IO_RC15 to Low
 * @pre      The RC15 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC15_SetLow()           (_LATC15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RC15 GPIO Pin which has a custom name of IO_RC15
 * @pre      The RC15 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RC15_Toggle()           (_LATC15 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RC15 GPIO Pin which has a custom name of IO_RC15
 * @param    none
 * @return   none  
 */
#define IO_RC15_GetValue()         _RC15

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC15 GPIO Pin which has a custom name of IO_RC15 as Input
 * @param    none
 * @return   none  
 */
#define IO_RC15_SetDigitalInput()  (_TRISC15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RC15 GPIO Pin which has a custom name of IO_RC15 as Output
 * @param    none
 * @return   none  
 */
#define IO_RC15_SetDigitalOutput() (_TRISC15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
