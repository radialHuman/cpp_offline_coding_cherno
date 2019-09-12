#include <iostream>
#include <string>
#include <set>
#include <functional> // std::greater

class Person_age
{
public:
    int age;
    std::string name;

    // comparator to sort the user defined elements, overloading less than since less than is default in set sorting
    bool operator  < (const Person_age& rhs) const {return age< rhs.age;};

    // for descending order
    bool operator  > (const Person_age& rhs) const {return age< rhs.age;};
};

class Person_name
{
public:
    int age;
    std::string name;

    // comparator to sort the user defined elements, overloading less than since less than is default in set sorting
    bool operator  < (const Person_name& rhs) const {return name < rhs.name;};

    // for descending order, can be done also by flipping the sign in return, but this is a better way
    bool operator  > (const Person_name& rhs) const {return name > rhs.name;};
};

int main()
{
    std::set<Person_age> s1 {{10,"name1"},{2,"ame2"},{33,"me3"}};
    std::cout << "If sorted by age\n" ;
    for (const auto& e: s1)
        std::cout << e.age << ", " << e.name << '\n';
    std::set<Person_name> s2 {{10,"name1"},{2,"ame2"},{33,"me3"}};
    std::cout << "If sorted by name\n" ;
    for (const auto& e: s2)
        std::cout << e.age << ", " << e.name << '\n';

    std::set<Person_name, std::greater<Person_name>> s3 {{10,"name1"},{2,"ame2"},{33,"me3"}}; // less is default, does type detection but can be given manually
    std::cout << "If sorted by name but in descending order\n" ;
    for (const auto& e: s3)
        std::cout << e.age << ", " << e.name << '\n';
}

/*
 * OUTPUT
If sorted by age
2, ame2
10, name1
33, me3
If sorted by name
2, ame2
33, me3
10, name1
If sorted by name but in descending order
10, name1
33, me3
2, ame2
 */
