cmake_minimum_required(VERSION 2.8)

project(Chapter1)
find_package(OpenCV REQUIRED)
add_executable(chapter1 chapter_1.cpp)
target_link_libraries(chapter1 ${OpenCV_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
