// https://www.youtube.com/watch?v=BvR1Pgzzr38
/* Copy constructor

*/

#include <iostream>
#include <string>
#include <string.h> // for strlen

class Str
{
    // old style since new style is automated and doesn prove the point
private:
    char* buf;
    unsigned int size;
public:
    Str(const char* s)
    {
        size = strlen(s);
        buf = new char[size+1]; //  extra for null termination
        // copying can be using for also, but for keeping it clean
        memcpy(buf, s, size);
        buf[size] = 0; // manually adding a null terminator

    }

    // to avoid memory leak, a destructor
    ~Str()
    {
        delete[] buf; // since on the heap
    }

    char& operator[](unsigned int i) // to access a char in a string, operator overloading
    {
        return buf[i];
    }

    friend std::ostream& operator<< (std::ostream& stream, const Str& s);
};

class Str_copy
{
    // old style since new style is automated and doesn prove the point
private:
    char* buf;
    unsigned int size;
public:
    Str_copy(const char* s)
    {
        size = strlen(s);
        buf = new char[size+1]; //  extra for null termination
        // copying can be using for also, but for keeping it clean
        memcpy(buf, s, size);
        buf[size] = 0; // manually adding a null terminator

    }

    // copy constructor
    Str_copy(const Str_copy& other) // also comes as default
        :size(other.size)
    {
       //  memcpy(this, &other, sizeof(Str_copy));
        buf = new char[size+1];
        memcpy(buf, other.buf, size+1);
    }

    // to avoid memory leak, a destructor
    ~Str_copy()
    {
        delete[] buf; // since on the heap
    }

    // to make sure copying is nto allowed:
    // Str_copy(const Str_copy& other) = delete;

    char& operator[](unsigned int i) // to access a char in a string, operator overloading
    {
        return buf[i];
    }

    friend std::ostream& operator<< (std::ostream& stream, const Str_copy& s);
};

// to make it possible with cout, overloading the operator
std::ostream& operator<< (std::ostream& stream, const Str& s)
{
    stream << s.buf; // called using a friend function, can access private members
    return stream;
}

std::ostream& operator<< (std::ostream& stream, const Str_copy& s)
{
    stream << s.buf; // called using a friend function, can access private members
    return stream;
}

int main()
{
    auto a = 3;
    auto b = a; //creating a copy with different address
    b = 3;
    // same for classes and structs

    // in case of heap allcoation, its pointers so they are a copy of a pointer pointing to the same address
    // changing one will affect the other
    int* a_h = new int;
    int* b_h = a_h;

    // example with old way of writing string
    Str s1 = "Some string here";
    std::cout << s1 << std::endl; // this will give the output but with some symbols in the end
    // changing the size by 1 in class

    Str s2 = s1; // shallow copy, doesn take care of pointer members
    s2[5] = 'Z';
    std::cout << "The new string is :" << s2 << std::endl;
    // due to this copying, the buf pointer is also copied and this crashes the code
    // creating the buf once and deleting it twice
    std::cout << "But the old string is now :" << s1 << std::endl;

    // to avoid this, the pointer has to be unique for the strings
    // deep copy, can be done using copy constructor
    std::cout << std::endl;
    Str_copy c_s1 = "Some string here using copy constructor";
    std::cout << c_s1 << std::endl; // this will give the output but with some symbols in the end
    Str_copy c_s2 = c_s1; // shallow copy, doesn take care of pointer members
    c_s2[5] = 'Z';
    std::cout << "The new string is :" << c_s2 << std::endl;
    std::cout << "And the old string is still :" << c_s1 << std::endl;

    // always use const and reference in fucntion 
}

/*
* OUTPUT
Some string here
The new string is :Some Ztring here
But the old string is now :Some Ztring here

Some string here using copy constructor
The new string is :Some Ztring here using copy constructor
And the old string is still :Some string here using copy constructor


*/