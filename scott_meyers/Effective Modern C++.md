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
 
 ---
 > ## Part 2

 > ### Decltype type deduction (C++11)
 * If something has to be initialized and its type has to be similar to that of something else then it can be used to deduce the type and play the role of type
 * It never strips const/volatile/references
 ``` cpp
#include <iostream>
#include <vector>

int main()
{
    int x = 10;
    decltype(x) y{12}; // using the type of x to initialize y
    std::cout << y << std::endl;
}

/*
 * OUTPUT
 12
 */
 ```
 * decltype(lvalue of type T) = T&
 * _Side effect_ : names are lvalue, but decltype(name) rule beats decltype(expr) rule
 ``` cpp
    int x = 10;
    // decltype(x) is int
    // decltype((x)) is int&
 ```
* Other complex rules are for hard-core library building 

> ### Function return type deduction (C++14)
* All lambdas and all fucntions are elegible for type deduction
* Two main type return deductions are:
    1. auto : That uses template type deduction (not auto type deduction). This will make a copy in return.
    2. decltype(auto) : uses decltype deduction rules. This would return a reference to the value.
* Do not put ( ) for returning anything, that would not give the value of the object but the value of the expression
* _Exception_: If the return type inside the function is int and the return type of the function is decltype(auto), the output will be int, but if the return is with ( ), then the output will be reference as in the case of decltype(auto)
``` cpp
#include <iostream>
#include <vector>

decltype(auto) func1(const int& x)
{
    auto y = x;
    return y; // this is a name return
}

decltype(auto) func2(const int& x)
{
    decltype(x) y{10};
    return (y); // this is a expression return
}

int main()
{
    std::cout << "return without paranthesis : " << func1(10) << std::endl;
    std::cout << "return with paranthesis gives a reference : " << func1(10) << std::endl;
}

/*
 * OUTPUT
return without paranthesis : 10
return with paranthesis gives a reference : 10
 */
```
* Deduced return type has to be used carefully, and most of the time unused

> ### std::move and std::forward
* They dont move or forward respectively, at run time
* The dont generate code either, at run time
* std::move: unconditionally __casts__ to an rvalue : rvalue_cast
    * Implementation of move in C++14 has decltype(auto)
* std::forward: conditionally __casts__ to an lvalue
``` cpp
#include <iostream>
#include <vector>
#include <string>

class annotation
{
private:
    std::string output;
public:
    explicit annotation(std::string input);
};
// constructor outside the class
annotation::annotation(std::string input):output(std::move(input)) {}

int main()
{
    annotation e("something");
    std::cout << e << std::endl;
}

/*
 * OUTPUT

 */
```
---
> Lost 30 mins of the video (no move/forward explantion at this time in any other resource, may be in the book later)
---

> ### Auto
* If a lvalue is "auto"ed then it should be initialized
``` cpp
int x; // allowed
auto x = 10; // allowed
auto x; // not allowed, cos it doesn know what the type is
```
* makes code easier to read
``` cpp
for(std::string::iterator s : s1 ) // explicit is verbose
for (auto i: s1) // easy to read

// if a iterator points to something, the type fo that iterator is 
// std::iterator_traits<It>::value_type <- this is inconvinient to type in so, auto it
```
* makes things easy when it comes to different bytes in 32 and 64 bit systems
``` cpp
unsigned s = v1.size(); // can be problamatic if in 64 bit windows
auto  s = v1.size(); // makes things easy
```
* Avoid accidental temporary objects
``` cpp
std::map<std::string, int> m;
for(const std::pair<std::string,int>& p : m) ... // creates temp for each element by copying since the const is missing in pair. Also it is slow and wrong
for(const auto& p : m) ... // no temps required
```
* It is not just typing convinience, but avoids such pitfalls
* Efficient way fo storing function objects
``` cpp
std::function<int(int)> fla = [a,b](int x){return x*x -a/10 +b;}
// each lambda fucntion has its own type 
// std fucntion obj can store these, in this case, it takes an (int) and returns an int
// it has a fixed size in memory, can be on heap, 
// it is a generalization of function pointer
auto flbs  = [a,b](int x){return x*x -a/10 +b;}
// cant be on heap, hence more efficient
```
* *__Exceptions__* 
    * braced initialization
    ``` cpp
    auto v1 = {1,2,3,4}; // list
    auto v1 {5}; // list
    auto v1 (5); // int
    auto v1 = 5; // int
    ```
    * hidden proxy types
    ``` cpp
    // type that acts like some other type
    // vector<bool> is an examples
    std::vector<bool> v;
    bool v1 = v[5]; // is a bool, it returns reference to the element not to a bit which is how bool stores
    auto v1 = v[5]; // is a std::vecot<bool>::reference, a class type
    ```
    * It can make temporary with proxy types exist more larger than it should generally and lead to dangling pointer, undefined behaviour
