/**
 * ADC5 Generated Driver Source File
 * 
 * @file      adc5.c
 *            
 * @ingroup   adcdriver
 *            
 * @brief     This is the generated driver source file for ADC5 driver        
 *
 * @skipline @version   PLIB Version 1.1.0
 *           
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*disclaimer*/

// Section: Included Files
#include <stddef.h>
#include "../adc5.h"

// Section: File specific functions

static void (*ADC5_ChannelHandler)(enum ADC5_CHANNEL channel, uint16_t adcVal) = NULL;
static void (*ADC5_Result32BitChannelHandler)(enum ADC5_CHANNEL channel, uint32_t adcVal) = NULL;
static void (*ADC5_ComparatorHandler)(enum ADC5_CMP comparator) = NULL;

// Section: File specific data type definitions

/**
 @ingroup  adcdriver
 @enum     ADC5_PWM_TRIG_SRCS
 @brief    Defines the PWM ADC TRIGGER sources available for the module to use.
*/
enum ADC5_PWM_TRIG_SRCS {
    PWM8_TRIGGER2 = 0x13, 
    PWM8_TRIGGER1 = 0x12, 
    PWM7_TRIGGER2 = 0x11, 
    PWM7_TRIGGER1 = 0x10, 
    PWM6_TRIGGER2 = 0xf, 
    PWM6_TRIGGER1 = 0xe, 
    PWM5_TRIGGER2 = 0xd, 
    PWM5_TRIGGER1 = 0xc, 
    PWM4_TRIGGER2 = 0xb, 
    PWM4_TRIGGER1 = 0xa, 
    PWM3_TRIGGER2 = 0x9, 
    PWM3_TRIGGER1 = 0x8, 
    PWM2_TRIGGER2 = 0x7, 
    PWM2_TRIGGER1 = 0x6, 
    PWM1_TRIGGER2 = 0x5, 
    PWM1_TRIGGER1 = 0x4, 
};

//Defines an object for ADC_MULTICORE.
static const struct ADC_MULTICORE adc5Multicore = {
    .ChannelSoftwareTriggerEnable           = &ADC5_ChannelSoftwareTriggerEnable,
    .ChannelSoftwareTriggerDisable          = &ADC5_ChannelSoftwareTriggerDisable,
    .SampleCountGet                         = NULL,
    .SampleCountStatusGet                   = NULL,
    .ChannelTasks                           = &ADC5_ChannelTasks, 
    .ComparatorTasks                        = NULL,
    .IndividualChannelInterruptEnable       = &ADC5_IndividualChannelInterruptEnable,
    .IndividualChannelInterruptDisable      = &ADC5_IndividualChannelInterruptDisable,
    .IndividualChannelInterruptFlagClear    = &ADC5_IndividualChannelInterruptFlagClear,
    .IndividualChannelInterruptPrioritySet  = &ADC5_IndividualChannelInterruptPrioritySet,
    .ChannelCallbackRegister                = &ADC5_ChannelCallbackRegister,
    .Result32BitChannelCallbackRegister     = &ADC5_Result32BitChannelCallbackRegister,
    .ComparatorCallbackRegister             = &ADC5_ComparatorCallbackRegister,
    .CorePowerEnable                        = NULL,
    .SharedCorePowerEnable                  = &ADC5_SharedCorePowerEnable,
    .CoreCalibration                        = NULL,
    .SharedCoreCalibration                  = &ADC5_SharedCoreCalibration,
    .PWMTriggerSourceSet                    = &ADC5_PWMTriggerSourceSet
};

//Defines an object for ADC_INTERFACE.

