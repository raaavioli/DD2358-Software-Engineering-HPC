cmake_minimum_required(VERSION 3.1)

project(exercise-2
  VERSION 1.0
  DESCRIPTION "Exercise-2 google test build"
  LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(matrix ${CMAKE_SOURCE_DIR}/Exercise-2/matrix.c)

add_subdirectory(googletest)

add_executable(matrix_test ${CMAKE_SOURCE_DIR}/Exercise-2/matrix_test.cpp)
target_link_libraries(matrix_test
  matrix
  gtest gtest_main)

set_target_properties(matrix matrix_test
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "lib/"
  LIBRARY_OUTPUT_DIRECTORY "lib/"
  RUNTIME_OUTPUT_DIRECTORY "bin/")
