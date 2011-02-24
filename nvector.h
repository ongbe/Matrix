#ifndef NVECTOR_H_INCLUDED
#define NVECTOR_H_INCLUDED

#include "exception.h"
using namespace std;



/**
  @fn operator<<
  @brief Outputs the NVector to a stream (i.e. <x1 x2 ... xn>)
  @return A reference to the ostream
  @pre none
  @post 'os' contains the output of the NVector
*/

/**
  @fn operator>>
  @brief Reads in an NVector from an istream
  @return A reference to the istream
  @pre The istream contains numeric characters only,
       The number of digits per line is m_numElements
  @post m_data[0...m_numElements-1] is filled with the values from the istream,
        the values are removed from the istream
*/


/**
  @fn zero
  @brief Gives all the values in m_data a value of 0
  @return nothing
  @pre type T is a numeric type
  @post m_data[0...n] takes on a value of 0
*/

/**
  @fn NVector
  @brief Default ctor
  @return nothing
  @pre nothing
  @post m_numElements = 0, m_data = NULL
*/

/**
  @fn NVector
  @brief Initializing ctor
  @return nothing
  @pre size >= 0
  @post m_numElements = size, m_data[0...n] is initialized
  @throw <Exception> {Size must be greater than zero}
*/

/**
  @fn NVector
  @brief Copy ctor
  @return nothing
  @pre none
  @post A deep copy of 'source' is made
*/

/**
  @fn ~NVector
  @brief Destructor
  @return nothing
  @pre nothing
  @post The NVector is deleted, all resources freed
*/

/**
  @fn setSize
  @brief Sets the size, or dimension, of the NVector
  @return void
  @pre 'size' >= 0
  @post Old data freed,
        m_numElements = size,
        m_data[0...size] allocated and initialized
  @throw <Exception> {Size must be greater than zero}
*/

/**
  @fn getSize
  @brief Gets the size, or dimension, of the NVector
  @return int - the size of the NVector
  @pre none
  @post none
*/

/**
  @fn isZero
  @brief Determines if the NVector is the zero vector
  @return A bool - true if all the components are 0, false otherwise
  @pre none
  @post none
*/

/**
  @fn operator[]
  @brief Accesses the elements of the NVector
  @return T - the i'th element in the NVector
  @pre 'i' is >= 0, 'i' is < the NVector's size
  @post nothing
  @throw <Exception> {Index out of bounds}
*/

/**
  @fn operator*
  @brief Computes the dot product of the two vectors
  @return A copy of an NVector
  @pre The * operator is defined for type T,
       "this" and rhs are the same dimension
  @post The returned value is the dot product
  @throw <Exception> {Only the dot product of NVectors of the same dimension
                      can be computed}
*/

/**
  @fn operator- (binary)
  @brief Performs vector subraction
  @return A copy of an NVector
  @pre The "-" operator is defined for type T,
       "this" and rhs are the same dimension
  @post The returned NVector is the result of vector subraction of this-rhs
  @throw <Exception> {Only NVectors of the same dimension can be subtracted}
*/

/**
  @fn operator- (unary)
  @brief Returns the reflection through the origin in n-space
  @return A copy of an NVector
  @pre The - operator is defined for type T
  @post none
*/

/**
  @fn operator+ (binary)
  @brief Performs vector addition
  @return A copy of an NVector
  @pre The + operator is defined for type T,
       "this" and rhs are the same dimension
  @post The returned NVector is the result of vector addition of this+rhs
  @throw <Exception> {Only NVectors of the same dimension can be added}
*/

/**
  @fn operator=
  @brief Performs assignment
  @return A reference to 'this' NVector
  @pre none
  @post A deep copy of rhs is made
*/


// Forward declaration required for friend declarations
template<class T>
class NVector;

template<class T>
ostream & operator<<(ostream &os, NVector<T> const &obj);

template<class T>
istream & operator>>(istream &is, NVector<T> &obj);

template<class T>
class NVector
{
  // friend functions must be declared outside of visibilty sections
  friend ostream & operator<< <>(ostream &os, NVector<T> const &obj);
  friend istream & operator>> <>(istream &is, NVector<T> &obj);

private:
  int m_numElements;  // The dimension of the NVector
  T *m_data;  // The elements themsevles
  void zero();

public:
  NVector();
  NVector(int size);
  NVector(const NVector &source);
  ~NVector();
  void setSize(int size);
  int getSize() const;
  bool isZero() const;

  // Operator overloads
  T & operator[](int i) const;
  T operator*(const NVector<T> &rhs) const;     // Dot product
  NVector<T> operator-(const NVector<T> &rhs) const;  // vector subtraction
  NVector<T> operator-() const;             // Unary (reflection through origin)
  NVector<T> operator+(const NVector<T> &rhs) const; // Binary (vector addition)
  NVector<T> & operator=(const NVector<T> &rhs);
};

#include "nvector.hpp"

#endif // NVECTOR_H_INCLUDED
