/*******************************************************************************
  @Company
    Microchip Technology Inc.

  @File Name
    touch.c

  @Summary
    QTouch Modular Library

  @Description
    Provides Initialization, Processing and ISR handler of touch library,
    Simple API functions to get/set the key touch parameters from/to the
    touch library data structures.
	
*******************************************************************************/
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

/*******************************************************************************
 * NOTE: The touch library contains pre-release code intended solely for
 * demonstration purposes. It is not intended for production use.
 *******************************************************************************/

#ifndef TOUCH_C
#define TOUCH_C

#include<xc.h>
#include "../touch.h"
#include "../../timer/tmr1.h"
#include "../include/qtm_acq_dspic33a_0x0051_api.h"
#include "../include/qtm_touch_key_0x0002_api.h"
#include "../include/qtm_freq_hop_auto_0x0004_api.h"
#include "../include/qtm_scroller_0x000b_api.h"

#warning "The touch library contains pre-release code intended solely for demonstration purposes. It is not intended for production use."

/*----------------------------------------------------------------------------
 *   prototypes
 *----------------------------------------------------------------------------*/

/*! \brief Touch post process complete callback function prototype.
 */
static void qtm_post_process_complete();

/*! \brief configure keys, wheels and sliders.
 */
static touch_ret_t touch_sensors_config(void);

/*! \brief Device config.
 */
static touch_ret_t touch_device_config(void);

/*! \brief Touch Error callback function prototype.
 */
static void qtm_error_callback(uint8_t error);

/*! \brief Timer config.
 */
static void touch_timer_config(void);


/*----------------------------------------------------------------------------
 *     Global Variables
 *----------------------------------------------------------------------------*/
/* Measurement Done Touch Flag  */
volatile uint8_t measurement_done_touch = 0;

/* Error Handling */
volatile uint8_t module_error_code = 0;

/* track touch in progress flag */
volatile uint8_t touch_in_progress = 0u;

/* post-process request flag */
volatile uint8_t touch_postprocess_request = 0;

/* Flag to indicate time for touch measurement */
volatile uint8_t time_to_measure_touch_flag = 0;

/* Acquisition module internal data - Size to largest acquisition set */

uint32_t touch_acq_signals_raw[DEF_NUM_CHANNELS];

/*----------------------------------------------------------------------------
 *     Acquisition Module
 *----------------------------------------------------------------------------*/

/* Acquisition set 1 - General settings */
qtm_acq_node_group_config_t adc_qtlib_acq_gen1 = 
    {DEF_NUM_CHANNELS, DEF_SENSOR_TYPE, DEF_SEL_FREQ_INIT};

/* Node status, signal, calibration values */
qtm_acq_node_data_t adc_qtlib_node_stat1[DEF_NUM_CHANNELS];

/* Node configurations */
qtm_acq_dspic33a_node_config_t adc_seq_node_cfg1[DEF_NUM_CHANNELS] = { NODE_0_PARAMS, NODE_1_PARAMS, NODE_2_PARAMS};

qtm_acq_dspic33a_device_config_t device_config = {
    .adc_clk_src = FRC,
    .device_id = DSPIC33_AK512MPS
};


/* Container */
qtm_acquisition_control_t qtlib_acq_set1 = 
{
    .qtm_acq_node_group_config = &adc_qtlib_acq_gen1,
    .qtm_acq_node_config = &adc_seq_node_cfg1[0],
    .qtm_acq_node_data = &adc_qtlib_node_stat1[0],
    .qtm_acq_device_config =&device_config,
};

/**********************************************************/
/*********** Frequency Hop Auto tune Module **********************/
/**********************************************************/

/* Buffer used with various noise filtering functions */
uint16_t noise_filter_buffer[DEF_NUM_SENSORS * NUM_FREQ_STEPS];
uint8_t freq_hop_delay_selection[NUM_FREQ_STEPS] = {DEF_MEDIAN_FILTER_FREQUENCIES};
uint8_t freq_hop_autotune_counters[NUM_FREQ_STEPS];

