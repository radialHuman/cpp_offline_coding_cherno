// https://www.youtube.com/watch?v=HcESuwmlHEY
/* Optimizing vector
To optimize anything, its working mechanism has to be known
1. create a vector
2. Start adding stuff in it
3. if the size of data pushed is larger than its capacity
4. vector has to allocate new memory
5. copy old to new location with new data
6. delete the old one
7. this reallocation makes the code slow
8. to avoid copying can optimize
9. to understand copying

*/
#include <iostream>
#include <vector>

struct vec
{
    float x,y,z;

    // constructor
    vec(float x, float y, float z)
    :x(x),y(y),z(z) {}

    // copy constructor
    vec(const vec& v)
    :x(v.x),y(v.y),z(v.z)
    {
        std::cout << "Copied!" << std::endl;
    }


};

int main()
{
    // to check how many copies happens by default
    std::vector<vec> v1;
    v1.push_back(vec{1,2,3}); // copy # 1
    v1.push_back(vec{3,2,1}); // copy # 2 and 3 resizing of capacity

    // this default way produces 3 copies

    v1.push_back(vec{0,0,0}); // copy 4, 5 and 6
    //by adding one more the number of copies becomes 6!
        // this is because, when one is pushed, then one copy occurs in the stack in main
        // this has to be taken from main function into the memory of vector
        // OPTIMIZATION 1: To store it directly in the vector memory instead of copying
        // OPTIMIZATION 2: If size if known before hand, capacity can be set and resizing wouldn happen

    // optimized version
    std::cout << "After optimziation 1 :\n";
    std::vector<vec> v2; // cant do it here, as it will create 3 objects instead of having memory for them
    v2.reserve(3);
    v2.push_back(vec{1,2,3});
    v2.push_back(vec{3,2,1});
    v2.push_back(vec{0,0,0});

    // so far reduced it to half
    // making it in the actual vector
    std::cout << "After optimziation 2 :\n";
    std::vector<vec> v3;
    v3.reserve(3);
    v3.emplace_back(1,2,3);
    v3.emplace_back(3,2,1);
    v3.emplace_back(0,0,0);
}

/*
* OUTPUT
Copied!
Copied!
Copied!
Copied!
Copied!
Copied!
After optimziation 1 :
Copied!
Copied!
Copied!
After optimziation 2 :

*/