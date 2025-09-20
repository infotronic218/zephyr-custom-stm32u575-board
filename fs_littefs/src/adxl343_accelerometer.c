#include"adxl343_accelerometer.h"
#include<zephyr/kernel.h>
#include<zephyr/logging/log.h>
#include<zephyr/device.h>
#include<zephyr/drivers/sensor.h>


static const struct device *accelerometer_dev = DEVICE_DT_GET(DT_NODELABEL(sensoor_adxl343));
LOG_MODULE_REGISTER(accel, LOG_LEVEL_DBG);

void adxl343_accelerometer_init(){
    if(!device_is_ready(accelerometer_dev)){
        LOG_ERR("The accelerometer is not ready ");
        return;
    }else{
        LOG_INF("The sensor is initialized succesfully ");
    }

    
    
   
    

}


void adxl343_accelerometer_loop()
{
  struct sensor_value  val_x , val_y, val_z;

  int ret = sensor_sample_fetch(accelerometer_dev);
  if(!ret){
    LOG_ERR("Failed to fetch the sensor sample");
    return ;
  }

  ret = sensor_channel_get(accelerometer_dev, SENSOR_CHAN_ACCEL_X, &val_x);
  ret = sensor_channel_get(accelerometer_dev, SENSOR_CHAN_ACCEL_Y, &val_y);
  ret = sensor_channel_get(accelerometer_dev, SENSOR_CHAN_ACCEL_Z, &val_z);
  LOG_INF("Accel data : x=%.2f; y=%.2f; z=%.2f ;", sensor_value_to_float(&val_x),
                                                   sensor_value_to_float(&val_y),
                                                   sensor_value_to_float(&val_z)
                                                );


  




  


}