/* Configuration */
qtm_freq_hop_autotune_config_t qtm_freq_hop_autotune_config1 = 
    {
        DEF_NUM_CHANNELS,
        NUM_FREQ_STEPS,
        (uint8_t*)&(adc_qtlib_acq_gen1.freq_option_select),
        &freq_hop_delay_selection[0],
        DEF_FREQ_AUTOTUNE_ENABLE,
        FREQ_AUTOTUNE_MAX_VARIANCE,
        FREQ_AUTOTUNE_COUNT_IN
    };

/* Data */
qtm_freq_hop_autotune_data_t qtm_freq_hop_autotune_data1 = 
{
    0, 
    0, 
    &noise_filter_buffer[0], 
    &adc_qtlib_node_stat1[0], 
    &freq_hop_autotune_counters[0]
};

/* Container */
qtm_freq_hop_autotune_control_t qtm_freq_hop_autotune_control1 = 
{
    &qtm_freq_hop_autotune_data1, 
    &qtm_freq_hop_autotune_config1
};

/**********************************************************/
/*********************** Keys Module **********************/
/**********************************************************/

/* Keys set 1 - General settings */
qtm_touch_key_group_config_t qtlib_key_grp_config_set1 = 
{
    DEF_NUM_SENSORS,
    DEF_TOUCH_DET_INT,
    DEF_MAX_ON_DURATION,
    DEF_ANTI_TCH_DET_INT,
    DEF_ANTI_TCH_RECAL_THRSHLD,
    DEF_TCH_DRIFT_RATE,
    DEF_ANTI_TCH_DRIFT_RATE,
    DEF_DRIFT_HOLD_TIME,
    DEF_REBURST_MODE
};

qtm_touch_key_group_data_t qtlib_key_grp_data_set1;

/* Key data */
qtm_touch_key_data_t qtlib_key_data_set1[DEF_NUM_SENSORS];

/* Key Configurations */                                                       
qtm_touch_key_config_t qtlib_key_configs_set1[DEF_NUM_SENSORS] = { KEY_0_PARAMS, KEY_1_PARAMS, KEY_2_PARAMS };

/* Container */
qtm_touch_key_control_t qtlib_key_set1
    = {&qtlib_key_grp_data_set1, &qtlib_key_grp_config_set1, &qtlib_key_data_set1[0], &qtlib_key_configs_set1[0]};

/**********************************************************/
/***************** Scroller Module ********************/
/**********************************************************/

/* Individual and Group Data */
qtm_scroller_data_t       qtm_scroller_data1[DEF_NUM_SCROLLERS];
qtm_scroller_group_data_t qtm_scroller_group_data1 = {0};

/* Group Configuration */
qtm_scroller_group_config_t qtm_scroller_group_config1 = {&qtlib_key_data_set1[0], DEF_NUM_SCROLLERS};

/* Scroller Configurations */
qtm_scroller_config_t qtm_scroller_config1[DEF_NUM_SCROLLERS] = {SCROLLER_0_PARAMS};  

/* Container */
qtm_scroller_control_t qtm_scroller_control1
    = {&qtm_scroller_group_data1, &qtm_scroller_group_config1, &qtm_scroller_data1[0], &qtm_scroller_config1[0]};

/*----------------------------------------------------------------------------
 *   function definitions
 *----------------------------------------------------------------------------*/

