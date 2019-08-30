// https://www.youtube.com/watch?v=qCc_Vqg3hJk&t=29s
/*
Multiple types of variables C++17
* a class in std library
* std::variant part 1
* make the variable first and then think about ohw to work with it
* have a variable defined with a list of data types it can be
* 
*/

#include <iostream>
#include <variant>
#include <string>


template<typename T>
void checkAndReturnVariable(T value)
{
    // auto* p1 = std::get_if<std::string>(&value);
	// if(p1!=nullptr)
	if(auto p1 = std::get_if<std::string>(&value))
	   std::cout << "If the variable is a string (using std::get_if) : " << std::get<std::string>(value) << std::endl;
	else
	   std::cout << "If the variable is an integer (using std::get_if) : " << std::get<int>(value) << std::endl;
}

int main()
{
	std::variant<std::string, int> v1;	
	v1 = "Something";
	std::cout << "When the variable is a string : " << std::get<std::string>(v1) << std::endl;
	v1 = 10; // this can be done
	std::cout << "When the variable is an integer : " << std::get<int>(v1) << std::endl;
	// the variable will hold only one type at a time and that would be the latest one
	// so if no the string is called it would thrown an error
	// to avoid that and exception mechanism
	// to check whats the type the variable holds right now:
	std::cout <<"The variable now active is :" << v1.index() << std::endl;
	// here mapping is as in the declaration from 0 to ...

	// another way of getting the type
	// to return a pointer to the variable given its type
	checkAndReturnVariable(v1);
	v1 = "Something else";
	checkAndReturnVariable(v1);

	// comparing it to type safe unions, with respect to size
	std::cout << "Size of this variable is combination of all its type's size : " <<sizeof(v1) <<'\n';
	// union would be the size of the biggest type in it, this is like a struct or a class
	// due to this unions are efficient, but variants are type safe, no undefined behaviour

	// variant can be used instead of optional as it does not say what went wrong while reading a file
	// variant can have different variable type depending on the output, ex: error with int coded using enum class

}

/*
* OUTPUT
When the variable is a string : Something huge                                                                      
When the variable is an integer : 10                                                                                           
The variable now active is :1                                                                                                  
If the variable is an integer (using pointer) : 10                                                                             
If the variable is a string (using pointer) : Something else                                                                   
Size of this variable is combination of all its type's size : 16         
*/