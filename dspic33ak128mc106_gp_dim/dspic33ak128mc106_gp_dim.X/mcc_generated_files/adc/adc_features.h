/**
 * ADC Generated Feature Header File
 * 
 * @file      adc_features.h
 *            
 * @ingroup   adcdriver
 *            
 * @brief     This is the generated module feature header file for ADC driver
 *            This file provides module feature list available on the selected device. 
 *            The macros defined in this file provides the flexibility to easily migrate 
 *            the user application to other device which might have varied feature list. 
 *            The content in this file is strictly "read only" and should not be altered.
 *            
 *
 * @skipline @version   PLIB Version 1.0.1
 *            
 * @skipline  Device : 
*/

/*disclaimer*/

#ifndef ADC_FEATURES
#define ADC_FEATURES
        
/*******************************************************************************
********************************************************************************
******************************************************************************** 
                            ********IMPORTANT********

This file defines the ADC module feature C-macros available 
on the selected device. The macros defined in this file provides the 
flexibility to easily migrate the user application to other device which might 
have varied feature list.

The file has to be manually included in main.c, if the user intends to migrate the
application to another device which might have varied feature list.
  
  
 ***************The content in this file is strictly "read only" and should 
 not be altered. Failing to do so, the migration is not guaranteed.*************

********************************************************************************
********************************************************************************         
********************************************************************************/

/*******************************************************************************
            Macros defined for features supported in the device
*******************************************************************************/

/** 
 @ingroup  adcdriver
 @brief    This macro defines the ADC core power enable functionality

  <b>APIs Supported:</b><br>
   void ADCx_CorePowerEnable (enum ADC_CHANNEL channel);<br>
   void ADC_SharedCorePowerEnable (void);<br>
   
   x denotes instance of ADC in ADCx, channel denotes dedicated Core. 
   Refer to device specific datasheet to check number of cores and ADC module instance.
   Refer driver header file for detailed description of the APIs.
  
*/
#define ADC_POWER_ENABLE_FEATURE_AVAILABLE  1

/** 
 @ingroup  adcdriver
 @brief    This macro defines the macro associated with ADC core calibration

  <b>APIs Supported:</b><br>
   void ADCx_CoreCalibration (enum ADC_CHANNEL channel);<br>
   void ADC_SharedCoreCalibration (void);<br>

   x denotes instance of ADC in ADCx, channel denotes dedicated Core. 
   Refer to device specific datasheet to check number of cores and ADC module instance.
   Refer driver header file for detailed description of the APIs.
  
*/
#define ADC_CALIBRATION_FEATURE_AVAILABLE  1

/** 
 @ingroup  adcdriver
 @brief    Defines the macro associated with ADC indvidual channel interrupts

  <b>APIs Supported:</b><br>
   void ADCx_IndividualChannelInterruptEnable (enum ADC_CHANNEL channel);<br>
   void ADCx_IndividualChannelInterruptDisable (enum ADC_CHANNEL channel);<br>
   void ADCx_IndividualChannelInterruptFlagClear (enum ADC_CHANNEL channel);<br>
   
   x denotes instance of ADC, channel denotes dedicated ADC channel. 
   Refer to device specific datasheet to check number of cores and ADC module instance.
   Refer driver header file for detailed description of the APIs.
  
*/
#define ADC_INDIVIDUAL_CHANNEL_INTERRUPT_FEATURE_AVAILABLE  1

/** 
 @ingroup  adcdriver
 @brief    Defines the macro associated with ADC comparator feature

  <b>APIs Supported:</b><br>
   void ADCx_ComparatorEnable(void);<br>
   void ADCx_ComparatorDisable(void);<br>
   void ADCx_ComparatorLowThresholdSet(uint16_t threshold );<br>
   void ADCx_ComparatorHighThresholdSet(uint16_t threshold );<br>
   uint16_t ADCx_ComparatorEventStatusGet(void);<br>
   uint16_t ADCx_ComparatorEventChannelGet(void);<br>

   x denotes instance of ADC in ADCx.
   Refer to device specific datasheet to check number of comparators and ADC module instance.
   Refer driver header file for detailed description of the APIs.
  
*/
#define ADC_COMPARATOR_FEATURE_AVAILABLE   1

/** 
 @ingroup  adcdriver
 @brief    Defines the macro associated with individual channel software trigger feature

  <b>APIs Supported:</b><br>
   void ADCx_ChannelSoftwareTriggerEnable(enum ADC_CHANNEL channel);<br>
   void ADCx_ChannelSoftwareTriggerDisable(enum ADC_CHANNEL channel);<br>

   x denotes instance of ADC in ADCx.
   Refer to device specific datasheet to check number of comparators and ADC module instance.
   Refer driver header file for detailed description of the APIs.
  
*/
#define ADC_INDIVIDUAL_SOFTWARE_TRIGGER_FEATURE_AVAILABLE   1

/** 
 @ingroup  adcdriver
 @brief    Defines the macro associated with secondary accumulator feature

  <b>APIs Supported:</b><br>
   void ADCx_SecondaryAccumulatorGet(enum ADC_CHANNEL channel);<br>

   x denotes instance of ADC in ADCx.
   Refer to device specific datasheet to check number of comparators and ADC module instance.
   Refer driver header file for detailed description of the APIs.
  
*/
#define ADC_SECONDARY_ACCUMULATOR_FEATURE_AVAILABLE   1

/*******************************************************************************
            Macros defined for features not supported in the device
*******************************************************************************/

/**<None*/

#endif //ADC_MODULE_FEATURES