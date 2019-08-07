/*
 * https://www.youtube.com/watch?v=M_Mrk1xHMoo
 *
 * RECURSIVE LAMBDA
 * > Pass the function as parameter
 * > Or else it wont recognize
 *
 */

// lambda function
constexpr auto fib_ = [](const auto fib,int input){
    if(input < 2 )
    {
        return(1);
    }
    return(fib(fib,input-1)+fib(fib,input-2));
};

// to make things look better
constexpr auto fib = [](int input){
    return fib_(fib_,input);
};

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <typeinfo>
#include <string_view>
#include <random>

int main()
{
    std::cout << "Fiboinacci for 0 is :" <<fib_(fib_,0) << '\n';
    std::cout << "Fiboinacci for 1 is :" <<fib_(fib_,1) << '\n';
    std::cout << "Fiboinacci for 2 is :" <<fib_(fib_,2) << '\n';
    std::cout << "Fiboinacci for 3 is :" <<fib_(fib_,3) << '\n';
    std::cout << "Fiboinacci for 4 is :" <<fib_(fib_,4) << '\n';
    std::cout << "Fiboinacci for 5 is :" <<fib_(fib_,5) << '\n';
    std::cout << "Fiboinacci for 10 is :" <<fib(10) << '\n';
    std::cout << "Fiboinacci for 11 is :" <<fib(11) << '\n';
    std::cout << "Fiboinacci for 12 is :" <<fib(12) << '\n';
    std::cout << "Fiboinacci for 13 is :" <<fib(13) << '\n';
    std::cout << "Fiboinacci for 14 is :" <<fib(14) << '\n';
    std::cout << "Fiboinacci for 15 is :" <<fib(15) << '\n';

    // ??? mutually recursive fucntions 
}

/*
 * OUTPUT
Fiboinacci for 0 is :1
Fiboinacci for 1 is :1
Fiboinacci for 2 is :2
Fiboinacci for 3 is :3
Fiboinacci for 4 is :5
Fiboinacci for 5 is :8
Fiboinacci for 10 is :89
Fiboinacci for 11 is :144
Fiboinacci for 12 is :233
Fiboinacci for 13 is :377
Fiboinacci for 14 is :610
Fiboinacci for 15 is :987
 */