/*
 Daniel Duffy
 * https://quantnet.com/media/categories/level-1-videos.12/
 * Advanced Language Features
 * > variadic
 * > STL bind
 * > STL algorithms and containers
 *
 * VARIADIC
 * > Like variable arguments (var args)
 * > Used to be seperately handlelled
 * > Template variadic
 * > template <typename T1, typename... T2> // called a template parameter pack
 * > Can be done for functions also
 * > void function(const T1& arg, const T2&... arg) // function parameter pack
 * > Called as : arg... // recursively
 *
 * CURRYING
 * > reducing function to a function with partial value defined
 * > f(x,y) -> f(2,y) => f(2,3) // finxing one of the argument
 * > gives higher order fucntions , can return and accept fucntions
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <typeinfo>
#include <string_view>

template <typename T1, typename ... T2>
void display(const T1& arg, const T2& ... args )
{
    std::cout << "The first argument is : " << arg << std::endl;
//    display(args ...); // ?? not working
}

int main()
{
    // variadic
    int s = 10;
    display(s, "Something" ,"was" ,"here.");


    // partial fucntion using currying

}

/*
 * OUTPUT

 */
