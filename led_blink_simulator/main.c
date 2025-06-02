#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

uint16_t get_led_delay(uint8_t led_num) {
    switch(led_num) {
        case 1:
            return 500;
        case 2:
            return 1000;
        case 3:
            return 1500;
        default:
            return 2000;
    }
}
void vTaskFunction1(void *pvParameters) {
    int led_num = *((int*)pvParameters);
    uint16_t delay_time_ms = get_led_delay(led_num);

    for( ;; ) {
        printf("LED %d ON\n", led_num);
        vTaskDelay(pdMS_TO_TICKS(delay_time_ms/2));
        printf("LED %d OFF\n", led_num);
        vTaskDelay(pdMS_TO_TICKS(delay_time_ms/2));
    }
}

int main(void) {
    int led1 = 1, led2 = 2, led3 = 3;

    // create tasks
    xTaskCreate(vTaskFunction1, "LED1", 1000, &led1, 1, NULL);
    xTaskCreate(vTaskFunction1, "LED2", 1000, &led2, 1, NULL);
    xTaskCreate(vTaskFunction1, "LED3", 1000, &led3, 1, NULL);\

    vTaskStartScheduler();

    return 0;
}
