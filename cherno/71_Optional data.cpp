// https://www.youtube.com/watch?v=UAAiwObNhQ0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=79&t=0s
/* Optional - Part 1
Functions usually deal with data, but when it fails, something has to be returned in a proper manner
to check the presence of data, the way we need, optional helps
*/
#include <iostream>
#include <optional> // from C++17
#include <string>
#include <fstream>

// function to read string from file
std::string read_file(const std::string& path)
{
	// input file stream
	std::ifstream stream(path);
	// if successful
	if(stream)
	{
		std::string output;
		// read the file
		return output;
		stream.close();
	}
	// if not
	return std::string(); // constructor
}

std::optional<std::string> read_optional(const std::string& path)
{
	std::ifstream stream(path);
	if(stream)
	{
		std::string output;
		// read the file
		return output;
		stream.close();
	}
	// if not
	return {}; // returning empty optional
}

int main()
{
	std::string data = read_file("testing.txt");
	// old way of checking if it worked
	if(data!="")
	{
		std::cout << "It might have worked and it is :\n";
		std::cout << data << std::endl;
	}
	else
		std::cout << "Definitely did not work the old way\n";

	// or a boolean can be passed to make it true or false in the function based on the outcome

	// New way is to use the optional, which check if data is read properly or not

	std::optional<std::string> data2 = read_file("testing.txt");
	// auto data = read_file("/media/radial/Work/Projects/cpp/48_Templates.txt");

	// if default value has to be set
	std::string defaults = data2.value_or("Some default string");
	if(data2.has_value())
//	if(data2)

	    std::cout << "Testing the optional way : \n" << data2.value() << "\nData in text file" << std::endl;
	else
		std::cout << "Definitely did not work the new way either\n";
}

/*
* OUTPUT
Definitely did not work the old way
Testing the optional way :

Data in text file

*/
