/**
 * PINS Generated Driver Source File 
 * 
 * @file      pins.c
 *            
 * @ingroup   pinsdriver
 *            
 * @brief     This is the generated driver source file for PINS driver.
 *
 * @skipline @version   PLIB Version 1.0.1
 *
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*
� [2025] Microchip Technology Inc. and its subsidiaries.

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

// Section: Includes
#include <xc.h>
#include <stddef.h>
#include "../pins.h"

// Section: File specific functions

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

// Section: Driver Interface Function Definitions
void PINS_Initialize(void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000UL;
    LATB = 0x0000UL;
    LATC = 0x0000UL;
    LATD = 0x0000UL;
    LATE = 0x0000UL;
    LATF = 0x0000UL;
    LATG = 0x0000UL;
    LATH = 0x0002UL;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0xFFFFUL;
    TRISB = 0xFFFFUL;
    TRISC = 0x00FEUL;
    TRISD = 0xFDFAUL;
    TRISE = 0x07FFUL;
    TRISF = 0x0FEFUL;
    TRISG = 0x03F7UL;
    TRISH = 0x0005UL;


    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPUA = 0x0000UL;
    CNPUB = 0x0000UL;
    CNPUC = 0x0000UL;
    CNPUD = 0x0000UL;
    CNPUE = 0x0000UL;
    CNPUF = 0x0000UL;
    CNPUG = 0x0000UL;
    CNPUH = 0x0000UL;
    CNPDA = 0x0000UL;
    CNPDB = 0x0000UL;
    CNPDC = 0x0000UL;
    CNPDD = 0x0000UL;
    CNPDE = 0x0000UL;
    CNPDF = 0x0000UL;
    CNPDG = 0x0000UL;
    CNPDH = 0x0000UL;


    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000UL;
    ODCB = 0x0000UL;
    ODCC = 0x0000UL;
    ODCD = 0x0000UL;
    ODCE = 0x0000UL;
    ODCF = 0x0000UL;
    ODCG = 0x0000UL;
    ODCH = 0x0000UL;


    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0xFFFFUL;
    ANSELB = 0xFFFFUL;
    ANSELE = 0x0003UL;
    ANSELF = 0x0001UL;

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    PINS_PPSUnlock(); // unlock PPS

    RPINR13bits.U1RXR = 0x0032UL; //RD1->UART1:U1RX;
    RPOR14bits.RP58R = 0x0028UL;  //RD9->SCCP2:OCM2;
    RPOR12bits.RP49R = 0x0027UL;  //RD0->SCCP1:OCM1;
    RPOR12bits.RP51R = 0x0029UL;  //RD2->SCCP3:OCM3;
    RPOR28bits.RP114R = 0x0013UL;  //RH1->UART1:U1TX;

    _CAN1RXR = 60;              //RD11 -> CAN1RX
    _RP62R = _RPOUT_CAN1TX;     //RD13 -> CAN1TX
    LATDbits.LATD14 = 0;        //Enable CAN Transceiver drive STBY low
    TRISDbits.TRISD14 = 0;
    PINS_PPSLock(); // lock PPS


}

