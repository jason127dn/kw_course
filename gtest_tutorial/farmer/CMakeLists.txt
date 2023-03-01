cmake_minimum_required(VERSION 3.10.0)
project(farmer VERSION 0.1.0)
 
message(STATUS ${PROJECT_NAME})
message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_BINARY_DIR})
message(STATUS ${PROJECT_IS_TOP_LEVEL})

add_executable(farmer_static src/main.cpp)
target_include_directories(farmer_static PUBLIC ../area_function/include)
target_link_libraries(farmer_static -L../area_function/lib/static area_static)

add_executable(farmer_shared src/main.cpp)
target_include_directories(farmer_shared PUBLIC ../area_function/include)
target_link_libraries(farmer_shared -L../area_function/lib/shared area_shared)

