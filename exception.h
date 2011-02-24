#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <string>
using std::string;


/**
  @fn Exception
  @brief The default ctor
  @return nothing
  @pre nothing
  @post m_message is blank
*/

/**
  @fn Exception
  @brief Initializing ctor
  @return nothing
  @pre nothing
  @post m_message is initialized to the passed string
*/

/**
  @fn message
  @brief Returns the error message
  @return m_message
  @pre nothing
  @post nothing
*/


/**
  @class Exception
  @brief A simple Exception class containing an error message
*/
class Exception
{
private:
  string m_message;

public:
  Exception() { m_message = ""; }
  Exception(string message) { m_message = message; }
  string message() { return m_message; }
};

#endif // EXCEPTION_H_INCLUDED
