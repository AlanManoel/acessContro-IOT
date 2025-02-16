cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(acesscontrol C CXX ASM)

pico_sdk_init()

add_executable(acesscontrol main.c inc/ssd1306_i2c.c
    modules/led/led_control.c
    modules/input_handler/input_handler.c
    modules/display_oled/display_oled.c
    modules/buzzer/buzzer.c
    )

pico_set_program_name(acesscontrol "acesscontrol")
pico_set_program_version(acesscontrol "0.1")

pico_enable_stdio_uart(acesscontrol 0)
pico_enable_stdio_usb(acesscontrol 1)

target_link_libraries(acesscontrol
        pico_stdlib
        hardware_pwm)

target_include_directories(acesscontrol PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(acesscontrol 
        hardware_i2c
        )

pico_add_extra_outputs(acesscontrol)

