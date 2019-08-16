//https://www.youtube.com/watch?v=mS9755gF66w

/*
 * Operator and overloading it
 * > symbol to do some function
 * > mathematical symbols
 * > * -> += & <<
 * > new delete
 * > , {} [] ()
 * > overloading is giving new meaning to the symbol
 * > adding parameters
 * > https://en.cppreference.com/w/cpp/language/operators
 * >
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

struct v2
{
    float x,y;
    v2(float x, float y)
    : x(x), y(y){}

    v2 operator+ (const v2& other) const {
        return v2(x + other.x , y+other.y);

    }

    v2 operator* (const v2& other) const {
        return v2(x * other.x , y*other.y);

    }
};

std::ostream& operator<<(std::ostream& stream, const v2& other)
{
    stream << other.x << " " << other.y ;
}

int main()
{
    v2 position (4.0,5.0);
    v2 speed (40.0,50.0);
    v2 power (0.3,0.5);

    // v2 result = position.Add(speed.Multiply()) // this should be done inoder to add and multiply
    // but this is is not easy to read
    v2 result = position + speed * power;

    std::cout << result << std::endl; // since there is no cout function that takes in v2

}

/*
 * OUTPUT
16 30
 */