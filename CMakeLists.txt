cmake_minimum_required(VERSION 3.21)
project (Alogirthms_PI21E)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("${PROJECT_SOURCE_DIR}/linear_search" "${PROJECT_SOURCE_DIR}/linear_search/output")
add_subdirectory("${PROJECT_SOURCE_DIR}/binary_search" "${PROJECT_SOURCE_DIR}/binary_search/output")

add_executable(Alogirthms_PI21E main.cpp)
