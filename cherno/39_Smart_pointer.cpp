//https://www.youtube.com/watch?v=UOB7-B2MfwA

#include <iostream>
#include <memory> // for smart pointers
#include <string>
#include <vector>


/* Smart pointer
 * no need to use new or delete
 * wrapper around raw pointer
 * different types of SP
 * helps in memory management
 * execute the following with breakpoint to see the effect
 */

class Entity{
public:
    Entity()
    {
        std::cout <<"Entity created!" << std::endl;
    }
    ~Entity()
    {
        std::cout <<"Entity destroyed!" << std::endl;
    }
    void print(std::string x)
    {
        std::cout << x << std::endl;
    }
};


int main()
{
    // unique pointer , is a scope pointer and is destroyed beyond the scope, cant be copied
    { // allocates on stack
    // std::unique_ptr<Entity> e(new Entity());
    std::unique_ptr<Entity> e = std::make_unique<Entity>(); // this is the right way to create, due to exception safety
    e -> print("Something");
    }
    // this can be shared and thats a problem

    // shared pointer depends on std lib and complier : reference counting
    // keep tab of how many refernces are pointing and when it becomes 0 it destroys
    std::shared_ptr<Entity> se2;
    {
        std::shared_ptr<Entity> se0 = std::make_shared<Entity>(); // this is the right way as this will create duplicates
        std::shared_ptr<Entity> se1 = se0;
        se2 = se1; // works even outside the scope
    }

    // weak pointer along with shared pointer, which does not increase the reference count
    std::weak_ptr<Entity> we0 = se2;


}

/*
 * OUTPUT
Entity created!
Something
Entity destroyed!
Entity created!
Entity destroyed!
 */