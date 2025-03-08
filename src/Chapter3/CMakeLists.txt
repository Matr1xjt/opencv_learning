cmake_minimum_required(VERSION 2.8)
project(chapter3)
find_package(OpenCV REQUIRED)

add_executable(chapter3 chapter3.cpp)
target_link_libraries(chapter3 ${OpenCV_LIBS})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)