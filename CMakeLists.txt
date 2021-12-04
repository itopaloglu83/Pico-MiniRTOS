cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(minirtos)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_library(FreeRTOS STATIC
    FreeRTOS-Kernel/croutine.c
    FreeRTOS-Kernel/event_groups.c
    FreeRTOS-Kernel/list.c
    FreeRTOS-Kernel/queue.c
    FreeRTOS-Kernel/stream_buffer.c
    FreeRTOS-Kernel/tasks.c
    FreeRTOS-Kernel/timers.c
    FreeRTOS-Kernel/portable/GCC/ARM_CM0/port.c
    FreeRTOS-Kernel/portable/MemMang/heap_4.c
)

target_include_directories(FreeRTOS PUBLIC
    include/
    FreeRTOS-Kernel/include
    FreeRTOS-Kernel/portable/GCC/ARM_CM0
)

add_executable(${CMAKE_PROJECT_NAME}
    minirtos.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(${CMAKE_PROJECT_NAME} pico_stdlib FreeRTOS)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${CMAKE_PROJECT_NAME})
