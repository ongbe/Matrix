#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
#include "matrix.h"
#include "exception.h"
using namespace std;

template<class T>
void readInput(Matrix<T> &A, NVector<T> &b, char* filename);


int main(int argc, char *argv[])
{
  const int dimension = 3;
  Matrix<double> A, x(dimension), y(dimension);
  NVector<double> b, c(dimension);

  try
  {
    readInput(A, b, "c:\\users\\lunchbox\\desktop\\Matrix\\input.txt");

    //cout << A << "\n" << b << "\n\n";

    for(int i = 0; i < dimension; ++i)
    {
      for(int j = 0; j < dimension; ++j)
      {
        x[i][j] = rand() % 10;
        y[i][j] = rand() % 10;
      }
    }

    cout << x << "\n\n" << x*3 << "\n\n";
  }
  catch(Exception &e)
  {
    cout << e.message();
  }

  return 0;
}

template<class T>
void readInput(Matrix<T> &A, NVector<T> &b, char* filename)
{
  int dimension = 0;
  string buffer;
  ifstream myfile(filename);

  if(!myfile.is_open())
  {
    cout << "File \"" << filename << "\" could not be opened.\n";
    return;
  }

  getline(myfile, buffer);
  dimension = atoi(buffer.c_str());
  A.setDimension(dimension);
  b.setSize(dimension);

  myfile >> A;
  myfile >> b;

  myfile.close();
}
