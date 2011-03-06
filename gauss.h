/**
  @author Elliott Kopp
  @file gauss.h
  @date 3/6/2011
  @brief The definition of the Gauss class
*/

#ifndef GAUSS_H_INCLUDED
#define GAUSS_H_INCLUDED

#include "matrix.h"
#include "nvector.h"
#include "exception.h"
#include <cmath>

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
