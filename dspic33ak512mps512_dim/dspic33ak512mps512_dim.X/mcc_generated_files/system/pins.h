/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver PINS Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @version   Firmware Driver Version 1.0.1
 *
 * @version   PLIB Version 1.0.0
 *
 * @skipline  Device : dsPIC33AK128MC106
*/

/*disclaimer*/

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of IO_RA0 to High
 * @pre      The RA0 must be set as Output Pin             
 * @return   none  
 */
#define IO_RA0_SetHigh()          (_LATA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of IO_RA0 to Low
 * @pre      The RA0 must be set as Output Pin
 * @return   none  
 */
#define IO_RA0_SetLow()           (_LATA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA0 GPIO Pin which has a custom name of IO_RA0
 * @pre      The RA0 must be set as Output Pin
 * @return   none  
 */
#define IO_RA0_Toggle()           (_LATA0 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA0 GPIO Pin which has a custom name of IO_RA0
 * @return   none  
 */
#define IO_RA0_GetValue()         _RA0

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of IO_RA0 as Input
 * @return   none  
 */
#define IO_RA0_SetDigitalInput()  (_TRISA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of IO_RA0 as Output
 * @return   none  
 */
#define IO_RA0_SetDigitalOutput() (_TRISA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB1 GPIO Pin which has a custom name of IO_RB1 to High
 * @pre      The RB1 must be set as Output Pin             
 * @return   none  
 */
#define IO_RB1_SetHigh()          (_LATB1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB1 GPIO Pin which has a custom name of IO_RB1 to Low
 * @pre      The RB1 must be set as Output Pin
 * @return   none  
 */
#define IO_RB1_SetLow()           (_LATB1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB1 GPIO Pin which has a custom name of IO_RB1
 * @pre      The RB1 must be set as Output Pin
 * @return   none  
 */
#define IO_RB1_Toggle()           (_LATB1 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB1 GPIO Pin which has a custom name of IO_RB1
 * @return   none  
 */
#define IO_RB1_GetValue()         _RB1

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB1 GPIO Pin which has a custom name of IO_RB1 as Input
 * @return   none  
 */
#define IO_RB1_SetDigitalInput()  (_TRISB1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB1 GPIO Pin which has a custom name of IO_RB1 as Output
 * @return   none  
 */
#define IO_RB1_SetDigitalOutput() (_TRISB1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA1 GPIO Pin which has a custom name of IO_RA1 to High
 * @pre      The RA1 must be set as Output Pin             
 * @return   none  
 */
#define IO_RA1_SetHigh()          (_LATA1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA1 GPIO Pin which has a custom name of IO_RA1 to Low
 * @pre      The RA1 must be set as Output Pin
 * @return   none  
 */
#define IO_RA1_SetLow()           (_LATA1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA1 GPIO Pin which has a custom name of IO_RA1
 * @pre      The RA1 must be set as Output Pin
 * @return   none  
 */
#define IO_RA1_Toggle()           (_LATA1 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA1 GPIO Pin which has a custom name of IO_RA1
 * @return   none  
 */
#define IO_RA1_GetValue()         _RA1

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA1 GPIO Pin which has a custom name of IO_RA1 as Input
 * @return   none  
 */
#define IO_RA1_SetDigitalInput()  (_TRISA1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA1 GPIO Pin which has a custom name of IO_RA1 as Output
 * @return   none  
 */
#define IO_RA1_SetDigitalOutput() (_TRISA1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB9 GPIO Pin which has a custom name of IO_RB9 to High
 * @pre      The RB9 must be set as Output Pin             
 * @return   none  
 */
#define IO_RB9_SetHigh()          (_LATB9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB9 GPIO Pin which has a custom name of IO_RB9 to Low
 * @pre      The RB9 must be set as Output Pin
 * @return   none  
 */
#define IO_RB9_SetLow()           (_LATB9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB9 GPIO Pin which has a custom name of IO_RB9
 * @pre      The RB9 must be set as Output Pin
 * @return   none  
 */
#define IO_RB9_Toggle()           (_LATB9 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB9 GPIO Pin which has a custom name of IO_RB9
 * @return   none  
 */
#define IO_RB9_GetValue()         _RB9

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB9 GPIO Pin which has a custom name of IO_RB9 as Input
 * @return   none  
 */
#define IO_RB9_SetDigitalInput()  (_TRISB9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB9 GPIO Pin which has a custom name of IO_RB9 as Output
 * @return   none  
 */
#define IO_RB9_SetDigitalOutput() (_TRISB9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB8 GPIO Pin which has a custom name of IO_RB8 to High
 * @pre      The RB8 must be set as Output Pin             
 * @return   none  
 */
#define IO_RB8_SetHigh()          (_LATB8 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB8 GPIO Pin which has a custom name of IO_RB8 to Low
 * @pre      The RB8 must be set as Output Pin
 * @return   none  
 */
#define IO_RB8_SetLow()           (_LATB8 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB8 GPIO Pin which has a custom name of IO_RB8
 * @pre      The RB8 must be set as Output Pin
 * @return   none  
 */
#define IO_RB8_Toggle()           (_LATB8 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB8 GPIO Pin which has a custom name of IO_RB8
 * @return   none  
 */
#define IO_RB8_GetValue()         _RB8

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB8 GPIO Pin which has a custom name of IO_RB8 as Input
 * @return   none  
 */
#define IO_RB8_SetDigitalInput()  (_TRISB8 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB8 GPIO Pin which has a custom name of IO_RB8 as Output
 * @return   none  
 */
#define IO_RB8_SetDigitalOutput() (_TRISB8 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @return   none  
 */
void PINS_Initialize(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for IO_RA1 Pin
 * @return   none   
 */
void IO_RA1_CallBack(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for IO_RA0 Pin
 * @return   none   
 */
void IO_RA0_CallBack(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for IO_RA2 Pin
 * @return   none   
 */
void IO_RA2_CallBack(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for IO_RB2 Pin
 * @return   none   
 */
void IO_RB2_CallBack(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for IO_RB4 Pin
 * @return   none   
 */
void IO_RB4_CallBack(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for IO_RB3 Pin
 * @return   none   
 */
void IO_RB3_CallBack(void);


/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void IO_RA1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void IO_RA0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void IO_RA2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void IO_RB2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void IO_RB4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void IO_RB3_SetInterruptHandler(void (* InterruptHandler)(void));


#endif
