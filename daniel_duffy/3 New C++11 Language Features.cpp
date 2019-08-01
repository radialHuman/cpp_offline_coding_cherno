/* Daniel Duffy
 * https://quantnet.com/media/categories/level-1-videos.12/
 * nullptr
 * no macro, type safe, used to check if something is really null or not NULL or 0 or undefined
 *
 * Static assert
 * used to check something at compile time
 * works only with static const expression
 * checks for a condition and displays message passed when it fails
 *
 * Decltype
 * check the type of expression
 * can be used in template when the parameters are of different types and trailing can be used to mention the return type
 * detects whats the type and can be used instead as type for another variable
 * Wrapping function
 *
 * Rvalue and lvalue
 * every expression is either r or l value
 * lvalue is persistent beyond the single expression, has memory and can be altered (const is an exception)
 * like : int x; y ; arr[10]; ++x;
 * lvalue cant be bound to rvalue references
 * rvalue is temporary and disappears beyond expression, doesn occupy memory
 * like : 3.14, x+y; x++; std::string("Hello")
 * rvalue can only be bound to non-const references
 *
 * universal reference (&&)
 * rvalue reference are eligible for move function
 *
 * Move semantic    ???
 *
 * constexpr
 * expression will be executed during the compile time
 *
 * Noexcept
 * for a fucntion which is not ready for exeptions , placed after ()
 * if they throw error, std::terminate and std::abort will take place
 * it optimizes as there wont be any stack unwinding
 * used for generic as error type wont be known before hand
 *
 * Uniform initialization
 * there are many ways, but to make one way which can be std
 *
 * INitalizaer list
 *
 * Variadic template
 * uses recurssion technique of calling one arg and then the rest using the same function
 * used to send multiple parameters for same type to a template
 *
 * ALias template
 * previously typedef cant be used for templates
 * using the keyword "using"
 *
 * Move semantics
 * avoids unnecessary copies and temporaries
 * differentiates between copyable and movable classes
 * and rvalue and lvalue
 *
 * ???
 *
 */




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <typeinfo>

// rvalue example
int MutableRValue()
{
    return 3;
}

// const rvalue example
const int ConstRValue()
{
    return 3;
}

// creating mutable lvalue
double mutableLvalue = 2.12;

// creating const lvalue
const double constLvalue = 2.12;

// alias template
template <class T>
using vec = std::vector <T>;


int main()
{
    int a{10};
    double b{10.2};
    decltype(a*b) c{10}; // makes c a double
    std::cout << c << typeid(c).name() << std::endl;

    //  using alias template
    vec<int> v1{1,2,3,4,5};
    std::cout << std::accumulate(v1.begin(), v1.end(),0) << std::endl;


}

/*
 * OUTPUT
10d
16
 */
