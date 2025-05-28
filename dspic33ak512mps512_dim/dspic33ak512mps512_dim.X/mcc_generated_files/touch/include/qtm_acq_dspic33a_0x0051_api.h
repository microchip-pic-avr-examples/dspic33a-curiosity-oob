/*******************************************************************************
  Touch Library

  Company:
    Microchip Technology Inc.

  File Name:
    qtm_acq_dspic33a_0x0051_api.h

  Summary:
    Touch Modular Library

  Description:
    API for acquisition module of dsPIC33A device family - DSPIC33A 0x0051
	
*******************************************************************************/

/*******************************************************************************
Copyright (c) Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/

/*******************************************************************************
 * NOTE: The touch library contains pre-release code intended solely for
 * demonstration purposes. It is not intended for production use.
 *******************************************************************************/

#ifndef QTM_ACQ_DSPIC33A_API_H
#define	QTM_ACQ_DSPIC33A_API_H

#include "qtm_common_components_api.h"

/* X line bit position */
#define X_NONE 0u
#define X(n) ((uint32_t)(1uL << (n)))

/* Y line bit position */
#define Y(n) ((uint32_t)(1uL << (n)))

/* Combine Analog / Digital Gain */
#define NODE_GAIN(d) (uint8_t)(d)

/* Touch library Oversampling setting */
typedef enum tag_filter_level_t 
{
  FILTER_LEVEL_1,
  FILTER_LEVEL_2,
  FILTER_LEVEL_4,
  FILTER_LEVEL_8,
  FILTER_LEVEL_16,
  FILTER_LEVEL_32,
  FILTER_LEVEL_64
} filter_level_t;

/* Touch library GAIN setting */
typedef enum tag_gain_t 
{
  GAIN_1,
  GAIN_2,
  GAIN_4,
  GAIN_8,
  GAIN_16
} gain_t;

/**
 * acquisition frequency delay setting.
 * inserts "n" ADC core clock cycles between consecutive measurements
 * e.g.  FREQ_HOP_SEL_14 setting inserts 14 ADC core clock cycles.
 */
typedef enum tag_freq_config_sel_t 
{
  FREQ_SEL_0,
  FREQ_SEL_1,
  FREQ_SEL_2,
  FREQ_SEL_3,
  FREQ_SEL_4,
  FREQ_SEL_5,
  FREQ_SEL_6,
  FREQ_SEL_7,
  FREQ_SEL_8,
  FREQ_SEL_9,
  FREQ_SEL_10,
  FREQ_SEL_11,
  FREQ_SEL_12,
  FREQ_SEL_13,
  FREQ_SEL_14,
  FREQ_SEL_15
} freq_config_sel_t;


typedef enum tagADCCLKSRC 
{
    POSC = 0u,
    BFRC = 1u,
    FRC = 2u,
    REF1 = 3u,
    REF2 = 4u,
} adc_clock_src_t;

typedef enum tagDeviceID {
    DSPIC33_AK512MPS = 0u,
    DSPIC33_AK512MC = 1u
} dspic33a_device_id;

/*----------------------------------------------------------------------------
 * Structure Declarations
 *----------------------------------------------------------------------------*/

/* device information configuration */
typedef struct {
    adc_clock_src_t         adc_clk_src;            /* Selects the ADC clock source */
    uint32_t                adc_clk_src_freq;       /* selected clock source frequency(Hz) for touch, min-16MHz and max 500MHz */
    dspic33a_device_id      device_id;              /* Device Identifier */
} qtm_acq_dspic33a_device_config_t;

/* Node configuration */
typedef struct
{
 uint32_t node_xmask;           /* Selects the X channels for this node */
 uint32_t node_ymask;           /* Selects the Y channels for this node */
 uint8_t node_csd;              /* Charge Share Delay Range: 8 to 1023*/
 uint8_t node_gain;             /* Bits 7:4 = reserved, Bits 3:0 = Digital gain */
 uint8_t node_oversampling;     /* Accumulator setting - Number of oversamples per measurement */
}qtm_acq_dspic33a_node_config_t;

/* Node run-time data - Defined in common api as it will be used with all acquisition modules */

/* Node group configuration */
typedef struct
{
  uint16_t num_sensor_nodes;            /* Number of sensor nodes */
  uint8_t acq_sensor_type;              /* Self or mutual sensors */
  uint8_t freq_option_select;           /* Hop Frequency selected */
} qtm_acq_node_group_config_t;