const struct ADC_INTERFACE ADC5 = {
    .Initialize             = &ADC5_Initialize,
    .Deinitialize           = &ADC5_Deinitialize,
    .Enable                 = &ADC5_Enable,
    .Disable                = &ADC5_Disable,
    .SoftwareTriggerEnable  = &ADC5_SoftwareTriggerEnable,
    .SoftwareTriggerDisable = &ADC5_SoftwareTriggerDisable,
    .ChannelSelect          = NULL, 
    .ConversionResultGet    = &ADC5_ConversionResultGet,
    .SecondaryAccumulatorGet= NULL,
    .IsConversionComplete   = &ADC5_IsConversionComplete,
    .ResolutionSet          = NULL,
    .InterruptEnable        = NULL,
    .InterruptDisable       = NULL,
    .InterruptFlagClear     = NULL,
    .InterruptPrioritySet   = NULL,
    .CommonCallbackRegister = NULL,
    .Tasks                  = NULL,
    .adcMulticoreInterface = &adc5Multicore,
};

// Section: Driver Interface Function Definitions

void ADC5_Initialize(void)
{
    //CALCNT Wait for 2 activity free ADC clock cycles; BUFEN disabled; TSTEN disabled; ON enabled; STNDBY disabled; RPTCNT 1 ADC clock cycles between triggers; CALRATE Every second; ACALEN disabled; CALREQ Calibration cycle is not requested; 
    AD5CON = 0x8000UL;
    //DATAOVR 0x0; 
    AD5DATAOVR = 0x0UL;
    //CH0RDY disabled; CH1RDY disabled; CH2RDY disabled; CH3RDY disabled; CH4RDY disabled; CH5RDY disabled; CH6RDY disabled; CH7RDY disabled; CH8RDY disabled; CH9RDY disabled; CH10RDY disabled; CH11RDY disabled; CH12RDY disabled; CH13RDY disabled; CH14RDY disabled; CH15RDY disabled; 
    AD5STAT = 0x0UL;
    //CH0RRDY disabled; CH1RRDY disabled; CH2RRDY disabled; CH3RRDY disabled; CH4RRDY disabled; CH5RRDY disabled; CH6RRDY disabled; CH7RRDY disabled; CH8RRDY disabled; CH9RRDY disabled; CH10RRDY disabled; CH11RRDY disabled; CH12RRDY disabled; CH13RRDY disabled; CH14RRDY disabled; CH15RRDY disabled; 
    AD5RSTAT = 0x0UL;
    //CH0CMP disabled; CH1CMP disabled; CH2CMP disabled; CH3CMP disabled; CH4CMP disabled; CH5CMP disabled; CH6CMP disabled; CH7CMP disabled; CH8CMP disabled; CH9CMP disabled; CH10CMP disabled; CH11CMP disabled; CH12CMP disabled; CH13CMP disabled; CH14CMP disabled; CH15CMP disabled; 
    AD5CMPSTAT = 0x0UL;
    //CH0TRG disabled; CH1TRG disabled; CH2TRG disabled; CH3TRG disabled; CH4TRG disabled; CH5TRG disabled; CH6TRG disabled; CH7TRG disabled; CH8TRG disabled; CH9TRG disabled; CH10TRG disabled; CH11TRG disabled; CH12TRG disabled; CH13TRG disabled; CH14TRG disabled; CH15TRG disabled; 
    AD5SWTRG = 0x0UL;
    //TRG1SRC Software trigger initiated by using ADnSWTRG register; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH0CON1 = 0x200001UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH1CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH2CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH3CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH4CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH5CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH6CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH7CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH8CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH9CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH10CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH11CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH12CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH13CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH14CON1 = 0x200000UL;
    //TRG1SRC Triggers are disabled; MODE Single sample initiated by TRG1SRC[4:0] trigger; TRG2SRC Triggers are disabled; ACCNUM 4 samples, 13 bits result; SAMC 0.5 TAD; IRQSEL enabled; EIEN disabled; TRG1POL disabled; PINSEL AD5AN0; NINSEL disabled; FRAC Integer; DIFF disabled; 
    AD5CH15CON1 = 0x200000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH0CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH1CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH2CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH3CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH4CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH5CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH6CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH7CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH8CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH9CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH10CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH11CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH12CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH13CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH14CON2 = 0x20000000UL;
    //ADCMPCNT disabled; CMPMOD NONE; CMPCNTMOD disabled; CMPVAL enabled; ACCBRST disabled; ACCRO disabled; 
    AD5CH15CON2 = 0x20000000UL;
    //
    AD5CH0RES = 0x0UL;
    //
    AD5CH1RES = 0x0UL;
    //
    AD5CH2RES = 0x0UL;
    //
    AD5CH3RES = 0x0UL;
    //
    AD5CH4RES = 0x0UL;
    //
    AD5CH5RES = 0x0UL;
    //
    AD5CH6RES = 0x0UL;
    //
    AD5CH7RES = 0x0UL;
    //
    AD5CH8RES = 0x0UL;
    //
    AD5CH9RES = 0x0UL;
    //
    AD5CH10RES = 0x0UL;
    //
    AD5CH11RES = 0x0UL;
    //
    AD5CH12RES = 0x0UL;
    //
    AD5CH13RES = 0x0UL;
    //
    AD5CH14RES = 0x0UL;
    //
    AD5CH15RES = 0x0UL;
    //CNT 0x0; 
    AD5CH0CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH1CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH2CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH3CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH4CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH5CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH6CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH7CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH8CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH9CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH10CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH11CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH12CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH13CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH14CNT = 0x0UL;
    //CNT 0x0; 
    AD5CH15CNT = 0x0UL;
    //CMPLO 0x0; 
    AD5CH0CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH1CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH2CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH3CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH4CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH5CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH6CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH7CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH8CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH9CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH10CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH11CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH12CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH13CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH14CMPLO = 0x0UL;
    //CMPLO 0x0; 
    AD5CH15CMPLO = 0x0UL;
    //CMPHI 0x0; 
    AD5CH0CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH1CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH2CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH3CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH4CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH5CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH6CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH7CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH8CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH9CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH10CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH11CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH12CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH13CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH14CMPHI = 0x0UL;
    //CMPHI 0x0; 
    AD5CH15CMPHI = 0x0UL;

    ADC5_ChannelCallbackRegister(&ADC5_ChannelCallback);
    ADC5_Result32BitChannelCallbackRegister(&ADC5_Result32BitChannelCallback);
    ADC5_ComparatorCallbackRegister(&ADC5_ComparatorCallback);
    
    
    // ADC Mode change to run mode
    ADC5_SharedCorePowerEnable();
}