/*============================================================================
static touch_ret_t touch_sensors_config(void)
------------------------------------------------------------------------------
Purpose: Initialization of touch key sensors
Input  : none
Output : none
Notes  :
============================================================================*/
/* Touch sensors config - assign nodes to buttons / wheels / sliders / surfaces / water level / etc */
static touch_ret_t touch_sensors_config(void)
{
    touch_ret_t touch_ret = TOUCH_SUCCESS;
    
    uint16_t    sensor_nodes;
    
    touch_ret = qtm_itc_init_acquisition_module(&qtlib_acq_set1);
    
    if (TOUCH_SUCCESS != touch_ret)
    {
        /* Acq module Error Detected: Issue an Acq module common error code 0x80 */
        qtm_error_callback(0x80);
    }
    else
    {
        /* Init pointers to DMA sequence memory */
        touch_ret = qtm_itc_qtlib_assign_signal_memory(&touch_acq_signals_raw[0u]);
        
        /* Initialize sensor nodes */
    	for (sensor_nodes = 0u; sensor_nodes < DEF_NUM_CHANNELS; sensor_nodes++) {
            /* Enable each node for measurement and mark for calibration */
            touch_ret |= qtm_enable_sensor_node(&qtlib_acq_set1, sensor_nodes);
            touch_ret |= qtm_calibrate_sensor_node(&qtlib_acq_set1, sensor_nodes);
            //touch_ret |= qtm_set_sensor_node_cal(&qtlib_acq_set1, sensor_nodes, set_cvd_cap[sensor_nodes]);

    	}	
	    /* Enable sensor keys and assign nodes */
	    for (sensor_nodes = 0u; sensor_nodes < DEF_NUM_CHANNELS; sensor_nodes++) {

            touch_ret |= qtm_init_sensor_key(&qtlib_key_set1, sensor_nodes, &adc_qtlib_node_stat1[sensor_nodes]);

	    }
        #if(SCROLLER_ENABLE == 1u)
        /* scroller init */
		touch_ret |= qtm_init_scroller_module(&qtm_scroller_control1);
        #endif
    }
    
    return (touch_ret);
}

/*============================================================================
static void qtm_measure_complete_callback( void )
------------------------------------------------------------------------------
Purpose: Callback function called after the completion of
         measurement cycle. This function sets the post processing request
         flag to trigger the post processing.
Input  : none
Output : none
Notes  :
============================================================================*/
static void qtm_measure_complete_callback(void)
{
    touch_postprocess_request = 1u;
}

/*============================================================================
static void qtm_post_process_complete(void)
------------------------------------------------------------------------------
Purpose: Callback function from binding layer called after the completion of
         post processing. This function sets the reburst flag based on the
         key sensor group status, calls the datastreamer output function to
         display the module data.
Input  : none
Output : none
Notes  :
============================================================================*/
static void qtm_post_process_complete(void)
{
    #if DEF_TOUCH_DATA_STREAMER_ENABLE == 1
        datastreamer_output();
    #endif

}

/*============================================================================
static void qtm_error_callback(uint8_t error)
------------------------------------------------------------------------------
Purpose: Callback function called after the completion of
         post processing. This function is called only when there is error.
Input  : error code
Output : decoded module error code
Notes  :
Error Handling supported by Binding layer module:
    Acquisition Module Error codes: 0x8<error code>
    0x81 - Qtm init
    0x82 - start acq
    0x83 - cal sensors
    0x84 - cal hardware

    Post processing Modules error codes: 0x4<process_id>
    0x40, 0x41, 0x42, ...
    process_id is the sequence of process IDs listed in #define LIB_MODULES_PROC_LIST macro.
    Process IDs start from zero and maximum is 15

    Examples:
    0x40 -> error in post processing module 1
    0x42 -> error in post processing module 3

Derived Module_error_codes:
    Acquisition module error =1
    post processing module1 error = 2
    post processing module2 error = 3
    ... and so on

============================================================================*/
static void qtm_error_callback(uint8_t error)
{
    module_error_code = 0;
    if (error & 0x80)
    {
        module_error_code = 1;
    }
    else if (error & 0x40)
    {
        module_error_code = (error & 0x0F) + 2;
    }

	#if DEF_TOUCH_DATA_STREAMER_ENABLE == 1
	    datastreamer_output();
	#endif
}

/*============================================================================
static void touch_device_config(void)
------------------------------------------------------------------------------
Purpose: To set Device configurations
Input  : none
Output : none
Notes  :
 ============================================================================*/
