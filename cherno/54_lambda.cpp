//https://www.youtube.com/watch?v=mWgmBBz0y8c&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=60&t=0s

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "C:\Users\RAHULDAMANI\CLionProjects\try2\dependencies\GLFW\include\GLFW\glfw3.h"

void ForEach_same(const std::vector<int>& v, void(*func)(int)) // this accepts a vector and a fucntion pointer
{
    for(auto i : v)
        func(i);
}

void ForEach_multiply(const std::vector<int>& v, const std::function<void(int)>& func) // this accepts a vector and a fucntion pointer
{
    for(auto i : v)
        func(i);
}

int main()
{
    int a = 5;
    std::vector<int> v1{1,2,3,4,5,2,1,3,2,3,2,};
    ForEach_same(v1,[](int i){std::cout<< "Value : " << i << std::endl;});
    ForEach_multiply(v1,[&a](int i){std::cout<< "Value : " << i*a << std::endl;});
    // to modify value passed by value
    ForEach_multiply(v1,[=](int i)mutable{a=10; std::cout<< "Value : " << i*a << std::endl;});
    // takes in all the values from outside the fucntion by value
//    ForEach_multiply(v1,[=](int i){std::cout<< "Value : " << i*a << std::endl;});
    // takes in all the values from outside the fucntion by refernce
//    ForEach_multiply(v1,[&](int i){std::cout<< "Value : " << i*a << std::endl;});
    // [] are used to capture things

    // find if use for lambda
    auto it1 = std::find_if(v1.begin(),v1.end(),[](int i){return i>3;});
    std::cout << *it1 << std::endl;
}



/*
 *
 *
 */

/*

Value : 1
Value : 2
Value : 3
Value : 4
Value : 5
Value : 2
Value : 1
Value : 3
Value : 2
Value : 3
Value : 2
Value : 5
Value : 10
Value : 15
Value : 20
Value : 25
Value : 10
Value : 5
Value : 15
Value : 10
Value : 15
Value : 10
Value : 10
Value : 20
Value : 30
Value : 40
Value : 50
Value : 20
Value : 10
Value : 30
Value : 20
Value : 30
Value : 20
4
 */
