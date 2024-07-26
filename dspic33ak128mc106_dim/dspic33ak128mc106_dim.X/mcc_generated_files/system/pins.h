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
 * @skipline  Device : dsPIC33AK128MC106
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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA6 GPIO Pin which has a custom name of IO_RA6 to High
 * @pre      The RA6 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RA6_SetHigh()          (_LATA6 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA6 GPIO Pin which has a custom name of IO_RA6 to Low
 * @pre      The RA6 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA6_SetLow()           (_LATA6 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA6 GPIO Pin which has a custom name of IO_RA6
 * @pre      The RA6 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RA6_Toggle()           (_LATA6 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA6 GPIO Pin which has a custom name of IO_RA6
 * @param    none
 * @return   none  
 */
#define IO_RA6_GetValue()         _RA6

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA6 GPIO Pin which has a custom name of IO_RA6 as Input
 * @param    none
 * @return   none  
 */
#define IO_RA6_SetDigitalInput()  (_TRISA6 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA6 GPIO Pin which has a custom name of IO_RA6 as Output
 * @param    none
 * @return   none  
 */
#define IO_RA6_SetDigitalOutput() (_TRISA6 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB4 GPIO Pin which has a custom name of IO_RB4 to High
 * @pre      The RB4 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetHigh()          (_LATB4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB4 GPIO Pin which has a custom name of IO_RB4 to Low
 * @pre      The RB4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetLow()           (_LATB4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB4 GPIO Pin which has a custom name of IO_RB4
 * @pre      The RB4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB4_Toggle()           (_LATB4 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB4 GPIO Pin which has a custom name of IO_RB4
 * @param    none
 * @return   none  
 */
#define IO_RB4_GetValue()         _RB4

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB4 GPIO Pin which has a custom name of IO_RB4 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetDigitalInput()  (_TRISB4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB4 GPIO Pin which has a custom name of IO_RB4 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetDigitalOutput() (_TRISB4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB5 GPIO Pin which has a custom name of IO_RB5 to High
 * @pre      The RB5 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB5_SetHigh()          (_LATB5 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB5 GPIO Pin which has a custom name of IO_RB5 to Low
 * @pre      The RB5 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB5_SetLow()           (_LATB5 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB5 GPIO Pin which has a custom name of IO_RB5
 * @pre      The RB5 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB5_Toggle()           (_LATB5 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB5 GPIO Pin which has a custom name of IO_RB5
 * @param    none
 * @return   none  
 */
#define IO_RB5_GetValue()         _RB5

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB5 GPIO Pin which has a custom name of IO_RB5 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB5_SetDigitalInput()  (_TRISB5 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB5 GPIO Pin which has a custom name of IO_RB5 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB5_SetDigitalOutput() (_TRISB5 = 0)

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
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
