#include <stdio.h>
#include "uart_driver.h"

void uart_init(void) {
    printf("[UART] Initialized.\n");
}

void uart_send(const char* msg) {
    printf("[UART] Sent: %s\n", msg);
}
