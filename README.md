# Instructions

- Clone repository and include submodules
> git clone --recurse-submodules git@github.com:raaavioli/DD2358-Software-Engineering-HPC.git

## Exercise 2 & 3
Source files are located in *Exercise-2/* respectively *Exercise-3/*. matrix.h is found under *include/*

The build system assumes you have an implementation of BLAS installed on your system, which you need to provide information about to cmake. For example, install and compile [OpenBLAS](http://www.openblas.net/), and make sure to put *cblas.h* and *openblas_config.h* in the same directory.

#### cmake arguments
* **BLAS_LIB** (required): path to a BLAS library implementation file, such as libopenblas.a (including file name)
* **CBLAS_H** (required): path to directory containing cblas.h and its required includes (i.e openblas_config.h for openblas)
* **LIBXSMM_ENABLED**: set to *TRUE* to compile and link binaries for libxsmm, **required for bonus assignment**
* **BUILD_GMOCK**: set to *OFF* to avoid unnecessary build, as it is not used.

### Build instruction
Following will build LIBXSMM and link all necessary libraries and produce binaries for all following execises, including bonus. Thus, **this step may take a few minutes**.

> \> mkdir build
>
> \> cd build
>
> \> cmake *<path_to_CMakeLists.txt>* -DBUILD_GMOCK=OFF -DLIBXSMM_ENABLED=TRUE -DCBLAS_H=<path-to-cblas.h> -DBLAS_LIB=<path-to-blas/lib___.a>
>
> > Example:
> >
> > \> cmake .. -DBUILD_GMOCK=OFF -DLIBXSMM_ENABLED=TRUE -DCBLAS_H=/usr/include/OpenBLAS/ \ 
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

### Acquire tarball
Create the tarball *exercise2-3.tar.gz* needed to run the docker container
> \> cd Exercise-4 && ./tarball.sh

### Build image
Building the docker container requires you to have Docker installed and the daemon running.

> \> cd Exercise-4
>
> \> sudo docker build -t exercise4:latest .

Building the image **may take several minutes** due to installation of OpenBLAS

### Run programs in container
After build is finished, simply run the appropriate benchmark inside the container

#### Default
Run gemm test on naive matrix implementation by default
> \> sudo docker run --rm exercise4:latest

#### Specify specific program
Run a specific program inside the container
> \> sudo docker run --rm exercise4:latest \<program\>

where \<program\> is one of: 
* ./matrix_test
* ./blas_test
* ./benchmark_blas \<max dimension\> \<increments\>
* ./benchmark_naive \<max dimension\> \<increments\>

## Exercise Bonus - LIBXSMM
Bonus exercise source file are located in *Exercise-Bonus/*.

If cmake build done to compile exercise 2 and 3 was properly executed, LIBXSMM should already be built and compiled.
See libxsmm_matrix.c for implementation of gemm in libxsmm.

As with exercise 3 and 2, the *xsmm_test*, which is the google test using libxsmm, and the libxsmm benchmark *benchmark_xsmm* are located inside *bin* as with the binaries in exercise 2 and 3. The binaries are executed as those in exercise 2 and 3.

> \> ./xsmm_test
or
> \> ./benchmark_xsmm 1000 10 > output_file.dat

Gnuplot script *xsmm_flops.gp* for plotting benchmarks is located in *data/* from the repository's root directory. To run the script, make sure to name your data-files properly to benchmark\_[naive|blas|xsmm]\_small.dat or change the naming configuration in *xsmm_flops.gp*.

