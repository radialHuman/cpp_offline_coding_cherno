# [Scott Meyers - Effective Modern C++](https://www.youtube.com/watch?v=fhM24zs1MFA&list=PLmxXlAVb5hkyq5njldMEPYdOqTAQPLChR "Scott Meyers - Effective Modern C++")
 * Modern C++ means C++98/03 + C++11 + C++14
 ## **Agenda**
 1. lvalue and rvalue
 1. type deduction
 1. std::move and std::forward
 1. auto
 1. auto + {expr} => std::initializer_list
 1. universal reference and rvalue reference
 1. pass and return rvalue reference via std::move and universal reference via std::forward
 1. reference collapsing
 1. default capture mode
 1. make const member function thread-safe
 > ## Part 1 
 * Many things in modern c++ revolves around rvalues and lvalues
 > ### 1. Lvalue and rvalue
 * *__lvalue__*: 
    * Not permitted to be moved from, because it can have more than 1 way to access that variable.
    * If something moves it, other parts fo the program would detect that.
    * It is a named object and accessible by a pointer or reference
    * Generally, if you it has an address, it is lvalue
 * *__rvalue__*: 
    * Everything thats not a lvalue is a rvalue
    * May be moved from
    * Candidate for move operation to optimize by moving than copying
    * Accessible only at one point in the source code
    * Usually, unnamed temp objects, which cant have pointers or references
    * All inbuilt numeric literals are rvalue

 ``` cpp
    #include <iostream>
    #include <vector></vector>

    template <typename T1, typename T2>
    int diff(const T1& c1, const T2& c2)
    {return c1.size() - c2.size();}

    // diff, c1, c2 are lvalue
    // return value is rvalue
    
    int main()
    {
        int i = 10; // i is lvalue, 10 is rvalue
        i++; // is a 
        std::cout << 100 << std::endl; // 100 is rvalue
        return 0; // r value

        int *p;  // lvalue, cant be moved from only copied
        std::vector<int> v1;
        std::unordered_set<int> s;

        *p = diff(v1,s); // the part post "=" is rvalue
    }
 ```
> ### 2. Type deduction
* Apart from normal type deductions in template pre-modern C++
* _C++11_ : for auto, universal references, lambda captures, returns and decltype.
* Based on 5 sets of rule
* _C++14_ : scope expands, same rules, but more context like lambda init captures etc. 
* If type deduction goes wrong the error message is cryptic
* _C++98_ : Had template type deduction :
    * x, x&, x*
* _C++11_ : 
    * x&& (later)
    * Lambda implicit return
    * Lambda captures 
    * decltype
    * auto (modified)
* _C++14_ : 
    * Lambda auto parameters
    * Auto return types
    * decltype (auto)
    * Lambda init capture
* This is very important to understand as it has a lot of usage and it necessary to understand auto
* Template Type deduction
``` cpp
template <typename T> // T has to be deduced
void f(ParamType param); // ParamType also has to be deduced
f(expr);
```
* The two T and ParamType interact with each other
* The type of T is affected by the form of ParamType, mostly different from T
    1. ParamType is a &/* but not a universal reference
    1. ParamType is a universal reference
    1. ParamType is neither a reference or a pointer
* Auto behaves exactly like Template type deductions
1. __ParamType is a &/* but not a universal reference__
``` cpp
// case 1.1
// ignore if the T is referenced
template <typename T>
void f(T& argument);

int x = 22;
const int cx = 20;
const int& rx = 30;
f(x); // T is int, so ParamType is int&
f(cx); // T is const int, so ParamType is const int&
f(rx); // T is const int (ignore the reference), like in the previous case, so ParamType is const int&


// case 1.2
// T changes but Param does not
template <typename T>
void f(const T& argument);

int x = 22;
const int cx = 20;
const int& rx = 30;
f(x); // T is int, so ParamType is const int&
f(cx); // T is taken as int, since Param has const, it is const int&
f(rx); // T is taken as int, and similar to the previous case, ParamType is const int&

// case 2.1
template <typename T>
void f(T* argument);

int x = 22;
const int *pcx = &x;
f(&x); // T is int, ParamType is int*
f(pcx); // T is const int, ParamType is const int*


// How this helps understand AUTO, which plays the role of T
int x = 22;
const int cx = 20;
const int& rx = 30;

auto& v1 = x; // v1 is int&, auto is int
auto& v2 = cx; // v2 is const int&, auto is const int
auto& v3 = rx; // v3 is const int&, auto is const int

const auto& v4 = x; // v4 is const int&, auto is int
const auto& v5 = cx; // v5 is const int&, auto is int
const auto& v6 = rx; // v6 is const int&, auto is int
```
2. __ParamType is a universal reference__
* _**Universal References**_: 
``` cpp
// Treated like normal references
// except : if expr is lvalue with deduced type E then T is deduced to be E& i.e., if a lvalue is passed as expr, then the ParamType becomes Lvalue reference and if its rvalue, the it becomes rvalue reference
// Reference collapsing deduces E& for ParamType
template <typename T>
void f(T&& argument); // this is not a rvalue reference, it is a universal reference, which an be both (explained later), depending on type deduction
f(expr);

int x = 22;
const int cx = 20;
const int& rx = 30;

f(x); // lvalue is passed, T is int& and ParamType is also int&
f(cx); // lvalue is passed, T is const int& and ParamType is also const int&
f(rx); // lvalue is passed, T is const int& and ParamType is also const int&
f(22); // rvalue is passed, T is int and ParamType is int&& (rvalue reference)
```

3. __ParamType is neither a reference or a pointer__ (passed by value)
``` cpp
// expr with const, reference and volatile nature is ignored
template <typename T>
void f(T argument);  // is an independent object, gets its own copy

int x = 22;
const int cx = 20;
const int& rx = 30;

f(x); // both are int
f(cx); //  both are int
f(rx); // both are int 

// How this helps understand AUTO, which plays the role of T
int x = 22;
const int cx = 20;
const int& rx = 30;

auto& v1 = x; // v1 is int, auto is int
auto& v2 = cx; // v2 is int, auto is int
auto& v3 = rx; // v3 is int, auto is int

auto& v4 = rx; //v4 is const int&
auto&& v5 = rx; //v5 is const int&
```
**Auto vs template Type deduction (exception)**
* Even though auto behaves similar to template for deduction, there is one difference i.e., _braced initializers_
``` cpp
template <typename T>
void f(T param);

f({1,2,3,4}); // this will fail the template, there is no type

// but autos will get a type 
auto x1 = {1,2,3,4}; // type is std::initializer::list<int>
auto x2{1,2,3,4}; // type is std::initializer::list<int>
```

* Auto will never be deduced to be a reference, even if the passed value is reference
* It has to be addedd manually
* _Special case_ (exceptions)
    * When auto has an array initialized
    * When auto gets a function name 
* std::forward helps do move on rvalue but copy on lvalue
> #### Failures 
*  If there are multiple parameters in a template function, and the T is deduced differently, then it will fail.
* Lambda functions will deduce like template deduction.
> #### N3922 for c++17 (MSVC implements this)
``` cpp
auto x1{1,2,3}; // this is error as there is more than one inside the braces, and no "=" 
auto x2 = {1,2,3}; // is a initializer list
auto x3{17}; // is a initializer list and not int
auto x4 = {17}; // This will become a list since it has "="
```
* Braces are for uniform initialization, unlike ( ) 
* But in c++11/14 all these are initializer list
 
 > ## Part 2
 * ...
 > ### ...
