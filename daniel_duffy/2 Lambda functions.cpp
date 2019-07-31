/* Daniel Duffy
 * https://quantnet.com/media/categories/level-1-videos.12/
 * LAMBDA FUNCTIONS
 * > unnamed functions
 * > defined inplace, on the fly
 * > used for call back functions
 * > instead of global functions and functors
 * > used with stl-algorithms
 * SYNTAX:
 * [capture variable](input parameter)<mutable> -> return type {function implementation}
 * capture variables : defined outside the scope of function but can be used in fucntion
 * [=] captures all local variables by value, [&] captures all the local variables by reference
 * [=, &x] can be sued to make exceptions
 * sometimes if the variable is not available while callin, it leads to dangling pointer problem
 * which was then resolved in cpp 14
 * stateful lambdas : uses local variable in to capture variable to work on it and can be modified
 * Can capture "this" by [this] inside a class
 * and inside the LF, this-> member can be sued to capture
 *
 * AUTO
 * data type deduced at compile time
 * for storing ananonymous type
 *
 * Stored lambda functions
 * can be given an alias
 */



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>


int main()
{
    // lambda function
    std::vector<int> v1{1,2,3,4,5,6,7,8,9,10};
    // ostream is for showing output
    std::remove_copy_if(v1.begin(), v1.end(),std::ostream_iterator<int>(std::cout," "),
            [](int i) -> bool
            {
                if(i>=3)
                    return true;
                else
                    return false;
            });
    std::cout << std::endl;

    // generate a number and replace it to the begining of vector
    std::generate_n(v1.begin(),v1.size(), []{return 12;});
    std::for_each(v1.begin(),v1.end(),[](int i){std::cout << i << " ";});
    std::cout << std::endl;

    // stateful lambdas
    int sum = 0;
    std::for_each(v1.begin(), v1.end(),[=](int i) mutable {sum+=i; std::cout<<"Inside lambda the sum is :"<< sum << std::endl;}); // to indicate the captured variable is allowed to be altered
    // lambda doesn alter the state of variable, its a const function
    std::cout << "The sum is (when passed by value, outside lambda) :" << sum << std::endl;
    std::for_each(v1.begin(), v1.end(),[&](int i){sum+=i;});
    std::cout << "The sum is (when passed by reference) :" << sum << std::endl;

    // stored lambda function
    auto f1 = [](std::vector<int> v){ return(std::accumulate(v.begin(),v.end(),0));};
    std::cout << "The sum of vector using stored lambda function is :" << f1(v1) << std::endl;

}

/*
 * OUTPUT
1 2
12 12 12 12 12 12 12 12 12 12
Inside lambda the sum is :12
Inside lambda the sum is :24
Inside lambda the sum is :36
Inside lambda the sum is :48
Inside lambda the sum is :60
Inside lambda the sum is :72
Inside lambda the sum is :84
Inside lambda the sum is :96
Inside lambda the sum is :108
Inside lambda the sum is :120
The sum is (when passed by value, outside lambda) :0
The sum is (when passed by reference) :120
The sum of vector using stored lambda function is :120

 */
