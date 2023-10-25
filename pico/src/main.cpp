#include <stdio.h>
#include "hardware/gpio.h"
#include "pico/stdlib.h"

const uint SENSE_PIN = 16;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void init_onboard_led() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, false);
}

void init_reed_sense() {
  gpio_init(SENSE_PIN);
  gpio_set_dir(SENSE_PIN, GPIO_IN);
  gpio_pull_up(SENSE_PIN);
}

void set_onboard_led(bool on) {
  gpio_put(LED_PIN, on);
}

void init_pins() {
    init_onboard_led();
    init_reed_sense();
}

void check_reed_forever() {
    bool is_hi = true;
    set_onboard_led(true);
    while (true) {
      if (gpio_get(SENSE_PIN) != is_hi) {
        is_hi = !is_hi;
        set_onboard_led(is_hi);
        printf("\r%s", is_hi ? "OPEN  " : "CLOSED");
      }
    }
}

int main() {
    init_pins();
    stdio_init_all();
    check_reed_forever();
    //while (true) {
    //  set_onboard_led(false);
    //  printf("Off\n");
    //  sleep_ms(1000);
    //  set_onboard_led(true);
    //  printf("On\n");
    //  sleep_ms(500);
    //}
    return 0;
}
