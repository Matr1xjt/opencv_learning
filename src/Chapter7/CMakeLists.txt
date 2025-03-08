cmake_minimum_required(VERSION 2.8)
project(Chapter7)

find_package(OpenCV REQUIRED)

add_executable(chapter7 chapter7.cpp)
target_link_libraries(chapter7 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)