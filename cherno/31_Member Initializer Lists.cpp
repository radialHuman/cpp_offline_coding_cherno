//https://www.youtube.com/watch?v=1nfuYMXjZsA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=37&t=0s

#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_name;
    int m_number;
public:
    // constructor, with no parameter, used to assign value by assigning
    Entity()
        // member initializer way
        : m_name("Something"), m_number(10) // used to initialize in the order in the private

    {   // one way of doing it normally is :
        // m_name = "Something";
    }

    // another constructor with parameter, used to assign the variable value
    Entity (const std::string& name)
    // member initializer way
            : m_name(name)
    {
        // m_name = name;
    }

    const std::string& getName() const {return m_name;} // class function
};


int main()
{
    // constructor member initialize list
    // class member initialization in the class constructor
    Entity e1; // creating object for class constructor with no parameter
    std::cout << e1.getName() << std::endl;
    Entity e2("Nothing"); // creating object for class constructor with parameter passed
    std::cout << e2.getName() << std::endl;

//    std::cout << "Enter a name\n";
//    std::cin.get();
    getchar();
}

/*
 * The use of this Constructor member initializer list is to avoid cluterring while assigning or initializing the variables inside a constructor
 * The advantage is that the constructor initializes only ones with this style or else it would create two and throw away one
 */

/*
Something
Nothing

 */
