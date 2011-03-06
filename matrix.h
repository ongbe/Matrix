/**
  @author Elliott Kopp
  @file matrix.h
  @date 3/6/2011
  @brief The definition of the Matrix class
*/

// #### DOCUMENTATION ####

/**
  @class Matrix
  @brief A class representing a Matrix.  Only square matricies supported.
*/

/**
  @fn friend operator<<
  @brief Prints the Matrix to an ostream
  @return A reference to the modified ostream
  @pre none
  @post os is modified to contain the Matrix
*/

/**
  @fn friend operator>>
  @brief Reads a Matrix in from an istream
  @return A reference to the modified istream
  @pre The istream contains numeric characters only,
       The number of digits per line is m_dimension
  @post m_data is filled with the values from the istream,
        the values are removed from the istream
*/

/**
  @fn friend operator*
  @brief  Performs scalar multiplication with an int on the LHS of the Matrix
  @return A copy of the scaled Matrix
  @pre none
  @post none
*/

/**
  @fn Matrix
  @brief The default ctor
  @return nothing
  @pre nothing
  @post m_dimension = 0, m_data = NULL
*/

/**
  @fn Matrix
  @brief Copy ctor
  @return nothing
  @pre nothing
  @post this Matrix is a copy of source
*/

/**
  @fn Matrix
  @brief ctor
  @return nothing
  @pre Passed dimension >= 0
  @post m_dimension = dimension,
        m_data is initialized to NVector of NVectors of size dimension
  @throw <Exception> {Dimension must be greater than zero}
*/

/**
  @fn ~Matrix
  @brief Destructor
  @return nothing
  @pre nothing
  @post All memory is freed (via managed objects)
*/

/**
  @fn getDimension
  @brief Gets the dimension of the Matrix
  @return int - the dimension of the Matrix
  @pre none
  @post none
*/

/**
  @fn setDimension
  @brief Sets the dimension of the Matrix
  @return void
  @pre dimension >= 0
  @post m_dimension = dimension,
        all data in m_data lost, new resources allocated
  @throw <Exception> {Dimension must be greater than zero}
*/

/**
  @fn operator[]
  @brief Gets the specified NVector that contains the row
  @return NVector - the row in the Matrix
  @pre i >= 0 and i < m_dimension
  @post none
  @throw <Exception> {Index out of bounds}
*/

/**
  @fn operator~
  @brief Returns the transpose of the Matrix
  @return A copy of a Matrix
  @pre none
  @post none
*/

/**
  @fn operator+
  @brief Performs Matrix addition
  @return A copy of a Matrix that is the sum of this + rhs
  @pre this and rhs are the same dimension
  @post none
  @throw <Exception> {The matricies must be the same dimension for addition}
*/

/**
  @fn operator-
  @brief Performs Matrix subtraction
  @return A copy of a Matrix that is the difference of this - rhs
  @pre this and rhs are the same dimension
  @post none
  @throw <Exception> {The matricies must be the same dimension for subtraction}
*/

/**
  @fn operator*
  @brief Performs Matrix/Matrix multiplication
  @return A copy of a Matrix that is the product of this * rhs
  @pre this and rhs are the same dimension
  @post none
  @throw <Exception> {The matricies must be the same dimension for
                      multiplication}
*/

/**
  @fn operator*
  @brief Performs Matrix scalar multiplication where an int is on the rhs
  @return A copy of a Matrix that is the product of this * rhs
  @pre none
  @post none
*/

/**
  @fn operator*
  @brief Performs Matrix/Vector multiplication
  @return A copy of a Matrix that is the product of this * rhs
  @pre this and rhs are the same dimension
  @post none
  @throw <Exception> {The matrix and vector must be the same dimension for
                      multiplication}
*/

/**
  @fn operator-
  @brief Negates all values in the Matrix
  @return A copy of a Matrix that is the product of this*-1
  @pre none
  @post none
*/


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

// Defined so scalar multiplication can be in the form scalar*matrix
template<class T>
Matrix<T> operator*(const int &lhs, const Matrix<T> &rhs);

template<class T>
class Matrix
{
  // friend functions should be declared outside of visibility sections
  friend ostream & operator<< <>(ostream &os, Matrix<T> const &obj);
  friend istream & operator>> <>(istream &is, Matrix<T> &obj);
  friend Matrix<T> operator* <>(const int &lhs, const Matrix<T> &rhs);

private:
  int m_dimension;
  NVector<NVector<T> > m_data;

public:
  Matrix();
  Matrix(const Matrix<T> &source);
  Matrix(int dimension);
  ~Matrix() {}; // Yay for managed codez!
  int getDimension() const;
  void setDimension(int dimension);

  // Operator overloads
  NVector<T> &operator[](int i) const;
  Matrix<T> operator~() const;  // Transpose
  Matrix<T> operator+(const Matrix<T> &rhs) const;
  Matrix<T> operator-(const Matrix<T> &rhs) const;
  Matrix<T> operator*(const Matrix<T> &rhs) const;
  Matrix<T> operator*(const int &rhs) const;
  NVector<T> operator*(const NVector<T> &rhs) const;
  Matrix<T> operator-() const;
};


#include "matrix.hpp"

#endif // MATRIX_H_INCLUDED
