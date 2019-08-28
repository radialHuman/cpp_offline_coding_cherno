// https://www.youtube.com/watch?v=I-hZkUa9mIs&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=54&t=0s
/*
TEMPLATES Part-1
* Not just generics from other languages, which are limited
* More like macro 
* Make compiler write codes based on a set of rules
* Function that can take in different types
*/

#include <iostream>
#include <string>

void print_int_function(int x)
{
	std::cout << x << std::endl;
}
void print_str_function(std::string x)
{
	std::cout << x << std::endl;
}

// any error in this tempate implementation, will not be noticed unless its called
template<typename T>
// template<class T> // are the same thing
void print_template(T arg)
{
	std::cout << arg << std::endl;
}

// class template
// creating an array on stack, array size determined at complie time, so a template can be used
template<int n> // since we know what we want to fill in later
class Array_1
{
private:
	int m_array[n];
public:
	int getSize() const {return n;}
};

template<typename T,int n> // since we know what we want to fill in later
class Array_2
{
private:
	T m_array[n];
public:
	int getSize() const {return n;}
};



int main()
{	
	std::cout << "Output from various functions:\n";
	print_int_function(5); 
	// this function will only be useful if its type is int, for anyother type, there has to be separate function,
	// which is basically writting the same code again with just a different type of paramter
	// else if a small change has to be done, it has to be done in all the functions, no need to overload
	print_str_function("Some string"); 

	// a better way is to something more generic 
	// This template is evaluated at complie time, not a actual function
	// when called, and with what paramters or types its called in, 
	print_template("\n");
	print_template ("Output from the template:"); 
	print_template("Some other string");
	print_template(1.2);
	print_template(1);
	// can be also written as 
	// print_template<int>(1)

	// this is not limited to types or functions. this can be extended to classes
	// STL is based on this

	// Example for class
	print_template("Example for a template class, with fixed type of content (int)");
	Array_1<5> array_1;
	print_template("Array size is:");
	print_template(array_1.getSize()) ;

	print_template("Example for a template class, with variable type and size");
	Array_2<std::string,10> array_2;
	print_template("Array size is:");
	print_template(array_2.getSize()) ;


	// this is meta programming, where complier codes during complie time

	// templates cant be used everywhere, and going complex with it can lead to confusion
}

/*
* OUTPUT
Output from various functions:
5
Some string


Output from the template:
Some other string
1.2
1
Example for a template class, with fixed type of content (int)
Array size is:
5
Example for a template class, with variable type and size
Array size is:
10
*/;