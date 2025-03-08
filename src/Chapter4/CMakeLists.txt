cmake_minimum_required(VERSION 2.8)
project(Chapter4)

find_package(OpenCV REQUIRED)

add_executable(chapter4 chapter4.cpp)
target_link_libraries(chapter4 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)