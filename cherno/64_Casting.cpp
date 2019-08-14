/*
 * https://www.youtube.com/watch?v=CiHfz6pTolQ&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=74&t=2s
 * The Cherno
 * > Casting
 * > type conversion
 * > implicit conversion : when conversion is easy and known by c++
 * > explicit conversion : when user says to do so
 *      > c style and c++ style casting
 *      >
 *
 */



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
    // implicit
    int a  = 5;
    double b = a; // this case, a is converted as double implicitly and nothing has to be said in particular to carryout that activity
    std::cout << "A was : " << a << '\n';
    std::cout << "B was casted to : " << b << '\n';

    double b1 = 5.4;
    int a1  = b1;
    std::cout << "b1 was : " << b1 << '\n';
    std::cout << "a1 was casted to : " << a1 << '\n';


    // explicit
    int c1 = (int)b1; // c type
    std::cout << "C1 was casted to explicitly in c style: " << c1 << '\n';

    int c2 = static_cast<int>(b1);
    std::cout << "C2 was casted to explicitly in c++ style: " << c2 << '\n';

    // dynamic cast, const cast, reinterpret_cast <- they are like c style and a little bit more, like run time checking
    // but these are syntactical sugar
    // extra things like check and returns null but slows it a bit down
    // reinterpret doesn change the type, just points and uses it like some other type
    // const is for removing and adding const
    // and these cast are searchable in search base, since they are named and unlike c style which are not





}

/*
 * OUTPUT
A was : 5
B was casted to : 5
b1 was : 5.4
a1 was casted to : 5
C1 was casted to explicitly in c style: 5
C2 was casted to explicitly in c++ style: 5
 */