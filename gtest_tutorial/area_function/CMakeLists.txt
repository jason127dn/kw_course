cmake_minimum_required(VERSION 3.10.0)
project(area_functions VERSION 0.1.0)

message(STATUS ${PROJECT_NAME})
message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_BINARY_DIR})
message(STATUS ${PROJECT_IS_TOP_LEVEL})

find_package(GTest)
message(STATUS "GTest_FOUND:" ${GTest_FOUND})
add_library(area_shared SHARED src/area.cpp)
target_include_directories(area_shared PUBLIC include)

add_library(area_static src/area.cpp)
target_include_directories(area_static PUBLIC include)
set_target_properties(area_static PROPERTIES PUBLIC_HEADER include/area.h)

add_executable(test_area test/test_area.cpp src/area.cpp)
target_include_directories(test_area PUBLIC include)
target_link_libraries(test_area gtest)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test_area)

install(
  TARGETS area_static
  ARCHIVE DESTINATION ${CMAKE_BINARY_DIR}/lib/static
  PUBLIC_HEADER DESTINATION ${CMAKE_BINARY_DIR}/include)

install(
  TARGETS area_shared
  LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/lib/shared)

set(GET_CODE_COVERAGE OFF)

if(GET_CODE_COVERAGE)
  
  include(CodeCoverage)
  append_coverage_compiler_flags()

  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE ctest -j ${n_cores} # Executable in PROJECT_BINARY_DIR
    DEPENDENCIES test_area)
endif()
