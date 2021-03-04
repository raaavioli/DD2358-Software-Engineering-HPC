#Instructions

- Clone repository and include submodules
> git clone --recurse-submodules git@github.com:raaavioli/DD2358-Software-Engineering-HPC.git

## Exercise 2
Source files are located in *Exercise-2/*
matrix.h is found under *include/*
### Build
> mkdir build
>
> cd build
>
> cmake *<path_to_CMakeLists.txt>* -DBUILD_GMOCK=OFF
>
> make

*matrix_test* executable is located in *bin/*, run:
> ./bin/matrix_test


