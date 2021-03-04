#include <gtest/gtest.h>

#include <stddef.h>

extern "C" 
{
  #include "matrix.h"
}

void compare_matrices(size_t size, double* expected, double* actual)
{
  for(size_t i = 0; i < size; i++)
  {
    ASSERT_DOUBLE_EQ(expected[i], actual[i]);
  }
}

/**
 * Tests multiplying M with an Identity matrix
 * I * M = M * I = M
 */
TEST(MatrixTest, AssertIdentityMatrixProperty)
{
  // Arrange
  constexpr size_t dim = 3;
  constexpr size_t size = dim * dim;
  double M[size] = {
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
  };

  double I[size] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
  };

  double expected[size] = {
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
  };

  // Act
  double res1[size] = { 0 };
  gemm(static_cast<int>(dim), res1, M, I);

  double res2[size] = { 0 };
  gemm(static_cast<int>(dim), res2, I, M);

  // Assert
  compare_matrices(size, expected, res1);
  compare_matrices(size, expected, res2);
}

/**
 * Tests multiplying zero matrices and verifying that 
 * result is 0, despite result initially containing some data.
 * 0 * 0 = 0
 */
TEST(MatrixTest, AssertResultIndependentOfPriorData)
{
  // Arrange
  constexpr size_t dim = 3;
  constexpr size_t size = dim * dim;
  double Zero[size] = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
  };

  double expected[size] = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
  };

  // Act
  // Initialize result to non 0.
  double result[size] = { 123 };
  gemm(static_cast<int>(dim), result, Zero, Zero);

  // Assert
  compare_matrices(size, expected, result);
}

/**
 * Tests no writes are done out of bounds, which could cause a crash
 */
TEST(MatrixTest, AssertNoWriteOutOfBounds)
{
  // Arrange
  double A[1] = { 3 };
  double B[1] = { 4 };

  double expected[4] = {
    12, 111,
    222, 333,
  };

  // Act
  double result[4] {
    0, 111,
    222, 333
  };
  gemm(1, result, A, B);

  // Assert
  compare_matrices(4, expected, result);

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