static touch_ret_t touch_device_config(void)
{
    touch_ret_t touch_ret = TOUCH_SUCCESS;
    
    uint32_t adc_clk_src_frequency = 0uL;
    uint32_t fvco_frequency = 0uL;
    uint16_t pll_pre = 0uL;
    uint16_t pll_fbd = 0uL;
    uint16_t pll_div1 = 0uL;
    uint16_t pll_div2 = 0uL;
    uint16_t int_div = 0uL;
    
    uint16_t local_nosc = CLK6CONbits.NOSC;
    adc_clock_src_t adc_clock_src = device_config.adc_clk_src;
    

    /* calculate frequency */
    if(adc_clock_src == FRC)
    {    
        if(local_nosc == 5u)
        {
            pll_pre = PLL1DIVbits.PLLPRE;
            pll_fbd = PLL1DIVbits.PLLFBDIV;
            pll_div1 = PLL1DIVbits.POSTDIV1;
            pll_div2 = PLL1DIVbits.POSTDIV2;
        }
        else if(local_nosc == 6u)
        {
            pll_pre = PLL2DIVbits.PLLPRE;
            pll_fbd = PLL2DIVbits.PLLFBDIV;
            pll_div1 = PLL2DIVbits.POSTDIV1;
            pll_div2 = PLL2DIVbits.POSTDIV2;
        }
        else if(local_nosc == 7u)
        {
            pll_pre = PLL1DIVbits.PLLPRE;
            pll_fbd = PLL1DIVbits.PLLFBDIV;
            int_div = VCO1DIVbits.INTDIV;
        }
        else if(local_nosc == 8u)
        {
            pll_pre = PLL2DIVbits.PLLPRE;
            pll_fbd = PLL2DIVbits.PLLFBDIV;
            int_div = VCO2DIVbits.INTDIV;
        }
        
        if (pll_pre == 0u)
        {
            pll_pre = 1u; /* avoid divide by 0 */
        }
        if (pll_fbd == 0u)
        {
            pll_fbd = 1u; /* avoid divide by 0 */
        }
        if (pll_div1 == 0u)
        {
            pll_div1 = 1u; /* avoid divide by 0 */
        }
        if (pll_div2 == 0u)
        {
            pll_div2 = 1u; /* avoid divide by 0 */
        }
        if (int_div == 0u)
        {
            int_div = 1u; /* avoid divide by 0 */
        }
        
        if(local_nosc == 5u)
        {
            #if defined (FRC_CLK_FREQ)
            fvco_frequency = ((FRC_CLK_FREQ * (pll_fbd & 0x00ffu)) / pll_pre)/(pll_div1 * pll_div2);
            #endif
        }
        else if(local_nosc == 6u)
        {
            #if defined (FRC_CLK_FREQ)
            fvco_frequency = ((FRC_CLK_FREQ * (pll_fbd & 0x00ffu)) / pll_pre)/(pll_div1 * pll_div2);
            #endif
        }
        else if(local_nosc == 7u)
        {
            #if defined (FRC_CLK_FREQ)
            fvco_frequency = ((FRC_CLK_FREQ * (pll_fbd & 0x00ffu)) / pll_pre)/(int_div * 2u);
            #endif
        }
        else if(local_nosc == 8u)
        {
            #if defined (FRC_CLK_FREQ)
            fvco_frequency = ((FRC_CLK_FREQ * (pll_fbd & 0x00ffu)) / pll_pre)/(int_div * 2u);
            #endif
        }
            
    
        adc_clk_src_frequency = fvco_frequency;
    }
    else
    {
            /* invalid */
    }

    device_config.adc_clk_src_freq = adc_clk_src_frequency;
    
    if(adc_clk_src_frequency > MAX_INPUT_ADC_CLK_FREQ)
    {
        touch_ret = TOUCH_INVALID_INPUT_PARAM;
    }
    else 
    {
            /* invalid */
    }
    
    return touch_ret;
}


uint16_t interrupt_cnt = 0u;
/*============================================================================
void touch_timer_handler(void)
------------------------------------------------------------------------------
Purpose: This function updates the time elapsed to the touch key module to
         synchronize the internal time counts used by the module.
Input  : none
Output : none
Notes  :
============================================================================*/
void touch_timer_handler(void)
{
    interrupt_cnt++;
	if (interrupt_cnt >= DEF_TOUCH_MEASUREMENT_PERIOD_MS)
    {                      
        interrupt_cnt = 0;
		/* Count complete - Measure touch sensors */
        time_to_measure_touch_flag = 1u;
        qtm_update_qtlib_timer(DEF_TOUCH_MEASUREMENT_PERIOD_MS);
    }
}

