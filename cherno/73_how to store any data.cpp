/* https://www.youtube.com/watch?v=7nPrUBNGRAk

// How to store any data in a variable, without a void pointer
// Safer way in C++17
> std::any

*/

#include <iostream>
#include <any>
#include <string>

int main()
{
    std::any input; // make_any can be used to construct
    input = "Something";
    input = std::string("Something else");
    input = 2;

    // casting any
    auto& s = std::any_cast<float&>(input); // if not possible, error would be thrown as a bad cast
    std::cout << "This was a number and now a string : " << s << std::endl;
    // std::variant is better as types are known, type safe
    // the way things are stored are different
    // variant is a type safe union
    // any has void pointer for large types (dynamically allocating memory), aligned union of all types for small types
    //
}
