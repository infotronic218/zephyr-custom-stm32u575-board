#include"analog_temp_test.h"
#include<zephyr/kernel.h>
#include<zephyr/drivers/adc.h>
#include<zephyr/logging/log.h>
#include<zephyr/device.h>

#define ADC_GAIN (3300.0/4095.0)
#define V_T0 400 // 400mV for 0 degree
#define VOLTAGE_MV_TO_TEMP(v) (((ADC_GAIN*(v))-V_T0)/19.5)

LOG_MODULE_REGISTER(analog_sensor, LOG_LEVEL_DBG);

#define ADC_NODE DT_PHANDLE(DT_PATH(zephyr_user), io_channels)

#define ADC_CHANNEL_0 DT_IO_CHANNELS_INPUT_BY_IDX(DT_PATH(zephyr_user), 0)

const struct device * temp_adc_dev = DEVICE_DT_GET(ADC_NODE);
const struct adc_dt_spec temp_adc_ch = ADC_DT_SPEC_GET_BY_IDX(DT_PATH(zephyr_user), 0);

void analog_temp_test_init()
{
    if(!device_is_ready(temp_adc_dev)){
        LOG_ERR("Adc device is not ready ");
        return;
    }
    LOG_INF("The ADC device is ready");
    if(!adc_is_ready_dt(&temp_adc_ch)){
        LOG_ERR("ADC is not ready 2 ");
        return;
    }

    int err = adc_channel_setup_dt(&temp_adc_ch);
    if(err){
        LOG_ERR("Failed to setup the ADC channel : %d ", err);
        return ;
    }

   
}

void analog_temp_test_loop()
{
    int16_t buffer;
    struct adc_sequence sequence ={
        .buffer = &buffer, 
        .buffer_size= sizeof(buffer)
    };

    int err = adc_sequence_init_dt(&temp_adc_ch, &sequence);
    if(err<0){
        LOG_ERR("Error in reading the addc ");
        return;
    }
    LOG_INF("Seq initialized");

    err = adc_read_dt(&temp_adc_ch,&sequence);

    if(err<0){
        LOG_ERR("Could not read the ADC");
        return ;
    }

    LOG_INF("Analog result : %d", buffer);
    LOG_INF("Temperature : %.2f", VOLTAGE_MV_TO_TEMP(buffer));
    float temp = ((buffer*3300.0/4095.0)-400)/19.5 ;
    LOG_INF("Temperature : %.2f", temp);

}