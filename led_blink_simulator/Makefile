TARGET = blink
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -pthread

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
