#include<zephyr/kernel.h>
#include<zephyr/logging/log.h>
#include<zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include<sensor_sht40_test.h>
#include<analog_temp_test.h>
void led1_timer_handler(void *params);
void led2_timer_handler(void *params);
void led3_timer_handler(void *params);
K_TIMER_DEFINE(led1_timer,led1_timer_handler, NULL);
K_TIMER_DEFINE(led2_timer,led2_timer_handler,  NULL);
K_TIMER_DEFINE(led3_timer,led3_timer_handler, NULL);

bool led1_state = false ;
bool led2_state = false ;
bool led3_state = false ;
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED3_NODE DT_ALIAS(led2)

static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led3 = GPIO_DT_SPEC_GET(LED3_NODE, gpios);

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

int main()
{
    int ret ;
    if (!gpio_is_ready_dt(&led1)) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

    if (!gpio_is_ready_dt(&led2)) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led2, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	} 

    if (!gpio_is_ready_dt(&led3)) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led3, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

    /*k_timer_start(&led1_timer, K_USEC(1),  K_USEC(1));
    
    k_timer_start(&led2_timer, K_MSEC(1),  K_MSEC(1));
    k_timer_start(&led3_timer, K_SECONDS(2),  K_SECONDS(2));*/
    //sensor_sht40_init();
    //analog_temp_test_init();
    while(1)
    {
        k_msleep(5000);
        //gpio_pin_toggle_dt(&led3);
        //gpio_pin_toggle_dt(&led1);
        //gpio_pin_toggle_dt(&led2);
        //sensor_sht40_loop();
         //analog_temp_test_loop();
         //analog_temp_test_loop();
        //LOG_INF("Hello find of a girl");
        k_msleep(1000);
    }
    return 0 ;
}

int i=0 ;
void led1_timer_handler(void *params){
    i++ ;
    if (i==500){
        gpio_pin_toggle_dt(&led1);
        i=0 ;
    }
    
}

void led2_timer_handler(void *params){
  gpio_pin_toggle_dt(&led2);
}

void led3_timer_handler(void *params){
  gpio_pin_toggle_dt(&led3);
}