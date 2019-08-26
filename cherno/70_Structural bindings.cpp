// https://www.youtube.com/watch?v=eUsTO5BO3WI
// Structural bindings from C++17

// how to handle multiple return types

#include <iostream>
#include <string>
#include <tuple>

// tuples, ties and pairs dealing
// structs returning <- old way

struct person_struct
{
    std::string name;
    int age;
};

std::tuple<std::string, int> person() // instead of tuple a pair can be used but tuple is expandable
{
    return{"someName",23};
}

int main()
{
    // older way
    std::tuple<std::string, int> p1 = person();
    // old way
    auto p2 = person();
    std::cout << "The old way of getting things :" << std::get<0>(p1) <<"|" << std::get<1>(p2) <<'\n';

    // another old, but better way
    std::string name1;
    int age1;
    std::tie(name1,age1) = person();
    std::cout << "The tie way of getting things :" << name1 <<"|" << age1 <<'\n';

    // using struct
    person_struct p3;
    p3.age = 10;
    p3.name = "someOtherName";
    std::cout << "The struct way of getting things :" << p3.name <<"|" << p3.age <<'\n';

    // new way
    auto [name2,age2] = person();
    std::cout << "The structural binding way of getting things :" << name2 <<"|" << age2 <<'\n';
}

/*
 * OUTPUT
The old way of getting things :someName|23
The tie way of getting things :someName|23
The struct way of getting things :someOtherName|10
The structural binding way of getting things :someName|23
 */