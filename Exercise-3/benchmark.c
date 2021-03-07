#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

#include "matrix.h"

/**
 * Benchmark program copied from course material in DD2358.
 * Used to benchmark matrix multiplication.
 */

double gettime(void) 
{
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec + 1e-6*tv.tv_usec;
}

int main(int argc, char **argv)
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <max-dim> <increment>\n", argv[0]);
    exit(-1);
  }

  const int max_dim = atoi(argv[1]);
  const int increment = atoi(argv[2]);

  double *A = (double *) malloc( max_dim * max_dim * sizeof(double));
  double *B = (double *) malloc( max_dim * max_dim * sizeof(double));
  double *C = (double *) malloc( max_dim * max_dim * sizeof(double));

  memset(A, 1, max_dim * max_dim * sizeof(double));
  memset(B, 2, max_dim * max_dim * sizeof(double));
  memset(C, 0, max_dim * max_dim * sizeof(double));

  for(int dim = increment; dim <= max_dim; dim+=increment) {
    double t = gettime();
    for (int j = 0; j < 100; j++) {
      gemm(dim, C, A, B);
    }
    t = gettime() - t;
    printf("%d\t%f\t%E\n", dim, t, 100 * 2 * pow(dim, 3) / t);
  }

  free(A);
  free(B);
  free(C);
  return 0;
}
