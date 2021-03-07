# Instructions

- Clone repository and include submodules
> git clone --recurse-submodules git@github.com:raaavioli/DD2358-Software-Engineering-HPC.git

## Exercise 2 & 3
Source files are located in *Exercise-2/* respectively *Exercise-3/*
matrix.h is found under *include/*

Build system assumes you have an implementation of BLAS installed on your system, which you need to provide information about to cmake.
#### cmake arguments
* **BLAS_LIB**: path to a BLAS library implementation file, such as libopenblas.a
* **CBLAS_H**: path to directory where cblas.h and its required includes (i.e openblas_config.h for openblas)
* **BUILD_GMOCK**: turn gmock build *OFF*, as it is not used.

### Build instruction
> \> mkdir build
>
> \> cd build
>
> \> cmake *<path_to_CMakeLists.txt>* -DBUILD_GMOCK=OFF -DCBLAS_H=<path-to-cblas.h> -DBLAS_LIB=<path-to-blas/lib___.a>
>
> > Example:
> >
> > \> cmake .. -DBUILD_GMOCK=OFF -DCBLAS_H=/usr/include/OpenBLAS/ \ 
> >
> > \>          -DBLAS_LIB=/usr/lib/OpenBLAS/libopenblas.a
>
> \> make

### Exercise 3 test suites
*matrix_test* executable is located in *bin/*, run:
> \> ./bin/matrix_test

*matrix_test* tests the naive implementation of gemm.

*blas_test* executable is located in *bin/*, run:
> \> ./bin/blas_test

*blas_test* tests the BLAS implementation of gemm.

### Exercise 3 experiments
Executables to perform benchmark tests are compiled with the cmake script and located in */bin*

Benchmarks are named *benchmark_[naive|blas]*.

##### Usage
> \> ./benchmark_\<name\> \<max dimension\> \<increments\>

where *\<max dimension\>* determines the largest dimension of matrices benchmarked 
and *\<increments\>* determines the starting dimension of the matrices and the size of
the increments until *\<max dimension\>* is reached.

Example:
> \> ./bin/benchmark_naive 1000 10 > benchmark_naive.dat

##### Plot
To plot your benchmarks, example *gnuplot* scripts are found under /data from the base directory.

*flops.gp* creates a png image with *GFlops/s* on y and *dimension* on x.
> \> gnuplot flops.gp 

*execution_time.gp* creates a png image with execution time for one matrix-matrix multiplication on y, and the *dimension* on x.
> \> gnuplot execution_time.gp

Currently, the gnuplot scripts require the names *benchmark_naive.dat* and *benchmark_blas.dat*. To plot files with different names, change the names in the scripts under the *plot* command.

## Exercise 4 - Docker
Dockerfile is found in directory *Exercise-4/*.

Building the docker container requires you to have Docker installed and the daemon running.

> \> cd Exercise-4
>
> \> sudo docker build -t exercise4:latest .

Building the image may take several minutes due to installation of OpenBLAS

After build is finished, simply run the container
> \> sudo docker run --rm exercise4:latest