/* Container structure for sensor group */
typedef struct
{
    qtm_acq_node_group_config_t    *qtm_acq_node_group_config;
    qtm_acq_dspic33a_node_config_t  *qtm_acq_node_config;
    qtm_acq_node_data_t            *qtm_acq_node_data;
    qtm_acq_dspic33a_device_config_t *qtm_acq_device_config;
} qtm_acquisition_control_t;

/*----------------------------------------------------------------------------
* prototypes
*----------------------------------------------------------------------------*/

/* Library prototypes */

/*============================================================================
touch_ret_t qtm_itc_init_acquisition_module(qtm_acquisition_control_t* qtm_acq_control_ptr);
------------------------------------------------------------------------------
Purpose: Initialize the ADC and Assign pins
Input  : pointer to acquisition set,
Output : touch_ret_t: 
Notes  : qtm_itc_init_acquisition module must be called ONLY once with a pointer to each config set
============================================================================*/
touch_ret_t qtm_itc_init_acquisition_module(qtm_acquisition_control_t* qtm_acq_control_ptr);

/*============================================================================
touch_ret_t qtm_itc_qtlib_assign_signal_memory(uint32_t* qtm_signal_raw_data_ptr)
------------------------------------------------------------------------------
Purpose: Assign raw signals pointer to array defined in application code
Input  : pointer to raw data array
Output : touch_ret_t: 
Notes  : none
============================================================================*/
touch_ret_t qtm_itc_qtlib_assign_signal_memory(uint32_t* qtm_signal_raw_data_ptr );

/*============================================================================
touch_ret_t qtm_enable_sensor_node(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number)
------------------------------------------------------------------------------
Purpose: Enables a sensor node for measurement
Input  : Node configurations pointer, node number
Output : touch_ret_t:
Notes  :
============================================================================*/
touch_ret_t qtm_enable_sensor_node(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number);

/*============================================================================
touch_ret_t qtm_disable_sensor_node(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number)
------------------------------------------------------------------------------
Purpose: Disables a sensor node for measurement
Input  : Node configurations pointer, node number
Output : touch_ret_t:
Notes  :
============================================================================*/
touch_ret_t qtm_disable_sensor_node(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number);

/*============================================================================
touch_ret_t qtm_calibrate_sensor_node(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number)
------------------------------------------------------------------------------
Purpose:  Marks a sensor node for calibration
Input  :  Node configurations pointer, node number
Output : touch_ret_t:
Notes  :
============================================================================*/
touch_ret_t qtm_calibrate_sensor_node(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number);

/*============================================================================
touch_ret_t qtm_set_sensor_node_cal(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number, uint8_t qtm_sensor_node_cal_val)
------------------------------------------------------------------------------
Purpose	: Sets the calibration value of a sensor node and stops CC calibration of that node.
Input	: Node configurations pointer, node (channel) number
Output	: touch_ret_t
Notes	:
============================================================================*/
touch_ret_t qtm_set_sensor_node_cal(qtm_acquisition_control_t* qtm_acq_control_ptr, uint16_t qtm_which_node_number, uint8_t qtm_sensor_node_cal_val);

/*============================================================================
void qtm_itc_de_init(void)
------------------------------------------------------------------------------
Purpose: To Deinitialise Touch
Input  : none
Output : none
Notes  : none
============================================================================*/
void qtm_itc_de_init(void);

/*============================================================================
touch_ret_t qtm_itc_start_measurement_seq(qtm_acquisition_control_t* qtm_acq_control_pointer, void (*measure_complete_callback) (void));
------------------------------------------------------------------------------
Purpose:  Loads touch configurations for first channel and start,  
Input  :  Node configurations pointer, measure complete callback pointer
Output : touch_ret_t:
Notes  :
============================================================================*/
touch_ret_t qtm_itc_start_measurement_seq(qtm_acquisition_control_t* qtm_acq_control_pointer, void (*measure_complete_callback) (void));

/*============================================================================
touch_ret_t qtm_acquisition_process(void)
------------------------------------------------------------------------------
Purpose: Signal capture and processing
Input  : (Measured signals, config)
Output : touch_ret_t
Notes  : none
============================================================================*/
touch_ret_t qtm_acquisition_process(void);

/*============================================================================
touch_ret_t qtm_update_acq_freq_delay(uint8_t scale_factor)
------------------------------------------------------------------------------
Purpose: Sets the delay used as part of freqency hop
Input  : multiplication factor for frequency hop delay
Output : touch_ret_t
Notes  : none
============================================================================*/
touch_ret_t qtm_update_acq_freq_delay(uint8_t scale_factor);

