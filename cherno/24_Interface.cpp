/*
 * https://www.youtube.com/watch?v=UWAdd13EfM8
 * The Cherno
 * > Pure virtual function - interface
 * > the base class doesn have the implementation of the function
 * > forces derived classes to have detials about the function
 * > its common to create classes with unimplemented methods
 * > since there is no method implementation, we cant instantiate that class
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

class base{
public:
    // function to be overridden, but only if virtual
    virtual std::string getName() = 0; // creating just the interface
//    {
//        std::cout << "Output from Base class here\n";
//    }
};

// derived class
class derived  : public base
{
private:
    std::string string;
public:
    // constructor to get a name, using memeber initalization
    derived(const std::string& n )
            : string(n) {}
    std::string getName() override { // override indicates that its a vritual function from base class
        std::cout << string << '\n';
    }
};



int main()
{

//    base* b = new base(); // this cant be done anymore as its a interface and no method implementation
    base* b = new derived("Base interface");
    b->getName();

    derived* d = new derived("Overridden output from Derived class here");
    d->getName();

}

/*
OUTPUT
 * Base interface
Overridden output from Derived class here
 */
