#include <matrix.h>

#include <libxsmm.h>

void gemm(int dim, double* c, double* a, double* b)
{
	const char* transpose = NULL;
	const int m = dim, n = dim, k = dim, lda = dim, ldb = dim, ldc = dim;
	const double alpha = 1.0, beta = 0.0;

	libxsmm_dgemm(
		transpose, transpose,
  	&m, &n, &k,
  	&alpha, a, &lda, 
		b, &ldb, &beta, 
		c, &ldc);
}
