//https://www.youtube.com/watch?v=4fJBrditnJU&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=35&t=11s

#include <iostream>
#include <string>

// const in classes and functions
class entity
{
private:
    int m_x, m_y;
    int* x1,y1; // makes only x1 a pointer
    int* x2, *y2; // makes both a pointer
    mutable int var;
public:
    int get_x() const //this works only inside a class,
    // it says the method will not modify the values of the actual variable
    {
//        m_x = 2; // this cant happen
        // but this can happen
        var = 2; // since it is mutable
        return m_x;
    }
    // this one returns a pointer that cant be modified, the content also cant be modified and the class members also cant be
//    const int* const get_x() const{}

};

void function_with_reference(const entity& e){} // accepts entity type objects without copying

int main()
{
    // Its a promise (breakable) to keep something constant
    const int MAX_VALUE = 5; // a must be 5 only and cant be modified, and is not a variable

    // for pointers
    int*  a  = new int;// creating integer on a heap to get a pointer ??
    std::cout << "A was : " << *a << std::endl;
    // this will not be constant as we can dereference a and assign it something else
    *a = 2;
    std::cout << "A is now :" << *a << std::endl;

    // the way to avoid all this
    const int* b = new int; // or any other way of writing const before the pointer
    // int const* b
    std::cout << "B was : " << *b << std::endl;
    std::cout << "New vairable B is constant and it can be still modified\n";
    /* this cant be done as in the case of a:
    *b = 10;
     */
    // can also now reassign the pointer to point to some other address
    b = (int*)&MAX_VALUE; // to make it int and assign it to a, bypassing with int pointer casting, way to break the const
    std::cout << "B is now again : " << *b << std::endl;

    // things can reverse if const location is a bit different
    int* const c = new int; // making the pointer constant
    *c = 10;
    // c = (int*)&MAX_VALUE; // this wouldn happen now

    // combination of both
    const int* const d = new int;
    // int const* const d = new int;
}

/*
 *
 *
 */

/*

A was : 17398448
A is now :2
B was : 17398448
New vairable B is constant and it can be still modified
B is now again : 5

 
 */