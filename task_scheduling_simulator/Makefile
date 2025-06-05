# Default to round-robin if not specified
MODE ?= roundrobin

ifeq ($(MODE),cooperative)
    SCHEDULER_MODE = 0
    TARGET = scheduler_cooperative
else ifeq ($(MODE),preemptive)
    SCHEDULER_MODE = 1
    TARGET = scheduler_preemptive
else ifeq ($(MODE),roundrobin)
    SCHEDULER_MODE = 2
    TARGET = scheduler_roundrobin
else
    $(error Invalid MODE: must be cooperative, preemptive, or roundrobin)
endif
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -pthread
CFLAGS += -I. -I../freertos/FreeRTOS/Source/include \
          -I../freertos/FreeRTOS/Source/portable/ThirdParty/GCC/Posix \
          -I../freertos/FreeRTOS/Source/portable/MemMang \
          -DSCHEDULER_MODE=$(SCHEDULER_MODE)

# Base paths
FREERTOS_DIR = ../freertos/FreeRTOS

# Includes
INCLUDES = \
  -I. \
  -I$(FREERTOS_DIR)/Source/include \
  -I$(FREERTOS_DIR)/Source/portable/ThirdParty/GCC/Posix \
  -I$(FREERTOS_DIR)/Source/portable/MemMang

# Source files
SOURCES = \
  main.c \
  task_functions.c \
  $(FREERTOS_DIR)/Source/tasks.c \
  $(FREERTOS_DIR)/Source/queue.c \
  $(FREERTOS_DIR)/Source/list.c \
  $(FREERTOS_DIR)/Source/timers.c \
  $(FREERTOS_DIR)/Source/event_groups.c \
  $(FREERTOS_DIR)/Source/portable/ThirdParty/GCC/Posix/port.c \
  $(FREERTOS_DIR)/Source/portable/MemMang/heap_4.c \
  $(FREERTOS_DIR)/Source/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c


# Build rule
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f $(TARGET)
