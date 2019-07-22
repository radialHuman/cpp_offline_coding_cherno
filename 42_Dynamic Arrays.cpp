//https://www.youtube.com/watch?v=PocJ5jXv8No&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=48&t=0s

#include <iostream>
#include <string>
#include <vector>

void function_to_pass_array(const std::vector<int>& x) // pasing it this way, does not copy the whole things
{
    std::cout << "From function :";
    for (auto i : x)
        std::cout << i << " ";

}

int main()
{
    // vectors
    std::vector<int> v1{1,2,3,4,5,6};

    for (auto i : v1)
        std::cout << i << " ";
    std::cout << std::endl;
    for (auto& i : v1)                  // this does not copy the whole thing into cout, it just sends the reference
        std::cout << i << " ";
    std::cout << std::endl;


    // to remove one element, it needs an iterator
    v1.erase(begin(v1)+2);
    for( auto& i:v1) std::cout <<i << " ";
    std::cout << std::endl;

    function_to_pass_array(v1);

    // to clear the vector entirely
    v1.clear();

    // next video
    // https://www.youtube.com/watch?v=HcESuwmlHEY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=49&t=4s

    // optimizing vector
    // know your environment and how things work and how they will react
    /*
     * vector dynamically allocates memory, by copying the pushed data from a location to another and deletes the previous one
     * if capacity runs out, the resizing occurs, this is one of the causes of latency
     * copying objects of vector has to be optimized
     */

    // Optimization 1:Make less copies and put the data directly in the allocated vector location
    // Optimization 2:If we know the data then we can avoid resizing and assign the size upfront
    std::vector<int> v2;
    v2.reserve(3); // this way we can assign size upfront, to make it faster then default of 1
    v2.emplace_back(10); // this makes things very fast as it directly makes storage in main vector
    v2.emplace_back(20);

}

/*
 *
 *
 */

/*

 1 2 3 4 5 6
1 2 3 4 5 6
1 2 4 5 6
From function :1 2 4 5 6

 */