void ADC5_Deinitialize (void)
{
    AD5CONbits.ON = 0U;
    
    AD5CON = 0x480000UL;
    AD5DATAOVR = 0x0UL;
    AD5STAT = 0x0UL;
    AD5RSTAT = 0x0UL;
    AD5CMPSTAT = 0x0UL;
    AD5SWTRG = 0x0UL;
    AD5CH0CON1 = 0x0UL;
    AD5CH1CON1 = 0x0UL;
    AD5CH2CON1 = 0x0UL;
    AD5CH3CON1 = 0x0UL;
    AD5CH4CON1 = 0x0UL;
    AD5CH5CON1 = 0x0UL;
    AD5CH6CON1 = 0x0UL;
    AD5CH7CON1 = 0x0UL;
    AD5CH8CON1 = 0x0UL;
    AD5CH9CON1 = 0x0UL;
    AD5CH10CON1 = 0x0UL;
    AD5CH11CON1 = 0x0UL;
    AD5CH12CON1 = 0x0UL;
    AD5CH13CON1 = 0x0UL;
    AD5CH14CON1 = 0x0UL;
    AD5CH15CON1 = 0x0UL;
    AD5CH0CON2 = 0x1UL;
    AD5CH1CON2 = 0x1UL;
    AD5CH2CON2 = 0x1UL;
    AD5CH3CON2 = 0x1UL;
    AD5CH4CON2 = 0x1UL;
    AD5CH5CON2 = 0x1UL;
    AD5CH6CON2 = 0x1UL;
    AD5CH7CON2 = 0x1UL;
    AD5CH8CON2 = 0x1UL;
    AD5CH9CON2 = 0x1UL;
    AD5CH10CON2 = 0x1UL;
    AD5CH11CON2 = 0x1UL;
    AD5CH12CON2 = 0x1UL;
    AD5CH13CON2 = 0x1UL;
    AD5CH14CON2 = 0x1UL;
    AD5CH15CON2 = 0x1UL;
    AD5CH0RES = 0x0UL;
    AD5CH1RES = 0x0UL;
    AD5CH2RES = 0x0UL;
    AD5CH3RES = 0x0UL;
    AD5CH4RES = 0x0UL;
    AD5CH5RES = 0x0UL;
    AD5CH6RES = 0x0UL;
    AD5CH7RES = 0x0UL;
    AD5CH8RES = 0x0UL;
    AD5CH9RES = 0x0UL;
    AD5CH10RES = 0x0UL;
    AD5CH11RES = 0x0UL;
    AD5CH12RES = 0x0UL;
    AD5CH13RES = 0x0UL;
    AD5CH14RES = 0x0UL;
    AD5CH15RES = 0x0UL;
    AD5CH0CNT = 0x0UL;
    AD5CH1CNT = 0x0UL;
    AD5CH2CNT = 0x0UL;
    AD5CH3CNT = 0x0UL;
    AD5CH4CNT = 0x0UL;
    AD5CH5CNT = 0x0UL;
    AD5CH6CNT = 0x0UL;
    AD5CH7CNT = 0x0UL;
    AD5CH8CNT = 0x0UL;
    AD5CH9CNT = 0x0UL;
    AD5CH10CNT = 0x0UL;
    AD5CH11CNT = 0x0UL;
    AD5CH12CNT = 0x0UL;
    AD5CH13CNT = 0x0UL;
    AD5CH14CNT = 0x0UL;
    AD5CH15CNT = 0x0UL;
    AD5CH0CMPLO = 0x0UL;
    AD5CH1CMPLO = 0x0UL;
    AD5CH2CMPLO = 0x0UL;
    AD5CH3CMPLO = 0x0UL;
    AD5CH4CMPLO = 0x0UL;
    AD5CH5CMPLO = 0x0UL;
    AD5CH6CMPLO = 0x0UL;
    AD5CH7CMPLO = 0x0UL;
    AD5CH8CMPLO = 0x0UL;
    AD5CH9CMPLO = 0x0UL;
    AD5CH10CMPLO = 0x0UL;
    AD5CH11CMPLO = 0x0UL;
    AD5CH12CMPLO = 0x0UL;
    AD5CH13CMPLO = 0x0UL;
    AD5CH14CMPLO = 0x0UL;
    AD5CH15CMPLO = 0x0UL;
    AD5CH0CMPHI = 0x0UL;
    AD5CH1CMPHI = 0x0UL;
    AD5CH2CMPHI = 0x0UL;
    AD5CH3CMPHI = 0x0UL;
    AD5CH4CMPHI = 0x0UL;
    AD5CH5CMPHI = 0x0UL;
    AD5CH6CMPHI = 0x0UL;
    AD5CH7CMPHI = 0x0UL;
    AD5CH8CMPHI = 0x0UL;
    AD5CH9CMPHI = 0x0UL;
    AD5CH10CMPHI = 0x0UL;
    AD5CH11CMPHI = 0x0UL;
    AD5CH12CMPHI = 0x0UL;
    AD5CH13CMPHI = 0x0UL;
    AD5CH14CMPHI = 0x0UL;
    AD5CH15CMPHI = 0x0UL;
}

