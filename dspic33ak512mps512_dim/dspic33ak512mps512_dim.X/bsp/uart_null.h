/**
 * UART_NULL Generated Driver Header File
 * 
 * @file      UART_NULL.h
 *            
 * @ingroup   uartdriver
 *            
 * @brief     This is the generated driver header file for the UART_NULL driver
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

#ifndef UART_NULL_H
#define UART_NULL_H

// Section: Included Files

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "../mcc_generated_files/uart/uart_interface.h"

// Section: Data Type Definitions

/**
 @ingroup  uartdriver
 @brief    Structure object of type UART_INTERFACE with the 
           custom name given by the user in the Melody Driver User interface. 
           The default name e.g. UART_NULL can be changed by the 
           user in the UART user interface. 
           This allows defining a structure with application specific name 
           using the 'Custom Name' field. Application specific name allows the 
           API Portability.
*/
extern const struct UART_INTERFACE UART_NULL_Drv;

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_Initialize API
 */
#define UART_NULL_Drv_Initialize UART_NULL_Initialize

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_Deinitialize API
 */
#define UART_NULL_Drv_Deinitialize UART_NULL_Deinitialize

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_Read API
 */
#define UART_NULL_Drv_Read UART_NULL_Read

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_Write API
 */
#define UART_NULL_Drv_Write UART_NULL_Write

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_IsRxReady API
 */
#define UART_NULL_Drv_IsRxReady UART_NULL_IsRxReady

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_IsTxReady API
 */
#define UART_NULL_Drv_IsTxReady UART_NULL_IsTxReady

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_IsTxDone API
 */
#define UART_NULL_Drv_IsTxDone UART_NULL_IsTxDone

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_TransmitEnable API
 */
#define UART_NULL_Drv_TransmitEnable UART_NULL_TransmitEnable

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_TransmitDisable API
 */
#define UART_NULL_Drv_TransmitDisable UART_NULL_TransmitDisable

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_AutoBaudSet API
 */
#define UART_NULL_Drv_AutoBaudSet UART_NULL_AutoBaudSet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_AutoBaudQuery API
 */
#define UART_NULL_Drv_AutoBaudQuery UART_NULL_AutoBaudQuery

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_AutoBaudEventEnableGet API
 */
#define UART_NULL_Drv_AutoBaudEventEnableGet UART_NULL_AutoBaudEventEnableGet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_ErrorGet API
 */
#define UART_NULL_Drv_ErrorGet UART_NULL_ErrorGet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_BRGCountSet API
 */
#define UART_NULL_Drv_BRGCountSet UART_NULL_BRGCountSet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_BRGCountGet API
 */
#define UART_NULL_Drv_BRGCountGet UART_NULL_BRGCountGet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_BaudRateSet API
 */
#define UART_NULL_Drv_BaudRateSet UART_NULL_BaudRateSet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART_NULL_BaudRateGet API
 */
#define UART_NULL_Drv_BaudRateGet UART_NULL_BaudRateGet

// Section: UART_NULL Driver Routines

/**
 * @ingroup  uartdriver
 * @brief    Initializes the UART driver
 * @param    none
 * @return   none
 */
void UART_NULL_Initialize(void);

/**
 * @ingroup  uartdriver
 * @brief    Deinitializes the UART to POR values
 * @param    none
 * @return   none
 */
void UART_NULL_Deinitialize(void);

/**
 * @ingroup  uartdriver
 * @brief    Reads a byte of data from the UART_NULL
 * @pre      UART_NULL_Initialize function should have been called
 *           before calling this function. The transfer status should be checked
 *           to see  if the receiver is not empty before calling this function.
 * @param    none
 * @return   A data byte received by the driver
 */
uint8_t UART_NULL_Read(void);

/**
 * @ingroup    uartdriver
 * @brief      Writes a byte of data to the UART_NULL
 * @pre        UART_NULL_Initialize function should have been called
 *             before calling this function. The transfer status should be checked
 *             to see if transmitter is not full before calling this function.
 * @param[in]  data - Data byte to write to the UART_NULL
 * @return     none
 */
void UART_NULL_Write(uint8_t data);

/**
 * @ingroup  uartdriver
 * @brief    Returns a boolean value if data is available to read
 * @param    none
 * @return   true  - Data available to read
 * @return   false - Data not available to read
 */
bool UART_NULL_IsRxReady(void);

/**
 * @ingroup  uartdriver
 * @brief    Returns a boolean value if data can be written
 * @param    none
 * @return   true    - Data can be written
 * @return   false   - Data can not be written
 */
bool UART_NULL_IsTxReady(void);

/**
 * @ingroup  uartdriver
 * @brief    Indicates if all bytes have been transferred
 * @param    none
 * @return   true    - All bytes transferred
 * @return   false   - Data transfer is pending
 */
bool UART_NULL_IsTxDone(void);

/**
 * @ingroup  uartdriver
 * @brief    Enables UART_NULL transmit 
 * @param    none
 * @return   none
 */
void UART_NULL_TransmitEnable(void);

/**
 * @ingroup  uartdriver
 * @brief    Disables UART_NULL transmit 
 * @param    none
 * @return   none
 */
void UART_NULL_TransmitDisable(void);

/**
 * @ingroup  uartdriver
 * @brief    Enables or disables UART_NULL Auto-Baud detection
 * @param[in]  enable - true, starts the auto-baud detection  
 * @param[in]  enable - false, disables the auto-baud detection  
 * @return   none
 */
void UART_NULL_AutoBaudSet(bool enable);

/**
 * @ingroup  uartdriver
 * @brief    Returns the status of Auto-Baud detection
 * @param    none
 * @return   true    - Auto-Baud detection in progress or counter overflow occurred
 * @return   false   - Auto-Baud detection is complete or disabled
 */
bool UART_NULL_AutoBaudQuery(void);

/**
 * @ingroup  uartdriver
 * @brief    Returns enable state of the Auto-Baud feature
 * @param    none
 * @return   true    - Auto-Baud is enabled
 * @return   false   - Auto-Baud is disabled
 */
bool UART_NULL_AutoBaudEventEnableGet(void);

/**
 * @ingroup  uartdriver
 * @brief    Sets the BRG value of UART_NULL
 * @param[in]   baudRate - BRG value upto 20 bits   
 * @return   none
 * @note    Make sure the is no transmission in progress using \ref UART_NULL_IsTxDone function
 */
void UART_NULL_BRGCountSet(uint32_t brgValue);

/**
 * @ingroup  uartdriver
 * @brief    Gets the BRG value of UART_NULL
 * @param    none
 * @return   Combined BRG value upto 20 bits
 */
uint32_t UART_NULL_BRGCountGet(void);

/**
 * @ingroup  uartdriver
 * @brief    Sets the calculated Baud-Rate of UART_NULL
 * @param[in]   baudRate - Value of Baud-Rate to be set  
 * @return   none
 * @note    Make sure the is no transmission in progress using \ref UART_NULL_IsTxDone function
 */
void UART_NULL_BaudRateSet(uint32_t baudRate);

/**
 * @ingroup  uartdriver
 * @brief    Gets the actual Baud-Rate of UART_NULL
 * @param    none
 * @return   Actual baud-rate of UART_NULL
 */
uint32_t UART_NULL_BaudRateGet(void);

/**
 * @ingroup  uartdriver
 * @brief    Returns the error status of UART_NULL
 * @param    none
 * @return   Errors with masking as per \ref UART_NULL_ERROR_MASKS
 */
size_t UART_NULL_ErrorGet(void);

#endif  // UART_NULL_H

