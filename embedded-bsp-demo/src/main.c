/* main.c - Embedded BSP Demo with FreeRTOS
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include <stdio.h>
#include "uart_driver.h"
#include "sensor_driver.h"
#include "memory_test.h"

/* Task prototypes */
void vUartTask(void* pvParameters);
void vSensorTask(void* pvParameters);
void vMemoryTask(void* pvParameters);

int main(void) {
    printf("Starting Embedded BSP Demo...\n");

    // BSP-style initialization
    uart_init();
    sensor_init();
    memory_test_init();

    // Create FreeRTOS tasks
    xTaskCreate(vUartTask, "UART", 200, NULL, 1, NULL);
    xTaskCreate(vSensorTask, "Sensor", 200, NULL, 1, NULL);
    xTaskCreate(vMemoryTask, "Memory", 200, NULL, 1, NULL);

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
}

/* TASK IMPLEMENTATIONS  */

/* UART heartbeat task */
void vUartTask(void* pvParameters) {
    (void)pvParameters;
    for (;;) {
        uart_send("Heartbeat");
        vTaskDelay(pdMS_TO_TICKS(1000)); // run every 1s
    }
}

/* Sensor read task */
void vSensorTask(void* pvParameters) {
    (void)pvParameters;
    for (;;) {
        int val = sensor_read();
        printf("[Sensor Task] Value = %d\n", val);
        vTaskDelay(pdMS_TO_TICKS(500)); // run every 0.5s
    }
}

/* Memory test task */
void vMemoryTask(void* pvParameters) {
    (void)pvParameters;
    for (;;) {
        memory_test_run();
        vTaskDelay(pdMS_TO_TICKS(2000)); // run every 2s
    }
}