void ADC5_SharedCorePowerEnable (void) 
{
    AD5CONbits.ON = 1U;   
    while(AD5CONbits.ADRDY == 0U)
    {
    }
}

void ADC5_SharedCoreCalibration (void) 
{
    AD5CONbits.CALREQ = 1U;    
    while(AD5CONbits.CALRDY == 0U)
    {
    }  
}

static uint16_t ADC5_TriggerSourceValueGet(enum ADC_PWM_INSTANCE pwmInstance, enum ADC_PWM_TRIGGERS triggerNumber)
{
    uint16_t adcTriggerSourceValue = 0x0U;
    switch(pwmInstance)
    {
        case ADC_PWM_GENERATOR_8:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM8_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM8_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_7:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM7_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM7_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_6:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM6_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM6_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_5:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM5_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM5_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_4:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM4_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM4_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_3:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM3_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM3_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_2:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM2_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM2_TRIGGER2;
                }
                else
                {
                }
                break;
        case ADC_PWM_GENERATOR_1:
                if(triggerNumber == ADC_PWM_TRIGGER_1)
                {
                    adcTriggerSourceValue = PWM1_TRIGGER1;
                }
                else if(triggerNumber == ADC_PWM_TRIGGER_2)
                {
                    adcTriggerSourceValue = PWM1_TRIGGER2;
                }
                else
                {
                }
                break;
         default:
                break;
    }
    return adcTriggerSourceValue;
}

