/* https://www.youtube.com/watch?v=fj_CF8xK760
 *
 * String view
 * gets a view inside the string
 */




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <typeinfo>
#include <string_view>

std::size_t getLength(const std::string& s)
{
    return s.size();
}

std::size_t getLength_view(const std::string_view & s)
{
    return s.size();
}

int main()
{
    // to get the length of the string back
    std::cout << getLength("something is being passed") << std::endl;
    // for long wors compiler might not be able to optimize
    std::cout << getLength_view("something is being passed") << std::endl;
    // string view doesn do any allocation, just has pointer pointed to beginning and the end of the string
    // this almost has every function that can be applied to a string
    // also its a constexpr usable expression

}

/*
 * OUTPUT
25
 */