cmake_minimum_required(VERSION 3.10.0)
project(ch01 VERSION 0.1.0)

message(STATUS ${PROJECT_NAME})
message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_BINARY_DIR})
message(STATUS ${PROJECT_IS_TOP_LEVEL})

add_subdirectory(area_function)
add_subdirectory(farmer)
