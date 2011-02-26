
template<class T>
Matrix<T>::Matrix()
{
  m_dimension = 0;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> &source)
{
  int size = source.getDimension();
  m_data.setSize(size);

  for(int i = 0; i < size; ++i)
  {
    m_data[i].setSize(size);
  }

  // Perform deep copy
  for(int i = 0; i < size; ++i)
  {
    m_data[i] = source[i];
  }
}

template<class T>
Matrix<T>::Matrix(int dimension)
{
  if(dimension < 0)
  {
    throw Exception("Dimension must be greater than zero");
  }

  m_dimension = dimension;
  m_data.setSize(dimension);

  for(int i = 0; i < dimension; ++i)
  {
    m_data[i].setSize(dimension);
  }
}

template<class T>
int Matrix<T>::getDimension() const
{
  return m_dimension;
}

template<class T>
void Matrix<T>::setDimension(int dimension)
{
  if(dimension < 0)
  {
    throw Exception("Dimension must be greater than zero");
  }

  m_dimension = dimension;
  m_data.setSize(dimension);

  for(int i = 0; i < m_dimension; ++i)
  {
    m_data[i].setSize(m_dimension);
  }

  return;
}

template<class T>
NVector<T> &Matrix<T>::operator[](int i) const
{
  if(i < 0 || i >= m_dimension)
  {
    throw Exception("Index out of bounds");
  }

  return m_data[i];
}

template<class T>
Matrix<T> Matrix<T>::operator~() const
{
  Matrix<T> transpose(m_dimension);

  for(int i = 0; i < m_dimension; ++i)
  {
    for(int j = 0; j < m_dimension; ++j)
    {
      transpose[i][j] = m_data[j][i];
    }
  }

  return transpose;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
  Matrix<T> temp(rhs.getDimension());

  if(rhs.getDimension() != m_dimension)
  {
    throw Exception("The matricies must be the same dimension for "
                    "addition");
  }

  for(int i = 0; i < m_dimension; ++i)
  {
    for(int j = 0; j < m_dimension; ++j)
    {
      temp[i][j] = m_data[i][j] + rhs[i][j];
    }
  }

  return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
  if(m_dimension != rhs.getDimension())
  {
    throw Exception("The matricies must be the same dimension for "
                    "subtraction");
  }

  return (*this + -rhs);  // Clever no?
}


/// TODO: pre-condition of square matricies
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const
{
  Matrix<T> temp(rhs.getDimension());

  if(m_dimension != rhs.getDimension())
  {
    throw Exception("The matricies must be the same dimension for "
                    "multiplication");
  }

  for(int i = 0; i < m_dimension; ++i)
  {
    for(int j = 0; j < m_dimension; ++j)
    {
      for(int k = 0; k < m_dimension; ++k)
      {
        temp[i][j] += m_data[i][k]*rhs[k][j];
      }
    }
  }

  return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator-() const
{
  Matrix<T> temp(m_dimension);

  for(int i = 0; i < m_dimension; ++i)
  {
    for(int j = 0; j < m_dimension; ++j)
    {
      // Technically a -0 works fine with everything, but for output a -0
      // doesn't look so good, so just avoid it all together.
      if(m_data[i][j] != 0)
        temp[i][j] = -m_data[i][j];
    }
  }

  return temp;
}

template<class T>
ostream & operator<<(ostream &os, Matrix<T> const &obj)
{
  for(int i = 0; i < obj.m_dimension; ++i)
  {
    os << obj.m_data[i] << "\n";
  }

  os << "\n";

  return os;
}

template<class T>
istream & operator>>(istream &is, Matrix<T> &obj)
{
  double temp = 0;

  for(int i = 0; i < obj.m_dimension; ++i)
  {
    for(int j = 0; j < obj.m_dimension; ++j)
    {
      is >> temp;
      obj.m_data[i][j] = static_cast<T>(temp);
    }
  }

  return is;
}
