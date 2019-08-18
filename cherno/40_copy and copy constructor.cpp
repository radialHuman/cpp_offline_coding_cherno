# include <iostream>
#include <string>

class c1{
public:
    int x,y;
};

// old school c way of making string
class String
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String(const char* s) // constructor
    {
        m_size = sizeof(s);
        m_buffer = new char[m_size+1]; // plus one is for the nullptr, or use strcpy if automatically required
        // copying the s to buffer
//        for (int i =0; i < m_size; i++)
//            m_buffer[i] = s[i];
        // also can be a lot cleaner
        memcpy(m_buffer,s,m_size+1);
    }
    // deleting the buffer on heap
    ~String(){
        delete[] m_buffer;
    }
    // copy constructor
    String(const String& other)
        : m_size(other.m_size)
    {
        m_buffer = new char[m_size+1];
        memcpy(m_buffer, other.m_buffer, m_size+1);
    }


    char& operator[](unsigned int i)
    {
        return m_buffer[i];
    }


    // friend fucntion to overload cout function
    friend std::ostream& operator <<(std::ostream& stream, const String& s);
};

std::ostream& operator <<(std::ostream& stream, const String& s)
{
    stream << s.m_buffer;
    return stream;
}


int main()
{
    // copying using inbuilt types
    std::cout << "With built-in types" << '\n';
    int a = 5;
    std::cout << "A now is :" << a << '\n';
    int b = a;
    std::cout << "B after copying is :" << b << '\n';
    b = 10;
    std::cout << "A after changing is (unchanged) :" << a << '\n';
    std::cout << "B after changing is :" << b << '\n';
    std::cout << '\n';
    // b is now a seperate copy and wont affect a

    // similarly for classes
    std::cout<< "With classes" << '\n';
    c1 c = {2,3};
    std::cout << "x of C :" << c.x << '\n';
    c1 d = c;
    std::cout << "x of D after copying is :" << d.x << '\n';
    d.x = 5;
    std::cout << "x of C after changing is (unchanged) :" << c.x << '\n';
    std::cout << "x of D after changing is :" << d.x << '\n';
    std::cout << '\n';
    // this happens due to the fact that they point to different memory addresses hence they dont affect each other even though one is made via the other

    // while doing heap allocation
    std::cout<< "Heap allocation" << '\n';
    c1* e = new c1();
    e->x = 1;
    e->y = 3;
    c1* f = e;
    // this way of copies, unlike previous one, not the struct value but the pointer to that location
    // any change in one will change the other as tey are pointing at the same thing
    std::cout << "x of e :" << e->x << '\n';
    std::cout << "x of f after copying is :" << f->x << '\n';
    f->x = 10;
    std::cout << "x of e after changing is (changed) :" << e->x << '\n';
    std::cout << "x of f after changing is :" << f->x << '\n';
    std::cout << '\n';
    // with the exception of references, while using "=", its always copying.
    // in case of pointers its copying just the pointer not the underlying value

    std::cout<< "Class copying" << '\n';
    String s = "Something";
    std::cout << "S initialized as : " << s << '\n';
    // copying (shallow, only pointer to same location)
    String t = s;
    std::cout << "T copied as : " << t << '\n';
    t[3] = 'd';
    std::cout << "S is now (changed) :" << std::endl;
    std::cout << "T is now :" << std::endl;
    std::cout << '\n';
    // the two will get destroyed twice, as the pointer is pointing to both

    // deep copy (to create a seperate memory with its personal pointer)
    // using copy constructor, in the class

}

/*
 * OUTPUT
 With built-in types
A now is :5
B after copying is :5
A after changing is (unchanged) :5
B after changing is :10

With classes
x of C :2
x of D after copying is :2
x of C after changing is (unchanged) :2
x of D after changing is :5

Heap allocation
x of e :1
x of f after copying is :1
x of e after changing is (changed) :10
x of f after changing is :10

Class copying
S initialized as : Somet
T copied as : Somet
S is now (changed) :
T is now :

 */