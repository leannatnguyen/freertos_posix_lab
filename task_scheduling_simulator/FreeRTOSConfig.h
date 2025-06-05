#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* ==== Scheduler Mode Switch ==== */
/* Pass -DSCHEDULER_MODE=N in the compiler flags or default to mode 2 (round-robin) */
#ifndef SCHEDULER_MODE
#define SCHEDULER_MODE 2
#endif

#if SCHEDULER_MODE == 0
    /* Cooperative scheduling */
    #define configUSE_PREEMPTION 0
    #define configUSE_TIME_SLICING 0
#elif SCHEDULER_MODE == 1
    /* Preemptive scheduling without time slicing */
    #define configUSE_PREEMPTION 1
    #define configUSE_TIME_SLICING 0
#elif SCHEDULER_MODE == 2
    /* Preemptive scheduling with time slicing (round-robin) */
    #define configUSE_PREEMPTION 1
    #define configUSE_TIME_SLICING 1
#else
    #error "Invalid SCHEDULER_MODE. Must be 0 (cooperative), 1 (preemptive), or 2 (round-robin)."
#endif

/* ==== Standard FreeRTOS Config ==== */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCPU_CLOCK_HZ                      (1000000)
#define configTICK_RATE_HZ                      (1000)
#define configMAX_PRIORITIES                    (5)
#define configMINIMAL_STACK_SIZE                (128)
#define configTOTAL_HEAP_SIZE                   (32 * 1024)
#define configUSE_16_BIT_TICKS                  0
#define configUSE_MUTEXES                       1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               (2)
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            (256)
#define configCHECK_FOR_STACK_OVERFLOW          0
#define configUSE_MALLOC_FAILED_HOOK            0

/* ==== POSIX Port Required Setting ==== */
#define configUSE_POSIX_ERRNO                   1

/* ==== API Function Inclusion ==== */
#define INCLUDE_vTaskDelay                      1   

#endif /* FREERTOS_CONFIG_H */
