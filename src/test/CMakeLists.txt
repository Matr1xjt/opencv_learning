cmake_minimum_required(VERSION 2.8)
project(opencv_learning)
find_package(OpenCV REQUIRED)
add_executable(test test.cpp)   
target_link_libraries(test ${OpenCV_LIBS})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)