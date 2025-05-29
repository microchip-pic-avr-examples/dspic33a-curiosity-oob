/**
 * ADC Generated Driver Types Header File
 * 
 * @file      adc_types.h
 *            
 * @ingroup   adcdriver
 *            
 * @brief     This is the generated driver types header file for the ADC driver           
 *
 * @skipline @version   PLIB Version 1.1.0
 *            
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*disclaimer*/

#ifndef ADC_TYPES_H
#define ADC_TYPES_H

// Section: Included Files

// Section: Data Type Definitions

/**
 @ingroup  adcdriver
 @enum     ADC_DEDICATED_CORE
 @brief    Defines the ADC cores that are 
           available for the module to use.
 @note     The enum list in the Help document might be just a reference to to show 
           the dedicated core list. Generated enum list is based on the configuration 
           done by user in the MCC Melody user interface.
*/
enum ADC_DEDICATED_CORE
{
    ADC_MAX_DEDICATED_CORES = 0    /**< No dedicated cores available */
};

/**
 @ingroup  adcdriver
 @enum     ADC_RESOLUTION_TYPE
 @brief    Defines the supported ADC resolution types.
*/
enum ADC_RESOLUTION_TYPE
{
    ADC_12_BIT_RESOLUTION,     /**< ADC Resolution of 12 bit*/
};

/**
 @ingroup  adcdriver
 @enum     ADC_PWM_INSTANCE
 @brief    Defines the ADC PWM trigger sources that are 
           available for the module to use.
 @note     Refer \ref PWM_GENERATOR enum for mapping between custom name and instance 
*/
enum ADC_PWM_INSTANCE
{
    ADC_PWM_GENERATOR_8,    /**< PWM name:PWM_GENERATOR_8 */
    ADC_PWM_GENERATOR_7,    /**< PWM name:PWM_GENERATOR_7 */
    ADC_PWM_GENERATOR_6,    /**< PWM name:PWM_GENERATOR_6 */
    ADC_PWM_GENERATOR_5,    /**< PWM name:PWM_GENERATOR_5 */
    ADC_PWM_GENERATOR_4,    /**< PWM name:PWM_GENERATOR_4 */
    ADC_PWM_GENERATOR_3,    /**< PWM name:PWM_GENERATOR_3 */
    ADC_PWM_GENERATOR_2,    /**< PWM name:PWM_GENERATOR_2 */
    ADC_PWM_GENERATOR_1,    /**< PWM name:PWM_GENERATOR_1 */
};

/**
 @ingroup  adcdriver
 @enum     ADC_PWM_TRIGGERS
 @brief    Defines the PWM triggers that are available in each individual PWM.
*/
enum ADC_PWM_TRIGGERS
{
    ADC_PWM_TRIGGER_1 = 1,     /**< PWM TRIGGER 1 */
    ADC_PWM_TRIGGER_2 = 2,     /**< PWM TRIGGER 2 */
};

#endif  //ADC_TYPES_H