void ADC5_PWMTriggerSourceSet(enum ADC5_CHANNEL channel, enum ADC_PWM_INSTANCE pwmInstance, enum ADC_PWM_TRIGGERS triggerNumber)
{
    uint16_t adcTriggerValue;
    adcTriggerValue= ADC5_TriggerSourceValueGet(pwmInstance, triggerNumber);
    switch(channel)
    {
        case ADC5_Channel0:
                AD5SWTRGbits.CH0TRG = adcTriggerValue;
                break;
        default:
                break;
    }
}

void ADC5_ChannelCallbackRegister(void(*callback)(enum ADC5_CHANNEL channel, uint16_t adcVal))
{
    if(NULL != callback)
    {
        ADC5_ChannelHandler = callback;
    }
}

void __attribute__ ((weak)) ADC5_ChannelCallback (enum ADC5_CHANNEL channel, uint16_t adcVal)
{ 
    (void)channel;
    (void)adcVal;
} 

void ADC5_Result32BitChannelCallbackRegister(void(*callback)(enum ADC5_CHANNEL channel, uint32_t adcVal))
{
    if(NULL != callback)
    {
        ADC5_Result32BitChannelHandler = callback;
    }
}

void __attribute__ ((weak)) ADC5_Result32BitChannelCallback (enum ADC5_CHANNEL channel, uint32_t adcVal)
{ 
    (void)channel;
    (void)adcVal;
} 


void __attribute__ ( ( __interrupt__ , auto_psv, weak ) ) _AD5CH0Interrupt ( void )
{
    uint32_t valADC5_Channel0;
    //Read the ADC value from the ADCBUF
    valADC5_Channel0 = AD5CH0DATA;

    if(NULL != ADC5_ChannelHandler)
    {
        (*ADC5_ChannelHandler)(ADC5_Channel0, valADC5_Channel0);
    }
    if(NULL != ADC5_Result32BitChannelHandler)
    {
        (*ADC5_Result32BitChannelHandler)(ADC5_Channel0, valADC5_Channel0);
    }

    //clear the ADC5_Channel0 interrupt flag
    IFS7bits.AD5CH0IF = 0U;
}


void __attribute__ ((weak)) ADC5_ChannelTasks (enum ADC5_CHANNEL channel)
{
    uint32_t adcVal;
    
    switch(channel)
    {   
        case ADC5_Channel0:
            if((bool)AD5STATbits.CH0RDY == 1U)
            {
                //Read the ADC value from the ADCBUF
                adcVal = AD5CH0DATA;

                if(NULL != ADC5_ChannelHandler)
                {
                    (*ADC5_ChannelHandler)(channel, adcVal);
                }
                if(NULL != ADC5_Result32BitChannelHandler)
                {
                    (*ADC5_Result32BitChannelHandler)(channel, adcVal);
                }
            }
            break;
        default:
            break;
    }            
}

void ADC5_ComparatorCallbackRegister(void(*callback)(enum ADC5_CMP comparator))
{
    if(NULL != callback)
    {
        ADC5_ComparatorHandler = callback;
    }
}

void __attribute__ ((weak)) ADC5_ComparatorCallback (enum ADC5_CMP comparator)
{ 
    (void)comparator;
} 



