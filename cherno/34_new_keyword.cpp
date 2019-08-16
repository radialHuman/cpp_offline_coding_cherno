//https://www.youtube.com/watch?v=p4sDgQ-jao4&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=59&t=0s

/*
 * NEW keyword
 * > memory is not managed in c++
 * > performance can be enhanced due to this
 * > new to allocate memory in heap specifically
 * > new  <datatype>
 * > this allocates bytes of memory as per the size
 * > contiguous block of memory has to be found and pointer si returned
 * > this takes time
 * > free list a list that has free memory maintained with this information
 * > its an operator
 * > can be over loaded just like + or -
 * >
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

class classes
{
public:

};

int main()
{
    int a  =10;
    // can also be written as
    int* b = new int; // since new returns a pointer
    // this allocates single 4 byte interger on the heap and b is storing tis memory address
    int* c = new int[50]; // specifying how many elements is required

    // classes also can be allocated on the heap
    // with classes, it sees the amount of variable size and multiples by instance count and finds such a memory
    classes* e = new classes[50]; // to create multiple objects
    classes* d = new classes();
    // this will not only make the memory but also the constructor
    // also written ac classes* d = (classes*)malloc(size_of(classes)); but this is without the constructor
    // also calls malloc(), memory allocation function

    // after using all the news, they have to be deleted
    delete b;
    delete[] e; // since it creates an array of memory
    delete[] c;
    delete d; // also an operator based on c fucntion "free"

    // automation of delete can be done using scope based pointer and reference counting

    // placement new decides where the memory comes from
    


}

/*
 * OUTPUT

 */