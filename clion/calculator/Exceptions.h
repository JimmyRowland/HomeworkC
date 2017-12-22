//
// Created by toor on 4/11/17.
//

#ifndef CALCULATOR_EXCEPTIONS_H
#define CALCULATOR_EXCEPTIONS_H
#include <iostream>
#include <exception>
using namespace std;
namespace cs20a{
class UnbalancedParenthesesException: public logic_error
{
public:
    using logic_error::logic_error;
    virtual const char* what() const throw()
    {
        return "Unbalanced Parentheses Found";
    }
};
class InvalidCharactersException: public logic_error
{
public:
    using logic_error::logic_error;
    virtual const char* what() const throw()
    {
        return "Invalid Characters Found";
    }
};
class DivideByZeroException: public logic_error
{
public:
    using logic_error::logic_error;
    virtual const char* what() const throw()
    {
        return "Division by zero attempted";
    }
};
}
#endif //CALCULATOR_EXCEPTIONS_H
