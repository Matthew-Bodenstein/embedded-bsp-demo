#include "sensor_driver.h"
#include <stdlib.h>
#include <time.h>

void sensor_init(void) {
    // In real hardware: configure ADC, I2C, SPI, etc.
    // Here: just seed random generator
    srand((unsigned int)time(NULL));
}

int sensor_read(void) {
    // Simulated sensor value: 0–119
    return rand() % 120;
}
