cmake_minimum_required(VERSION 2.8)

project(chapter8)
find_package(OpenCV REQUIRED)

add_executable(chapter8 chapter8.cpp)
target_link_libraries(chapter8 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)