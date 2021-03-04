# Instructions

- Clone repository and include submodules
> git clone --recurse-submodules git@github.com:raaavioli/DD2358-Software-Engineering-HPC.git

## Exercise 2 & 3
Source files are located in *Exercise-2/* respectively *Exercise-3/*
matrix.h is found under *include/*

Build system assumes you have an implementation of BLAS installed on your system, which you need to provide information about to cmake.
#### cmake arguments
* BLAS_LIB: path to BLAS library implementation file, such as libopenblas.a
* CBLAS_H: path to directory where cblas.h and its required includes (i.e openblas_config.h for openblas)

### Build
> mkdir build
>
> cd build
>
> cmake *<path_to_CMakeLists.txt>* -DBUILD_GMOCK=OFF -DCBLAS_H=<path-to-cblas.h> -DBLAS_LIB=<path-to-blas/lib___.a>
>
> > Example: cmake .. -DBUILD_GMOCK=OFF -DCBLAS_H=/usr/include/OpenBLAS/ -DBLAS_LIB=/usr/lib/OpenBLAS/libopenblas.a
>
> make

*matrix_test* executable is located in *bin/*, run:
> ./bin/matrix_test

*blas_test* executable is located in *bin/*, run:
> ./bin/blas_test


