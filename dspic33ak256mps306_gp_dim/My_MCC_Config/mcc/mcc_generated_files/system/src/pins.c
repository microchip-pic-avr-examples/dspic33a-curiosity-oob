/**
 * PINS Generated Driver Source File 
 * 
 * @file      pins.c
 *            
 * @ingroup   pinsdriver
 *            
 * @brief     This is the generated driver source file for PINS driver.
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

// Section: Includes
#include <xc.h>
#include <stddef.h>
#include "../pins.h"

// Section: File specific functions

// Section: Driver Interface Function Definitions
void PINS_Initialize(void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000UL;
    LATB = 0x0000UL;
    LATC = 0x0400UL;
    LATD = 0x0000UL;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x0BFBUL;
    TRISB = 0x3FFFUL;
    TRISC = 0x0BDAUL;
    TRISD = 0x01FFUL;


    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPUA = 0x0000UL;
    CNPUB = 0x0000UL;
    CNPUC = 0x0000UL;
    CNPUD = 0x0000UL;
    CNPDA = 0x0000UL;
    CNPDB = 0x0000UL;
    CNPDC = 0x0000UL;
    CNPDD = 0x0000UL;


    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000UL;
    ODCB = 0x0000UL;
    ODCC = 0x0000UL;
    ODCD = 0x0000UL;


    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x0BFBUL;
    ANSELB = 0x0FFFUL;
    ANSELC = 0x00C0UL;
    ANSELD = 0x0060UL;

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
      PINS_PPSUnlock(); // unlock PPS

        RPINR17bits.CAN1RXR = 0x0024UL; //RC3->CAN1:CAN1RX;
        RPINR13bits.U1RXR = 0x0025UL; //RC4->UART1:U1RX;
        RPOR0bits.RP3R = 0x001EUL;  //RA2->SCCP2:OCM2;
        RPOR2bits.RP11R = 0x001DUL;  //RA10->SCCP1:OCM1;
        RPOR8bits.RP33R = 0x001FUL;  //RC0->SCCP3:OCM3;
        RPOR9bits.RP38R = 0x0009UL;  //RC5->CAN1:CAN1TX;
        RPOR10bits.RP43R = 0x000AUL;  //RC10->UART1:U1TX;

      PINS_PPSLock(); // lock PPS


}

