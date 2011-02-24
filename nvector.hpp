
template<class T>
NVector<T>::NVector()
{
  m_numElements = 0;
  m_data = NULL;
}

template<class T>
NVector<T>::NVector(int size)
{
  if(size < 0)
  {
    throw Exception("Size must be greater than zero");
  }

  m_numElements = size;
  m_data = new T[m_numElements];
  zero();
}

template<class T>
NVector<T>::NVector(const NVector &source)
{
  m_data = new T[source.m_numElements];
  m_numElements = source.m_numElements;

  for(int i = 0; i < source.m_numElements; ++i)
  {
    m_data[i] = source.m_data[i];
  }
}

template<class T>
NVector<T>::~NVector()
{
  delete [] m_data;
  m_numElements = 0;
}

template<class T>
void NVector<T>::setSize(int size)
{
  if(size < 0)
  {
    throw Exception("Size must be greater than zero");
  }

  m_numElements = size;
  delete [] m_data;
  m_data = new T[m_numElements];

  // Initialize the memory in case the user does something stupid
  for(int i = 0; i < m_numElements; ++i)
  {
    m_data[i] = T();
  }
}

template<class T>
void NVector<T>::zero()
{
  for(int i = 0; i < m_numElements; ++i)
  {
    m_data[i] = 0;
  }
}

template<class T>
bool NVector<T>::isZero() const
{
  for(int i = 0; i < m_numElements; ++i)
  {
    if(m_data[i] != 0)
    {
      return false;
    }
  }

  return true;
}

template<class T>
T & NVector<T>::operator[](int i) const
{
  if(i < 0 || i >= m_numElements)
  {
    throw Exception("Index out of bounds");
  }

  return m_data[i];
}

template<class T>
int NVector<T>::getSize() const
{
  return m_numElements;
}

template<class T>
NVector<T> NVector<T>::operator-(const NVector<T> &rhs) const
{
  NVector<T> temp(*this);

  // First, make sure the NVectors contain the same number of elements
  if(m_numElements != rhs.m_numElements)
  {
    throw Exception("Only NVectors of the same dimension can be subtracted");
  }

  // Loop through the elements and subtract em'
  for(int i = 0; i < m_numElements; ++i)
  {
    temp[i] -= rhs.m_data[i];
  }

  return temp;
}

template<class T>
T NVector<T>::operator*(const NVector<T> &rhs) const
{
  T sum = 0;

  // First, make sure the NVectors are the same dimension
  if(m_numElements != rhs.m_numElements)
  {
    throw Exception("Only the dot product of NVectors of the same dimension "
                    "can be computed");
  }

  for(int i = 0; i < m_numElements; ++i)
  {
    sum += m_data[i] * rhs.m_data[i];
  }

  return sum;
}

template<class T>
NVector<T> NVector<T>::operator-()const
{
  NVector<T> temp(*this);

  for(int i = 0; i < m_numElements; ++i)
  {
    temp[i] = -m_data[i];
  }

  return temp;
}

template<class T>
NVector<T> NVector<T>::operator+(const NVector<T> &rhs) const
{
  NVector<T> temp(*this);

  // First, make sure the NVectors contain the same number of elements
  if(m_numElements != rhs.m_numElements)
  {
    throw Exception("Only NVectors of the same dimension can be subtracted");
  }

  // Loop through the elements and subtract em'
  for(int i = 0; i < m_numElements; ++i)
  {
    temp[i] += rhs.m_data[i];
  }

  return temp;
}

template<class T>
NVector<T> & NVector<T>::operator=(const NVector<T> &rhs)
{
  // Clear this NVector
  delete [] m_data;
  m_numElements = rhs.m_numElements;
  m_data = new T[m_numElements];

  // Copy each of the components
  for(int i = 0; i < m_numElements; ++i)
  {
    m_data[i] = rhs.m_data[i];
  }

  return *this;
}

template<class T>
ostream & operator<<(ostream &os, NVector<T> const &obj)
{
  os << "<";

  for(int i = 0; i < obj.m_numElements; ++i)
  {
    os << obj.m_data[i];

    if(i < obj.m_numElements-1)
    {
      os << ", ";
    }
  }

  os << ">";

  return os;
}

template<class T>
istream & operator>>(istream &is, NVector<T> &obj)
{
  for(int i = 0; i < obj.m_numElements; ++i)
  {
    is >> obj.m_data[i];
  }

  return is;
}
