#include<zephyr/kernel.h>
#include<zephyr/device.h>
#include<zephyr/drivers/sensor.h>
#include<sensor_sht40_test.h>
#include<zephyr/logging/log.h>


LOG_MODULE_REGISTER(sht40, LOG_LEVEL_DBG);

const struct device *const sensor_sht40_dev = DEVICE_DT_GET(DT_NODELABEL(sensor_sht40));


void sensor_sht40_init(){
    if(!device_is_ready(sensor_sht40_dev)){
        LOG_ERR("The sensor is not ready ");
        while(1){
            k_msleep(1000);
        }
    }

    LOG_INF("The sensor is ready");

}
void sensor_sht40_loop(){

    struct sensor_value temp ;
    struct sensor_value humid ;
    int ret ;

      if(sensor_sample_fetch(sensor_sht40_dev)!=0){
            LOG_ERR("Failed to take sample");
        }
        ret  = sensor_channel_get(sensor_sht40_dev, SENSOR_CHAN_AMBIENT_TEMP, &temp);
        if(ret==0){
          
            LOG_INF("Temperature : %.2f C", sensor_value_to_float(&temp));
        }
        ret = sensor_channel_get(sensor_sht40_dev, SENSOR_CHAN_HUMIDITY, &humid);
        if(ret==0){ 

            LOG_INF("Humidity : %.2f ", sensor_value_to_float(&humid));
        }

}