/**
  @author Elliott Kopp
  @file main.cpp
  @date 3/6/2011
  @brief The driver for hw4
*/

#include <fstream>
#include <cstdlib>
#include "matrix.h"
#include "gauss.h"
#include "exception.h"
using namespace std;

/**
  @fn readInput
  @brief Reads a matrix and a vector in from a file
  @pre filename exists and has read permissions,
       filename is a well-formed valid input file
  @post A and b are modified to hold the contents of the file
  @return void
  @throw <Exception> {File "filename" could not be opened.}
*/
template<class T>
void readInput(Matrix<T> &A, NVector<T> &b, char* filename);


int main(int argc, char *argv[])
{
  Matrix<double> A;
  NVector<double> b;
  Gauss<double> g;

  if(argc != 2)
  {
    cout << "Please specify an input file to use.\nExample:\n";
    cout << "\t./driver input.txt\n\n";
    return 1;
  }

  try
  {
    readInput(A, b, argv[1]);

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
    throw Exception("File \"" + string(filename) + "\" could not be opened.\n");
  }

  getline(myfile, buffer);
  dimension = atoi(buffer.c_str());
  A.setDimension(dimension);
  b.setSize(dimension);

  myfile >> A;
  myfile >> b;

  myfile.close();
}
