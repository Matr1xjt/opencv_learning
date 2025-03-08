cmake_minimum_required(VERSION 2.8)
project(Chapter2)
find_package(OpenCV REQUIRED)

add_executable(chapter2 chapter2.cpp)
target_link_libraries(chapter2 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)