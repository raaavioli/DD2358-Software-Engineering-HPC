cmake_minimum_required(VERSION 3.1)

project(exercise-2
  VERSION 1.0
  DESCRIPTION "Exercise-2 google test build"
  LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(googletest)

add_library(matrix ${CMAKE_SOURCE_DIR}/Exercise-2/matrix.c)

add_executable(matrix_test ${CMAKE_SOURCE_DIR}/Exercise-2/matrix_test.cpp)

target_link_libraries(matrix_test
  matrix gtest gtest_main)

add_executable(blas_test ${CMAKE_SOURCE_DIR}/Exercise-3/blas_test.cpp)
if(NOT CBLAS_H)
  message(FATAL_ERROR "Please specify location of cblas.h, i.e '-DCBLAS_H=/usr/include/'")
elseif(NOT BLAS_LIB)
  message(FATAL_ERROR "Please specify path to your BLAS library, i.e libopenblas.a: '-DBLAS_LIB=/usr/lib/OpenBLAS/libopenblas.a'")
else()
  message("cblas.h and libopenblas.a found: " ${CBLAS_H} ", " ${BLAS_LIB} )
endif()
target_include_directories(blas_test PRIVATE ${CBLAS_H})
target_link_libraries(blas_test
  ${BLAS_LIB}/libopenblas.a gtest gtest_main)

set_target_properties(matrix matrix_test blas_test
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "lib/"
  LIBRARY_OUTPUT_DIRECTORY "lib/"
  RUNTIME_OUTPUT_DIRECTORY "bin/")