/*============================================================================
void touch_timer_config(void)
------------------------------------------------------------------------------
Purpose: register Timer callback
Input  : none
Output : none
Notes  :
============================================================================*/
static void touch_timer_config(void)
{  
}

/*============================================================================
void touch_check_node_cc_cal(void)
------------------------------------------------------------------------------
Purpose: This function is used to stop calibration on the nodes that exceeds the maximum calibration counter 
Input  : none
Output : none
Notes  :
============================================================================*/
uint8_t cal_count[DEF_NUM_CHANNELS] = {0u};
void touch_check_node_cc_cal(void)
{

    uint16_t node_num = 0u;
    

	for (node_num = 0u; node_num < DEF_NUM_CHANNELS; node_num++)
	{
		if( (adc_qtlib_node_stat1[node_num].node_acq_status &  (NODE_CC_CAL << NODE_STATUS_POS)) != 0u)
		{
			if( cal_count[node_num] > DEF_MAX_CC_CAL_COUNT )
			{
				/* stop calibration - set the last computed CC value */
				qtm_set_sensor_node_cal(&qtlib_acq_set1, node_num, adc_qtlib_node_stat1[node_num].node_comp_caps);
				/* reset counter */
				cal_count[node_num] = 0u;
			
			}
			else
			{	/* increment counter */
				cal_count[node_num]++;
			}
		}
	}
}

/*============================================================================
void touch_init(void)
------------------------------------------------------------------------------
Purpose: Initialization of touch library. PTC, timer, and
         datastreamer modules are initialized in this function.
Input  : none
Output : none
Notes  :
============================================================================*/
void touch_init(void)
{
    touch_ret_t touch_ret = TOUCH_SUCCESS;
    
    touch_ret = touch_device_config();
    
    if(TOUCH_SUCCESS != touch_ret)
    {
        /* Acq module Error Detected */
        qtm_error_callback(0x81);
    }
    
    touch_timer_config();
    
    touch_ret = touch_sensors_config();
    if (TOUCH_SUCCESS != touch_ret)
    {
        /* Acq module Error Detected: Issue an Acq module common error code 0x80 */
        qtm_error_callback(0x81);
    }
    
    /* Set Freq Hop Time scale */
	touch_ret = qtm_update_acq_freq_delay(DEF_FREQ_HOP_TIME_SCALE);
    if (TOUCH_SUCCESS != touch_ret)
    {
            /* Acq module Error Detected: Issue an Acq module common error code 0x80 */
            qtm_error_callback(0x81);
    }    
}

void touch_process(void)
{   
    touch_ret_t touch_ret = TOUCH_SUCCESS;
    
    /* check the time_to_measure_touch for Touch Acquisition */
    if ((time_to_measure_touch_flag == 1u) && (touch_in_progress == 0u) && (touch_postprocess_request==0u))
    {
        
        touch_ret = qtm_itc_start_measurement_seq(&qtlib_acq_set1, qtm_measure_complete_callback);
        
        if (TOUCH_SUCCESS == touch_ret) {
            /* Clear the Measure request flag */
			time_to_measure_touch_flag = 0u;
            /* set in progress flag */
            touch_in_progress = 1u;
        }
        else
        {
            /* Acq module Error Detected: Issue an Acq module common error code 0x80 */
            qtm_error_callback(0x81);
        }
    }
    
    /* check the flag for node level post processing */
    if (touch_postprocess_request == 1u)
    {
        /* clear in progress flag */
        touch_in_progress = 0u;
        /* Reset the flags for node_level_post_processing */
        touch_postprocess_request = 0u;
        /* Run Acquisition module level post processing*/
        touch_ret = qtm_acquisition_process();
        
        touch_check_node_cc_cal();
        
        if(TOUCH_SUCCESS == touch_ret)
        {            
            /* Returned with success: Start module level post processing */
            touch_ret = qtm_freq_hop_autotune(&qtm_freq_hop_autotune_control1);
            if (TOUCH_SUCCESS != touch_ret) {
                qtm_error_callback(0x41);
            }
            
            touch_ret = qtm_key_sensors_process(&qtlib_key_set1);
            if (TOUCH_SUCCESS != touch_ret)
            {
                qtm_error_callback(0x42);
            }
            #if(SCROLLER_ENABLE == 1u)
            touch_ret = qtm_scroller_process(&qtm_scroller_control1);
            if (TOUCH_SUCCESS != touch_ret)
            {
                qtm_error_callback(0x43);
            }
            #endif
        }
        else
        {
            /* Acq module Error Detected: Issue an Acq module common error code 0x80 */
            qtm_error_callback(0x80);
        }


        if (0u != (qtlib_key_set1.qtm_touch_key_group_data->qtm_keys_status & QTM_KEY_REBURST))
        {
            time_to_measure_touch_flag = 1u;
        }
        else
        {
            measurement_done_touch = 1u;
        }
        qtm_post_process_complete();
    }
    
}

