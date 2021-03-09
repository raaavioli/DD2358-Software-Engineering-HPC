#set terminal dumb enhanced ansi256
#set term dumb 94 44
set terminal png
set autoscale
set output "gflop_xsmm_benchmark.png"

set xlabel "Dimension"
set ylabel "GFlops/s"
set border 3 lw 1
set title "Ryzen 5 1600x, gcc 7.5.0"
set tics nomirror
set key inside left
plot  "benchmark_naive_small.dat" using 1:($3/1e9) with linespoints title "Naive", \
      "benchmark_blas_small.dat" using 1:($3/1e9) with linespoints title "OpenBLAS", \
      "benchmark_xsmm_small.dat" using 1:($3/1e9) with linespoints title "LIBXSMM"
