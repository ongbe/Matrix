
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
Matrix<T>::~Matrix()
{
  // NVectors are managed, and we don't have dynamic memory, so no need to
  // free any resources.
}

template<class T>
int Matrix<T>::getDimension()
{
  return m_dimension;
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
ostream & operator<<(ostream &os, Matrix<T> const &obj)
{
  for(int i = 0; i < obj.m_dimension; ++i)
  {
    os << obj.m_data[i] << "\n";
  }

  os << "\n";

  return os;
}
