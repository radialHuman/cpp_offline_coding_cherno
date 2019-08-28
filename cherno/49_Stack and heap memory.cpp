// https://www.youtube.com/watch?v=wJ1L2nSIV1s&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=54
/*
STACK AND HEAP MEMORY
* SM and HM are areas in RAM
* SM is ~2MB and HM is mutable
* HM is hot as it is continuously stored and accessed, it can be in cache also
* These are used to store data
* CPP, when ased, gives us a part of these.
* The difference lies in how it allocates these memories
* 
*/

#include <iostream>

struct sv
{
	float x,y,z;
	// constructor
	sv()
	: x(10),y(12),z(14) 
	{}
};

int main()
{
	// on a stack
	int v1 = 5;
	int array[5];
	array[0] = 0;
	array[1] = 1;
	array[3] = 2;
	array[3] = 3;
	array[4] = 4;
	sv s{1,2,3};
	/* all these will be stored close to each other in memory with memory guards in between
	stack pointer, when something is assigned, moves, to the equivakent memory locations 
	stack stored backwards and one after another, its very fast
	the data is stored close to eachother, contiguously
	once the scope is over, all these will get free
	*/

	// on a heap
	int* hv1 = new int;
	// new calls a function called malloc, memory allocator, calls platform specific fucntion
	// which allocates memory on the heap
	// inintally a certain portion of RAM is allocated, which will be tracked using "free list"
	// a lot of book keeping about the size, the status and the pointer that goes on due to malloc
	// and if application demands for more than whats assigned, then more memory is requested from OS
	// thats all very expensive
	*hv1 = 5;
	int* haaray = new int[5];
	harray[0] = 0;
	harray[1] = 1;
	harray[3] = 2;
	harray[3] = 3;
	harray[4] = 4;
	sv* hs = new sv;

	delete hv1;
	delete[] harray;
	delete hs;
	// since new was used, and no smart pointers are used, these have to be deleted to free our memory

	/*
	The only reason to use heap is when stack cant take the amount of data
	Or when object has to be accessed beyond the scope
	performance difference is the allocation
	cache miss (???)
	*/


}

/*
OUTPUT
* 
*/