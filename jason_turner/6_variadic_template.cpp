//https://www.youtube.com/watch?v=o1EvPhz6UNE

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// variadic template is used to create a template that works not only for any type of variable but also
// for any number of variables passed to it
// template to convert anything to string

template <class T>
std::string to_string(const T& x)
{
    std::stringstream ss;
    ss << x;
    return ss.str();
}

// zeroth case for variadic template
std::vector<std::string> to_string_variadic(){
    return{};
}

template <class t1,class ... T> // ... is to show its variadic, and it has atleast one parameter
std::vector<std::string> to_string_variadic(const t1& x, const T& ... y)
{
    std::vector<std::string> ss;
    ss.push_back(to_string(x));

    // for the rest of the parameters
    const auto remaining = to_string_variadic(y...); // but this will need a zeroth case
    ss.insert(ss.end(),remaining.begin(),remaining.end());
    return ss;
}



int main()
{
    std::cout << to_string(123) << std::endl;
    std::cout << to_string("123") << std::endl;

    // to convert a list of elements
    const auto vec = to_string_variadic(32,"something",38.12);
    for(const auto i : vec)
    {
        std::cout << i << std::endl;
    }

}

/*
 * OUTPUT
123
123
32
something
38.12
 */