* These problems are common for libraries based on expression template, like: 
    * Boost.uBLAS (matrix operations)
    * Boost.Xpressive (regex)
    * Boost.proto (DSL)
    * Boost.MetaStateMachine (state machine)
* These with auto has higher risk of compile/tun time surprises
---
 > ## Part 3

* The libraries with proxy has good documentation and if suspicious, header file template would have variation in the type the should return and the one they do
* To cope with this issue, auto can be said what to deduce by casting 
* This helps in making it clear that there is a type conversion involved - expressive

> ### Universal references
* type&& <- is a universal reference and can be both lvalue and rvalue
* Lvalue cant be assigned to a rvalue reference type, and vice versa
    * if "type&& or "&&" is a rvalue then
        * It binds onlr rvalues and
        * facilitates move
    * Else if its a universal type
        * Binds everything
        * can copy or fwd
        * renamed by forwarding reference
* *Reference collapsing* (later)
``` cpp
void f(widget&& param); // rvalue ref

widget&& var1 = widget(); // rvalue ref

auto&& var2 = var1; // not rvalue ref

template <typename T>
void f(std::vector<T>&& param); // rvalue ref

template <typename T>
void f(T&& param); // not rvalue ref

```
* URef arises in two situations
    * function template parameter (mostly used in)
    ``` cpp
    template <typename T>
    void f(type&& param);
    ```
    * Auto declaration
    ``` cpp
    auto&& var = ... ;
    ```
    * _It happens if its of T&& where the T is deduced type_
    * Initiaizer of a reference determines if its a r or l value ref
    ```
        * Initializer of URef is a L => URef becomes LRef
        * Initializer of URef is a R => URef becomes RRef
    ```
    * Example 1 (in template)
    ``` cpp
    template <typename T>
    void f(T&& param);

    widget w;

    f(w); // here w is a lvalue, which is passed into the template, which makes f(Widget&) by deducing, hence making URef a LRef

    f(std::move(w)); // here w is casted into Rvalue, hence making f(widget&&), there by making URef a RRef
    // these two call different functions due to change in reference
    // reduces different templates in less code

    f(widget()); // Creates unnamed temp widget object, no address so its a rvalue and hence template gets RRef
    ```
    * Example 2 (auto declaration)
    ``` cpp
    std::vector<int> v;

    auto&& val = 5; // This is a rvalue passing hence RRef

    auto&& val = v[5]; // returns int&, which is a lref == lavlue (default), hence making this whole thing LRef
    ```
    * Standardized document (hazardous), has details of libraries and auto&& is used in range-based-for implementation. Otherwise its rare in user code.
    * Can be used in C++14 lambdas
    * Not type deduction, no URef
    ``` cpp
    void f(Widget&& w);  // no type deduction, since widget is known to be the type, so its a RRef not URef

    template <typename T>
    void f(T&& param); // T is not known, will be deduced, so URef

    template <typename T1>
    class g1
    {
        g1(g1&& rhs); // no type deduction going on , so Rref
    };

    template <typename T1>
    class g2
    {
        template <typename T2>
        g2(T2&& rhs); // T2 is deduced, so URef
    };
    ```
    * Not all T&& in a template lead to URef
    ``` cpp
    template <class T, class Allocator=allocator<T>
    class vector{
    public:
        void push_back(T&& x); // 
    };

    std::vector<int> v1; // due to the nature of this, the type is known and there is no deduction
    v1.push_back(10.5); // this would make it a RRef
    ```
    * >  #### _Function templates can deduce types, class template cant_
    
