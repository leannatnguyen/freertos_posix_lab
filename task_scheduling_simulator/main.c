#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "task_functions.h"


int main(void) {
    xTaskCreate(vLowPriorityTask, "Low1", configMINIMAL_STACK_SIZE, (void *)(intptr_t)1, 1, NULL);
    xTaskCreate(vLowPriorityTask, "Low2", configMINIMAL_STACK_SIZE, (void *)(intptr_t)2, 1, NULL);
    xTaskCreate(vMediumPriorityTask, "Medium", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(vHighPriorityTask, "High", configMINIMAL_STACK_SIZE, NULL, 3, NULL);

    vTaskStartScheduler();

    for ( ;; ) {

    }
    return 0;
}
