#include "matrix.h"

#include <stddef.h>

void gemm(int n, double* c, double* a, double* b) 
{
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      // reset c in case it contained some value
      c[i * n + j] = 0;
      for (size_t k = 0; k < n; k++)
      {
        c[i * n + j] += a[i * n + k] * b[k * n + j];
      }
    }
  }
}


