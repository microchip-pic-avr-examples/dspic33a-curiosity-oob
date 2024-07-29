/**
 * CLOCK Generated Driver Source File 
 * 
 * @file      clock.c
 *            
 * @ingroup   clockdriver
 *            
 * @brief     This is the generated source file for CLOCK driver
 *            
 * @version   Driver Version 1.0.1
 *            
 * @skipline  Device : dsPIC33CH128MP508
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

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
#include <stdint.h>
#include "../clock.h"
#include "../../clock_settings.h"

//to be removed in template
void CLOCK_Initialize(void)
{
    OSCCFGbits.POSCMD = POSCMD_XT_MODE;
    
    CLK1CON = (CLKCON_ON_1|CLKCON_OE_1|CLKCON_BOSC_BFRC|CLKCON_FSCMEN_1|CLKCON_NOSC_FRC);
    CLK1DIV = (CLKDIV_FRACDIV_2_P1x(0UL)|CLKDIV_INTDIV_2x(1UL));
        
    CLK1CONbits.DIVSWEN = 1; //enable divide factors to get updated
    while (CLK1CONbits.DIVSWEN == 1) //hardware cleared 
    {
    }

    CLK1CONbits.OSWEN = 1; //enable clock switching
    while (CLK1CONbits.OSWEN == 1) //wait for switching(hardware clear))
    {
    } 
    
    //Generator3 clock switch
    CLK3CON = (CLKCON_ON_1|CLKCON_OE_1|CLKCON_BOSC_BFRC|CLKCON_FSCMEN_1|CLKCON_NOSC_BFRC);
        
    CLK3CONbits.DIVSWEN = 1; //enable divide factors to get updated
    while (CLK3CONbits.DIVSWEN == 1) //hardware cleared 
    {
    }

    CLK3CONbits.OSWEN = 1; //enable clock switching
    while (CLK3CONbits.OSWEN == 1) //wait for switching(hardware clear))
    {
    }
    
    //Generator8 clock switch
    CLK8CON = (CLKCON_ON_1|CLKCON_OE_1|CLKCON_BOSC_BFRC|CLKCON_FSCMEN_1|CLKCON_NOSC_FRC);
        
    CLK8CONbits.DIVSWEN = 1; //enable divide factors to get updated
    while (CLK8CONbits.DIVSWEN == 1) //hardware cleared 
    {
    }

    CLK8CONbits.OSWEN = 1; //enable clock switching
    while (CLK8CONbits.OSWEN == 1) //wait for switching(hardware clear))
    {
    }

    //Clock diagnostics control register, clock monitor and fault injection bits
    
    //FRC tuner
    FRCTUN = 0x0; 
    
    //BFRC tuning
    BFRCTUN =0x0; 
    
    //Clock Monitor control register
    CM1CON = 0x0;
    CM2CON = 0x0;
    CM3CON = 0x0;
    CM4CON = 0x0;
    
    //Clock monitor status register
    CM1STAT = 0x0;
    CM2STAT = 0x0;
    CM3STAT = 0x0;
    CM4STAT = 0x0;
    
    //Clock monitor prescalar
    CM1WINPR = 0x0;
    CM2WINPR = 0x0;
    CM3WINPR = 0x0;
    CM4WINPR = 0x0;
    
    //Clock monitor Input selection register
    CM1SEL = 0x0;
    CM2SEL = 0x0;
    CM3SEL = 0x0;
    CM4SEL = 0x0;
    
    //Clock monitor last fetched count buffer
    CM1BUF = 0x0;
    CM2BUF = 0x0;
    CM3BUF = 0x0;
    CM4BUF = 0x0;
    
    //Clock monitor saturation value
    CM1SAT = 0x0;
    CM2SAT = 0x0;
    CM3SAT = 0x0;
    CM4SAT = 0x0;
    
    //Clock monitor high value fail
    CM1HFAIL = 0x0;
    CM2HFAIL = 0x0;
    CM3HFAIL = 0x0;
    CM4HFAIL = 0x0;
    
    //Clock monitor low value fail
    CM1LFAIL = 0x0;
    CM2LFAIL = 0x0;
    CM3LFAIL = 0x0;
    CM4LFAIL = 0x0;
    
    //Clock monitor high warning
    CM1HWARN = 0x0;
    CM2HWARN = 0x0;
    CM3HWARN = 0x0;
    CM4HWARN = 0x0;

    //Clock monitor low warning
    CM1LWARN = 0x0;
    CM2LWARN = 0x0;
    CM3LWARN = 0x0;
    CM4LWARN = 0x0;
}