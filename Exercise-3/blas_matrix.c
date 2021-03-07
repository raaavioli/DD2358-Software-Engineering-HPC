#include "matrix.h"
#include <stddef.h>

#include <cblas.h>

void gemm(int dim, double* c, double* a, double* b)
{
  const double alpha = 1.0;
  const double beta = 0.0;
  const int lda = dim;
  const int ldb = dim;
  const int ldc = dim;

  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
    dim, dim, dim, alpha, a, lda,
    b, ldb, beta, c, ldc);
}



