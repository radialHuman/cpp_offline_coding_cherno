// https://www.youtube.com/watch?v=iNuTwvD6ciI&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=43
/*Stacks
like a pile of books, a book is a scope, and the variable sin it are the things written in the book
once the book is off the stack the variables/content is off too
this can be leveraged
a scope can be a function, if, loop, class or anything inside {}
*/
#include <iostream>

class Entity
{
public:
	Entity() // constructor
	{
		std::cout <<"Entity created\n";
	}
	~Entity() // destructor
	{
		std::cout <<"Entity destroyed\n";
	}
};

// a class which is scoped pointer and a wrapper around a pointer
// which upon contruction heap allocates the pointer and destroys when destruction occurs
// automating the new and delete process
// alternative to a unique pointer (done maually)

class scopedPointer
{
private:
	Entity* m_ptr;
public: 
	scopedPointer(Entity*  ptr)
	: m_ptr(ptr){}

	~scopedPointer()
	{
		delete m_ptr;
	}
};

int main()
{
	std::cout << "First using stack\n"; 
	{	
		std::cout << "In the stack scope\n"; 
		Entity e; // this will show created
	} // and this will show destroyed
	std::cout << "Out of the stack scope\n"; 

	std::cout << "And now using heap\n"; 

	{	
		std::cout << "In the heap scope\n"; 
		Entity* e = new Entity(); // this will show created
	} // and this will show destroyed
	std::cout << "Out of the stack scope and still alive\n";
	// delete e; // gets cleared automatically
	std::cout << "After deleteing\n";

	// a function that makes an array and returns a pointer to it when called in main
	// due to the fact that it is on stack it will not complie as the object is destroyed once outside the scope

	{
		scopedPointer e = new Entity();
	} // unlike other one on the heap, this will get destroyed as the scope ends
}


/*
* OUTPUT
First using stack
In the stack scope
Entity created
Entity destroyed
Out of the stack scope
And now using heap
In the heap scope
Entity created
Out of the stack scope and still alive
After deleteing
Entity created
Entity destroyed
*/