---
 > ## Part 4

 * If the same implementation is done for emplace_back than push _back then it is a URef
 * Since it gives a list of arg (variadic template) of arbitrary type and deduction happens
 * emplace_back does not create and destroy extra constructor like push_back (lesser code, lesser steps)
 * In the vector of std, there are two versions push_back one for l and one for r (overloaded)
 * But since URef is eligible in case of emplace_back, only one fucntion exists (purpose of URef) (already overloaded)
 * Emplace back moves the arguments -> forwards reference

* Syntax matters : The type has to be entirely deduced
 ``` cpp
 template <typename T>
 void f(T&& param); // URef

 template <typename T>
 void f(const T&& param); // RRef, const will not be deduced

 template <typename T>
 void f(std::vector<T>&& param); // RRef, nothign to deduce like in the case of class
 
 widget w;
 auto&& v1 = w; // URef => becomed LRef
 const auto&& v2 = w; //  wont compile

 ```
* RRef to const is very rare, since RRef can be moved, const means cant modify so its contradictory

* _RRef can be used be std::move and URef can be used with std::forward_
* _RRef is bound to be moved, whereas URef might be moved_
* Every type can have both rvalue and lvalue ex: int x; and 10;
* ALl parameters are lvalue, it has a name and an address
``` cpp
widget::widget (widget&& rhs); // this is a RRef to a lvalue
template<typename T>
void widget::setName(T&& newName); // this is a URef to a lvalue
```
* One of the main function of C++11 was to make it possible for rvalues to be moved from
```
doSomthing( parameter ); // this should treat rvalue and lvalue separately (polymorphism)
```
* std::move unconditionally casts to rvalue
* std::move is used to avoid copying
``` cpp
class Widget
{
    public:
    Widget(Widget&& rhs) // this is a rvalue ref since it involves class
    : name(std::move (rhs.name)), // moving object field by field
    p(std::move (rhs.p))
    {
        // implementation
    }

    private:
    std::string name;
    std::shared_pointer<someDataStructure> p;
};
```
* std::forward conditionally casts to a rvalue
* Since it is a URef, move might not work so forward depending on the value
```cpp
class Widget
{
public:
    template <typename T>
    void setName(T&& newName) // it will cast it into an rvalue only if it was bound to an rvalue when it was called
    {
        name = std::forward<T>(newName); // this is a URef, the T type will determine if it will be copied or moved
    }
};

```
* URef copy lvalues and move rvalue
* These are cast so complier doesn know what it does
* std::forward has to be apssed in with a type to be casted in
* Case: 
```
If there is a move done before the move fucntion then the variable will not be there to be moved,so move it or change it only in the last cast
```
* _Use std::move on the last occurance of the RRef_
* _Use std::forward on the last occurance of the URef_

* Return value optimization (???)
* If its a RRef you are passing, apply move when last used
* Same for URef, forward it when last used
``` cpp
Matrix operator+(Matrix&& temp, const Matrix& y)
{
    temp += y;
    return std::move(temp); // treat it like an rvalue
}

Matrix operator+(Matrix&& temp, const Matrix& y)
{
    temp += y;
    return temp; // will be copied
}
```
* Functions returning references might lead to danlging references problem
* _Copy elition_ : If local variable is of the same type as the function, and it returns the lcoal variable, then both of them can be put in the same chunk so dont move it 
* If it is returned with a move, which is a function, does not suit well with copy elition
``` cpp
// generates good code
Widget f1()
{
    Widget w;
    ...
    return w;
}

// generates bad code
Widget f1()
{
    Widget w;
    ...
    return std::move(w); /// also no Rref here
}
```

---
 > ## Part 5