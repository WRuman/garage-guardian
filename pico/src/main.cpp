#include <stdio.h>
#include "hardware/gpio.h"
#include "pico/stdlib.h"

const uint SENSE_PIN = 16;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void configureOnboardLED() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, false);
}

void setOnboardLED(bool on) {
  gpio_put(LED_PIN, on);
}

int main() {
    stdio_init_all();
    configureOnboardLED();

    gpio_init(SENSE_PIN);
    gpio_set_dir(SENSE_PIN, GPIO_IN);
    gpio_pull_up(SENSE_PIN);

    bool is_hi = true;

    while (true) {
      if (gpio_get(SENSE_PIN) != is_hi) {
        is_hi = !is_hi;
        setOnboardLED(is_hi);
        printf("\r%s", is_hi ? "OPEN  " : "CLOSED");
      }
    }
    return 0;
}
