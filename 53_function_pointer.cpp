//https://www.youtube.com/watch?v=p4sDgQ-jao4&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=59&t=0s

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void function()
{
    std::cout << "Something!\n";
}

void function2(int q)
{
    std::cout << q << std::endl;
}


void forAll(const std::vector<int>& v, void(*func)(int)) // calling in fucntion2
{
    for (int i: v)
//        std::cout << i*3 << std::endl; // this can be done, but what is this can be done by passing in another function as if it is a variable
        func(i);
}

int main()
{
    // function pointer (raw from c)
    function();
    // this function can be assigned to a variable
    auto f1 = function; // this is a function pointer being passed to a variable, as it is not a function call
    // this is similar to auto f = &function, this gives the memory address of the function
    // this is the address of instructions passed by this function to the executable file
    f1();
    // type of this variable f is, with empty bracket for passing in parameters
    void(*anything)() = function; // to avoid assigning like this, use auto or typedef it
    anything();

    typedef void(*something)();
    something f2 = function;
    f2();

    // function that uses parameter
    auto f3 = function2;
    f3(5);

    typedef void(*something_else)(int);
    something_else f4 = function2;
    f4(8);

    // use case
    std::vector<int> v1{1,5,2,6,3,7,3,2};
    forAll(v1, function2); // fucntion with function as parameter

}




/*

 Something!
Something!
Something!
Something!
5
8
1
5
2
6
3
7
3
2


 */