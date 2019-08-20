# [Scott Meyers - Effective Modern C++](https://www.youtube.com/watch?v=fhM24zs1MFA&list=PLmxXlAVb5hkyq5njldMEPYdOqTAQPLChR "Scott Meyers - Effective Modern C++")
 * Modern C++ means C++98/03 + C++11 + C++14
 ## **Agenda**
 1. lvalue and rvalue
 1. type deduction
 1. std::move and std::forward
 1. auto
 1. auto + {expr} => std::initializer_list
 1. universal reference and rvalue reference
 1. pass and return rvalue reference via std::move and universal reference via std::forward
 1. reference collapsing
 1. default capture mode
 1. make const member function thread-safe
 > ## Part 1 
 * Many things in modern c++ revolves around rvalues and lvalues
 * *__lvalue__*: 
    * Not permitted to be moved from, because it can have more than 1 way to access that variable.
    * If something moves it, other parts fo the program would detect that.
    * It is a named object and accessible by a pointer or reference
    * Generally, if you it has an address, it is lvalue
 * *__rvalue__*: 
    * Everything thats not a lvalue is a rvalue
    * May be moved from
    * Candidate for move operation to optimize by moving than copying
    * Accessible only at one point in the source code
    * Usually, unnamed temp objects, which cant have pointers or references
    * All inbuilt numeric literals are rvalue

 ``` cpp
    #include <iostream>
    #include <vector></vector>

    template <typename T1, typename T2>
    int diff(const T1& c1, const T2& c2)
    {return c1.size() - c2.size();}

    // diff, c1, c2 are lvalue
    // return value is rvalue
    
    int main()
    {
        int i = 10; // i is lvalue, 10 is rvalue
        i++; // is a 
        std::cout << 100 << std::endl; // 100 is rvalue
        return 0; // r value

        int *p;  // lvalue, cant be moved from only copied
        std::vector<int> v1;
        std::unordered_set<int> s;

        *p = diff(v1,s); // the part post "=" is rvalue
    }
 ```
   
 
