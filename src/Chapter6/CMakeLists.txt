cmake_minimum_required(VERSION 2.8)
project(Chapter6)

find_package(OpenCV REQUIRED)

add_executable(chapter6 chapter6.cpp)
target_link_libraries(chapter6 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)