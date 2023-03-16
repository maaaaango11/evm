cmake_minimum_required(VERSION 3.15)
project(usb C)

set(CMAKE_C_STANDARD 99)

target_include_directories(usb "D:/wrk/evm/libusb-1.0.24/include")


add_executable(usb main.c)

target_link_libraries(usb "D:/wrk/evm/libusb-1.0.24")



