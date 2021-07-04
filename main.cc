#include "pico/stdlib.h"
#include "hardware/pwm.h"

const uint LED_PIN = 25;

int blink() {

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (1) {
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
        gpio_put(LED_PIN, 1);
        sleep_ms(100);
	gpio_put(LED_PIN, 0);
	sleep_ms(100);
	gpio_put(LED_PIN,1);
	sleep_ms(100);
    }
}

int blink2() {
	gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
	uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
	pwm_set_wrap(slice_num, 65535U);
	pwm_set_gpio_level(LED_PIN, 10000);
	pwm_set_enabled(slice_num, true);
	pwm_set_clkdiv_int_frac(slice_num, 255, 0);
	for(;;) {}
}

int main() {
	blink2();
	return 0;
}
