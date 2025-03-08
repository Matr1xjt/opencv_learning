cmake_minimum_required(VERSION 2.8)

project(project3)
find_package(OpenCV REQUIRED)

add_executable(project3 project3.cpp)
target_link_libraries(project3 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)