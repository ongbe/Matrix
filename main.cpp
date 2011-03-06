#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
#include "matrix.h"
#include "gauss.h"
#include "exception.h"
using namespace std;

template<class T>
void readInput(Matrix<T> &A, NVector<T> &b, char* filename);


int main(int argc, char *argv[])
{
  Matrix<double> A;
  NVector<double> b;
  Gauss<double> g;

  try
  {
    readInput(A, b, "F:\\Programming\\CS328\\Matrix\\input.txt");

    cout << "A:\n" << A << "~A (transpose):\n" << ~A;
    cout << "A * ~A:\n" << A * ~A << "\n";
    cout << "b:\n" << b << "\n\n";
    cout << "x (answer):\n" << g(A,b) << "\n\n";
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
