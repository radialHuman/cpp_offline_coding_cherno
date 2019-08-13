/*
 * https://www.youtube.com/watch?v=oIV2KchSyGQ
 * The Cherno
 * > virtual fucntions overrides methods in subclasses
 * > polymorphism example
 * > override dosen solve anything but indicates the reader about the virtual function in another class
 * > dynamic dispatch used by virtual fucntions help in creating v table which maps
 * > even though this has a overhead of creating a v table where virtual and derived tables are mapped, the efficiency is not reduced
 * > 2 over heads with memory and pointer
 * > This also helps in preventing spelling mistake and calling in the right function from base class
 * >
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
    virtual std::string getName(){
        std::cout << "Output from Base class here\n";
    }
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
    base* b = new base();
    b->getName();

    derived* d = new derived("Overridden output from Derived class here");
    d->getName();
}

/*
OUTPUT
 * Output from Base class here
 * Overridden output from Derived class here
 */