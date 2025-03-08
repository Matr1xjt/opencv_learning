cmake_minimum_required(VERSION 2.8)
project(Chapter5)

find_package(OpenCV REQUIRED)

add_executable(chapter5 chapter5.cpp)
target_link_libraries(chapter5 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)