/*============================================================================
touch_ret_t qtm_itc_config_update(uint8_t acq_sensor_type )
------------------------------------------------------------------------------
Purpose: To update the ITC Sequence
Input  : acquisition sensor type
Output : touch_ret_t
Notes  :
============================================================================*/
touch_ret_t qtm_itc_config_update( uint8_t acq_sensor_type  );
 
/*============================================================================
void qtm_dspic33a_touch_handler_eoc(void)
------------------------------------------------------------------------------
Purpose: Captures  the  measurement,  starts  the  next  or  End  Of  Sequence  handler
Input  : none
Output : touch_ret_t
Notes  : none
============================================================================*/
void qtm_dspic33a_touch_handler_eoc(void);
 
/*============================================================================
void qtm_disable_touch(void)
------------------------------------------------------------------------------
Purpose: Turn off touch module
Input  : none
Output : none
Notes  :
============================================================================*/
void qtm_disable_touch(void);

/*============================================================================
void qtm_enable_touch(void)
------------------------------------------------------------------------------
Purpose: Turn ON touch module
Input  : none
Output : none
Notes  :
============================================================================*/
void qtm_enable_touch(void);

 /*============================================================================
uint16_t qtm_get_current_measure_channel(void)
------------------------------------------------------------------------------
Purpose: get the last measured channel
Input  : none
Output : none
Notes  : none
============================================================================*/
uint16_t  qtm_get_current_measure_channel(void);

/*============================================================================
uint16_t qtm_dspic33a_acq_module_get_id(void)
------------------------------------------------------------------------------
Purpose: Returns the module ID
Input  : none
Output : Module ID
Notes  : none
============================================================================*/
uint16_t qtm_dspic33a_acq_module_get_id(void);

/*============================================================================
uint8_t qtm_dspic33a_acq_module_get_ver(void)
------------------------------------------------------------------------------
Purpose: Returns the module Firmware version
Input  : none
Output : Module ID - Upper nibble major / Lower nibble minor
Notes  : none
============================================================================*/
uint8_t qtm_dspic33a_acq_module_get_ver(void);

/*----------------------------------------------------------------------------
 *     device identifier definitions
 *----------------------------------------------------------------------------*/

#if         defined (__dsPIC33AK256MPS505__) || defined (__dsPIC33AK256MPS506__) || defined (__dsPIC33AK256MPS508__) || defined (__dsPIC33AK256MPS510__) || defined (__dsPIC33AK256MPS512__) || \
            defined (__dsPIC33AK512MPS505__) || defined (__dsPIC33AK512MPS506__) || defined (__dsPIC33AK512MPS508__) || defined (__dsPIC33AK512MPS510__) || defined (__dsPIC33AK512MPS512__) || \
            defined (__dsPIC33AK256MPS205__) || defined (__dsPIC33AK256MPS206__) || defined (__dsPIC33AK256MPS208__) || defined (__dsPIC33AK256MPS210__) || defined (__dsPIC33AK256MPS212__) || \
            defined (__dsPIC33AK512MPS205__) || defined (__dsPIC33AK512MPS206__) || defined (__dsPIC33AK512MPS208__) || defined (__dsPIC33AK512MPS210__) || defined (__dsPIC33AK512MPS212__)
            
#define     DSPIC33_DEVICE_IDENTIFIER   DSPIC33_AK512MPS

#elif       defined (__dsPIC33AK256MC505__) || defined (__dsPIC33AK256MC506__) || defined (__dsPIC33AK256MC508__) || defined (__dsPIC33AK256MC510__) || defined (__dsPIC33AK256MC512__) || \
            defined (__dsPIC33AK512MC505__) || defined (__dsPIC33AK512MC506__) || defined (__dsPIC33AK512MC508__) || defined (__dsPIC33AK512MC510__) || defined (__dsPIC33AK512MC512__) || \
            defined (__dsPIC33AK256MC205__) || defined (__dsPIC33AK256MC206__) || defined (__dsPIC33AK256MC208__) || defined (__dsPIC33AK256MC210__) || defined (__dsPIC33AK256MC212__) || \
            defined (__dsPIC33AK512MC205__) || defined (__dsPIC33AK512MC206__) || defined (__dsPIC33AK512MC208__) || defined (__dsPIC33AK512MC210__) || defined (__dsPIC33AK512MC212__)

#define     DSPIC33_DEVICE_IDENTIFIER   DSPIC33_AK512MC

#endif

#endif /* QTM_ACQ_DSPIC33A_API_H */









