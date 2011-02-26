#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include "nvector.h"
#include "exception.h"
using namespace std;

template<class T>
class Matrix;

template<class T>
ostream & operator<<(ostream &os, Matrix<T> const &obj);

template<class T>
istream & operator>>(istream &is, Matrix<T> &obj);


template<class T>
class Matrix
{
  // friend functions should be declared outside of visibility sections
  friend ostream & operator<< <>(ostream &os, Matrix<T> const &obj);
  friend istream & operator>> <>(istream &is, Matrix<T> &obj);

private:
  int m_dimension;
  NVector<NVector<T> > m_data;

public:
  Matrix();
  Matrix(const Matrix<T> &source);
  Matrix(int dimension);
  ~Matrix() {};
  int getDimension() const;
  void setDimension(int dimension);

  // Operator overloads
  NVector<T> &operator[](int i) const;
  Matrix<T> operator~() const;  // Transpose
  Matrix<T> operator+(const Matrix<T> &rhs) const;
  Matrix<T> operator-(const Matrix<T> &rhs) const;
  Matrix<T> operator*(const Matrix<T> &rhs) const;
  Matrix<T> operator-() const;
};


#include "matrix.hpp"

#endif // MATRIX_H_INCLUDED