/*============================================================================
 * Helper functions
============================================================================*/
uint16_t get_sensor_node_signal(uint16_t sensor_node)
{
    return (adc_qtlib_node_stat1[sensor_node].node_acq_signals);
}

void update_sensor_node_signal(uint16_t sensor_node, uint16_t new_signal)
{
    adc_qtlib_node_stat1[sensor_node].node_acq_signals = new_signal;
}

uint16_t get_sensor_node_reference(uint16_t sensor_node)
{
    return (qtlib_key_data_set1[sensor_node].channel_reference);
}

void update_sensor_node_reference(uint16_t sensor_node, uint16_t new_reference)
{
    qtlib_key_data_set1[sensor_node].channel_reference = new_reference;
}

uint16_t get_sensor_cc_val(uint16_t sensor_node)
{
    return (adc_qtlib_node_stat1[sensor_node].node_comp_caps);
}

void update_sensor_cc_val(uint16_t sensor_node, uint16_t new_cc_value)
{
    adc_qtlib_node_stat1[sensor_node].node_comp_caps = new_cc_value;
}

uint8_t get_sensor_state(uint16_t sensor_node)
{
    return (qtlib_key_data_set1[sensor_node].sensor_state);
}
uint8_t get_sensor_threshold(uint16_t sensor_node)
{
    return (qtlib_key_configs_set1[sensor_node].channel_threshold);
}
void update_sensor_state(uint16_t sensor_node, uint8_t new_state)
{
    qtlib_key_set1.qtm_touch_key_data[sensor_node].sensor_state = new_state;
}

void calibrate_node(uint16_t sensor_node)
{
    /* Calibrate Node */
    qtm_calibrate_sensor_node(&qtlib_acq_set1, sensor_node);
    /* Initialize key */
    qtm_init_sensor_key(&qtlib_key_set1, sensor_node, &adc_qtlib_node_stat1[sensor_node]);
}

uint8_t get_current_frequency(void)
{
    return *qtm_freq_hop_autotune_config1.freq_option_select;
}

uint8_t get_filter_frequency(uint8_t idx)
{
    return qtm_freq_hop_autotune_config1.median_filter_freq[idx];
}

uint8_t get_scroller_state(uint16_t sensor_node)
{
	return (qtm_scroller_control1.qtm_scroller_data[sensor_node].scroller_status);
}

uint16_t get_scroller_position(uint16_t sensor_node)
{
	return (qtm_scroller_control1.qtm_scroller_data[sensor_node].position);
}

uint16_t get_scroller_contact_size(uint16_t sensor_node)
{
    return (qtm_scroller_control1.qtm_scroller_data[sensor_node].contact_size);
}

uint16_t get_scroller_contact_threshold(uint16_t sensor_node)
{
    return (qtm_scroller_control1.qtm_scroller_config[sensor_node].contact_min_threshold);
}

/*============================================================================
ISR(ITC)
------------------------------------------------------------------------------
Purpose  :  Interrupt handler for PITC Interrupt
Input    :  none
Output   :  none
Notes    :  This interrupt is called when all CVD conversions for one channel are completed. 
============================================================================*/
void __attribute__((interrupt)) _ITCInterrupt()
{

    qtm_dspic33a_touch_handler_eoc();    

}

#endif /* TOUCH_C */