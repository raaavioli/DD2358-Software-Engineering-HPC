FROM ubuntu:20.04

ENV TZ=Europe/Stockholm
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
WORKDIR /
COPY exercise2-3.tar.gz .
RUN apt-get update \
	&& apt-get install -y build-essential cmake git wget gfortran \
	&& tar -xvzf exercise2-3.tar.gz

WORKDIR /build
RUN wget -O openblas.tar.gz "https://github.com/xianyi/OpenBLAS/releases/download/v0.3.13/OpenBLAS-0.3.13.tar.gz" && \
	tar -xvzf openblas.tar.gz && rm openblas.tar.gz && cd OpenBLAS-0.3.13 && \
	make -j$(nproc)

WORKDIR /build
RUN cmake .. -DBUILD_GMOCK=OFF -DCBLAS_H=/build/OpenBLAS-0.3.13 \
	-DBLAS_LIB=/build/OpenBLAS-0.3.13/libopenblas.a && \
	make

WORKDIR /build/bin
CMD ./matrix_test

