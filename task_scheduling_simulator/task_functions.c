// #include "FreeRTOS.h"
// #include <stdio.h>
// #include "task_functions.h"
// #include "task.h"


// void vLowPriorityTask(void *pvParams) {
//     const TickType_t low_delay = pdMS_TO_TICKS(10000);
//     for ( ;; ) {
//         printf("Low Priority Task %d Executing \n", (int)(intptr_t)pvParams);
//         vTaskDelay(low_delay);
//     }
// }

// void vMediumPriorityTask(void *pvParams) {
//     const TickType_t medium_delay = pdMS_TO_TICKS(5000);
//     for ( ;; ) {
//         printf("Medium Priority Task Executing \n");
//         vTaskDelay(medium_delay);
//     }
// }

// void vHighPriorityTask(void *pvParams) {
//     const TickType_t high_delay = pdMS_TO_TICKS(2500);
//     for ( ;; ) {
//         printf("High Priority Task Executing\n");
//         vTaskDelay(high_delay);
//     }
// }

#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <inttypes.h>
#include "task_functions.h"

void vLowPriorityTask(void *pvParams) {
    const TickType_t low_delay = pdMS_TO_TICKS(10000);
    for (;;) {
        printf("[%" PRIu32 " ms] %s (Priority %lu): Executing, param = %d\n",
               (uint32_t)xTaskGetTickCount(),
               pcTaskGetName(NULL),
               (unsigned long)uxTaskPriorityGet(NULL),
               (int)(intptr_t)pvParams);
        vTaskDelay(low_delay);
    }
}

void vMediumPriorityTask(void *pvParams) {
    const TickType_t medium_delay = pdMS_TO_TICKS(5000);
    for (;;) {
        printf("[%" PRIu32 " ms] %s (Priority %lu): Executing\n",
               (uint32_t)xTaskGetTickCount(),
               pcTaskGetName(NULL),
               (unsigned long)uxTaskPriorityGet(NULL));
        vTaskDelay(medium_delay);
    }
}

void vHighPriorityTask(void *pvParams) {
    const TickType_t high_delay = pdMS_TO_TICKS(2500);
    for (;;) {
        printf("[%" PRIu32 " ms] %s (Priority %lu): Executing\n",
               (uint32_t)xTaskGetTickCount(),
               pcTaskGetName(NULL),
               (unsigned long)uxTaskPriorityGet(NULL));
        vTaskDelay(high_delay);
    }
}
