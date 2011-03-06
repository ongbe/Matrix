/**
  @author Elliott Kopp
  @file gauss.hpp
  @date 3/6/2011
  @brief The implementation of the Matrix class
*/

template<class T>
void Gauss<T>::swap(T &val1, T &val2) const
{
  T temp = val1;
  val1 = val2;
  val2 = temp;
  return;
}

/// pre-condition = square matrix
template<class T>
NVector<T> Gauss<T>::operator()(const Matrix<T> &A, const NVector<T> &b) const
{
  int n = A.getDimension(), maxRow = 0;
  double max = 0;
  T multiple = 0;
  NVector<T> x(n), s(n);  // s = max(each row in a)
  Matrix<T> a(A);

  if(n != b.getSize())
  {
    throw Exception("The matrix and vector must be the same dimension");
  }

  if(A.getDimension() == 0)
  {
    return NVector<T>(0);
  }
  else if(A.getDimension() == 1)
  {
    NVector<T> temp(1);
    temp[0] = A[0][0];
    return temp;
  }

  // First, form our s vector
  for(int i = 0; i < n; ++i)
  {
    s[i] = fabs(a[i][0]);

    for(int j = 1; j < n; ++j)
    {
      if(fabs(a[i][j]) > s[i])
        s[i] = fabs(a[i][j]);
    }
  }

  for(int i = 0; i < n-1; ++i)  // current row/column
  {
    max = 0;

    // Do scaled partial pivoting (swap rows)
    for(int k = i; k < n; ++k)
    {
      if(fabs(a[k][i])/s[k] > max)
      {
        max = fabs(a[k][i])/s[k];
        maxRow = k;
      }
    }

    if(maxRow != i)
    {
      // swap the rows in A, b, and s
      swap(b[i], b[maxRow]);
      swap(s[i], s[maxRow]);

      for(int k = i; k < n; ++k)
        swap(a[i][k], a[maxRow][k]);
    }

    // forward elimination
    for(int j = i+1; j < n; ++j)
    {
      multiple = -(a[j][i]/a[i][i]);

      for(int k = i; k < n && multiple != 0; ++k)
      {
        // compute for a
        a[j][k] = multiple*a[i][k]+a[j][k];

        if(fabs(a[j][k]) < FLOAT_TOL)
          a[j][k] = 0;
      }

      // compute for b
      b[j] = multiple*b[i]+b[j];

      if(fabs(b[j]) < FLOAT_TOL)
        b[j] = 0;
    }
  }

  // Backwards substitution
  for(int i = n-1; i > 0; --i)
  {
    for(int j = i-1; j >= 0; --j)
    {
      multiple = -(a[j][i]/a[i][i]);

      for(int k = n-1; k > j; --k)
      {
        a[j][k] = multiple*a[i][k]+a[j][k];

        if(fabs(a[j][k]) < FLOAT_TOL)
          a[j][k] = 0;
      }

      // compute for b
      b[j] = multiple*b[i]+b[j];

      if(fabs(b[j]) < FLOAT_TOL)
        b[j] = 0;
    }
  }

  // Now put into reduced REF by scaling each row to 1 in the pivot
  for(int i = 0; i < n; ++i)
  {
    b[i] = b[i]/a[i][i];
    a[i][i] /= a[i][i];
  }

  return b;
}

