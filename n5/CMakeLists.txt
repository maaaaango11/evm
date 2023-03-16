cmake_minimum_required(VERSION 3.15)
project(webcam)

set(CMAKE_CXX_STANDARD 14)

set(OpenCV_DIR "D:/wrk/evm/opencv-master/mingw-build/install")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenCV COMPONENTS core imgproc highgui objdetect REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(webcam main.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(webcam ${OpenCV_LIBS})