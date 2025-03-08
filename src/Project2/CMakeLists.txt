cmake_minimum_required(VERSION 2.8)
project(project2)
find_package(OpenCV)

add_executable(project2 project2.cpp)
target_link_libraries(project2 ${OpenCV_LIBS})


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)