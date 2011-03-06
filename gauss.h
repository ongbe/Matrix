/**
  @author Elliott Kopp
  @file gauss.h
  @date 3/6/2011
  @brief The definition of the Gauss class
*/


// #### DOCUMENTATION ####

/**
  @fn swap
  @brief Swaps two values
  @return void
  @pre none
  @post The two values are swapped in memory
*/

/**
  @fn operator()
  @brief Performs gaussian elimination with scaled partial pivoting to solve
         the equation Ax=b
  @return NVector - the x vector that is the solution to the equation Ax=b
  @pre A and b are the same dimension,
       A is square
  @post none
  @throw <Exception> {The matrix and vector must be the same dimension}
*/


#ifndef GAUSS_H_INCLUDED
#define GAUSS_H_INCLUDED

#include "matrix.h"
#include "nvector.h"
#include "exception.h"
#include <cmath>

// Values with an abs. val. of < FLOAT_TOL are considered exactly 0
#define FLOAT_TOL .00000001
using namespace std;

template<class T>
class Gauss
{
private:
  void swap(T &val1, T &val2) const;

public:
  NVector<T> operator()(const Matrix<T> &A, const NVector<T> &b) const;
};

#include "gauss.hpp"

#endif // GAUSS_H_INCLUDED
