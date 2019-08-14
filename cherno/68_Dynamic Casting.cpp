/*
 * https://www.youtube.com/watch?v=CiHfz6pTolQ&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=74&t=2s
 * The Cherno
 * > Dynamic Casting
 * > validation is done if the cast was successful or not
 * > its a fucntion, and evaluated with run time
 * > can be done for classes based on hierarchy only
 * > base class casted to derived can be problematic
 * > if fails, then nullptr is returned
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

class Entity
{
public:
    virtual void print(){}
};

class player : public Entity
{
//public:

};

class enemy : public Entity
{
//public:

};

int main()
{
    Entity* e1 = new Entity();
    enemy* en = new enemy();
    player* p1 = new player();
    player* p2 = dynamic_cast<player*>(p1);
    player* p3 = dynamic_cast<player*>(en);

    std::cout << p2 << std::endl;
    std::cout << p3 << " <- Nullpointer for unconvertable type class" << std::endl;
    if(p3)
    {
        // somethign can be done
    }

    // RTTI run time type information is stored and adds overhead
    // and does the matching of types
    // this can be turned off in properties

}

/*
 * OUTPUT
0xf01a10
0 <- Nullpointer for unconvertable type class
 */