cmake_minimum_required(VERSION 3.1)

project(exercise-2
  VERSION 1.0
  DESCRIPTION "Exercise-2 google test build"
  LANGUAGES C CXX)

# GENERAL
include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(googletest)

# LIBRARIES
find_library(THREAD pthread)
if (NOT THREAD)
  message(FATAL_ERROR "libpthread.a not found")
endif()
find_library(MATH m)
if(NOT MATH)
  message(FATAL_ERROR "libm.a not found")
endif()

# Naive impl of gemm
add_library(matrix ${CMAKE_SOURCE_DIR}/Exercise-2/matrix.c)

# Blas impl of gemm
add_library(blas_matrix ${CMAKE_SOURCE_DIR}/Exercise-3/blas_matrix.c)
if(NOT CBLAS_H)
  message(FATAL_ERROR "cblas.h include directory missing, i.e '-DCBLAS_H=/usr/include/'")
elseif(NOT BLAS_LIB)
  message(FATAL_ERROR "BLAS library missing, i.e libopenblas.a: '-DBLAS_LIB=/usr/lib/OpenBLAS/libopenblas.a'")
else()
  message("cblas.h and blas library paths specified: " ${CBLAS_H} ", " ${BLAS_LIB} )
endif()
target_include_directories(blas_matrix PUBLIC ${CBLAS_H})
target_link_libraries(blas_matrix ${BLAS_LIB})
target_link_libraries(blas_matrix ${THREAD})


#EXECUTABLES

# Gtest suite with naive gemm
add_executable(matrix_test ${CMAKE_SOURCE_DIR}/Exercise-2/matrix_test.cpp)
target_link_libraries(matrix_test
  matrix gtest gtest_main)

# Gtest suite with blas gemm
add_executable(blas_test ${CMAKE_SOURCE_DIR}/Exercise-2/matrix_test.cpp)
target_link_libraries(blas_test
  blas_matrix gtest gtest_main)

# Benchmark of naive gemm
add_executable(benchmark_naive ${CMAKE_SOURCE_DIR}/Exercise-3/benchmark.c)
target_link_libraries(benchmark_naive matrix)
target_link_libraries(benchmark_naive ${MATH})

# Benchmark of blas gemm
add_executable(benchmark_blas ${CMAKE_SOURCE_DIR}/Exercise-3/benchmark.c)
target_link_libraries(benchmark_blas ${MATH})
target_link_libraries(benchmark_blas
  blas_matrix)

set_target_properties(matrix blas_matrix matrix_test blas_test benchmark_naive benchmark_blas
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "lib/"
  LIBRARY_OUTPUT_DIRECTORY "lib/"
  RUNTIME_OUTPUT_DIRECTORY "bin/")
