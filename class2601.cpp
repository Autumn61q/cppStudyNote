// A member function can invoke another member function on the
// implicit parameter without using the dot notation.
void Employee::print() const
{
cout << "Name: " << get_name()
<< "Salary: " << get_salary()
<< "\n";
}

// A type alias is a synonym for another type.
// • Simplify complicated type
// • Emphasize the purpose
class Matrix {
typedef std::vector<std::vector<double>> Value;//把这个二维double类型的vector命名为value
};
class Account {
typedef double Money;
};
// • You can also use “’using”
class Matrix {
using Value = std::vector<std::vector<double>>;
};
class Account {
using Money = double;
};

// Inline Functions
// • An inline function is expanded in line at each call to avoid the
// overhead of function calls.
inline int Time::get_seconds() const {
return sec;
}
// • If the function is called
Time t;
std::cout << t.get_seconds() << std::endl;
// • (probably) be replaced by the compiler with
std::cout << t.sec << std::endl;
// • inline member functions have to be defined in the header file.

// File Structures
// • When your code gets large or you work in a team, you will want
// to split your code into separate source files.
// • Saves time: instead of recompiling the entire program, only
// recompile files that have been changed.
// • Group work: separate programmers work on separate files.

// • The header file (e.g. product.h) contains:
// • definitions of constants
// • definitions of classes
// • declarations of nonmember functions
// • declarations of global variables

// • The source file (e.g. product.cpp) contains:
// • definitions of member functions
// • definitions of nonmember functions
// • definitions of global variables

// Order of Includes
// • It is suggested to follow a specific order of include headers.
// • Google C++ style guide:
// • related header
// • system headers
// • standard libraries
// • others

// • Example
product.cpp:
#include "product.h"
#include <string>
#include <vector>
#include "util.h"
