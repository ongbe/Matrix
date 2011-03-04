


/// pre-condition = square matrix
template<class T>
NVector<T> Gauss<T>::operator()(const Matrix<T> &A, const NVector<T> &b) const
{
  int n = A.getDimension();
  T multiple = 0;
  NVector<T> x(n);
  Matrix<T> a(A);


  if(n != b.getSize())
  {
    throw Exception("The matrix and vector must be the same dimension");
  }


  for(int i = 0; i < n-1; ++i)  // current row/column
  {
    // Divide each element in the current row by the pivot to get
    // 1 in the pivot position
    //for(int k = n-1; k >= i; --k)
    //{
    //  if(a[i][i] != 0)
    //  {
    //    a[i][k] = a[i][k]/static_cast<T>(fabs(a[i][i]));
    //  }
    //}


    cout << a << '\n';

    // forward substitution
    // currentrow[i] = multiple*pivotRow[i]+currentrow[i]
    for(int j = i+1; j < n; ++j)
    {
      multiple = -(a[j][i]/a[i][i]);
      for(int k = i; k < n; ++k)
      {
        double currentRowAtI = a[j][k]; /// TODO: cleanup
        double pivotRowAtI = a[i][k];
        double temp = multiple*a[i][k]+a[j][k];
        a[j][k] = temp;

        if(fabs(temp) < FLOAT_TOL)
          a[j][k] = 0;

        //cout << a << '\n';
      }
    }
  }

  cout << "\nFINAL:\n" << a << "\n\n";

  return x;
}

