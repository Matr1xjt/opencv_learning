cmake_minimum_required(VERSION 2.8)
project(project1)
find_package(OpenCV)

add_executable(project1 project1.cpp)
target_link_libraries(project1 ${OpenCV_LIBS})

add_executable(color color.cpp)
target_link_libraries(color ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)