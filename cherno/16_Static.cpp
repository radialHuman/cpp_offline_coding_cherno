/*
 * https://www.youtube.com/watch?v=f3FVU-iwNuA&t=15s
 * The Cherno
 * > Static on a variable/function makes it private to the transactional unit it is in
 * > if a global variable or a fucntion has to be accessed then it can use the "extern" keyword
 * > but this cant access the static variable
 *
 * in a class
 * > if a vriable is static, then there is only one such variable in all the instances of the class
 * >
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

struct entity
{
    int x,y;
    static int x1,y1;
    void print()
    {
        std::cout << x << "," << y <<std::endl;
    }

    static void s_print() // static method can access only static variables
    {
        std::cout << x1 << "," << y1 <<std::endl;
    }

};

int entity::x1;
int entity::y1;

int main()
{
    entity e{10,12};
    e.print();

    entity e2; // just this would give a undefined reference error so line above main is required
    e2.x1 = 1;
    e2.y1 = 0;


    entity e1; // just this would give a undefined reference error so line above main is required
    e1.x1 = 100;
    e1.y1 = 230;

    // this can rather be written like
    entity e3;
    entity::x1 = 10;
    entity::y1 = 20;
    e3.print();
    e2.print();
    e1.print();

    // should actually be called as
    entity::s_print();



    // first x and y will have 1 and 0, but since its static,it will have one value through out all the instances
    // this makes them point to the same value
    // and the last one will be chosen as the value when declared

    // a static method is like having a function outside the class and thus it cannot access the variables in the class
    // since menmber functions are just fucntions with hiddne parmeter or class instance, which static methods dont get

}

/*
 * OUTPUT
10,12
67,7543188
4200160,0
6487928,4200267
10,20
 */