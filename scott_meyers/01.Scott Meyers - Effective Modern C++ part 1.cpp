/*
 * https://www.youtube.com/watch?v=fhM24zs1MFA&list=WL&index=12&t=188s
 * > Lvalues and rvalues
 * > type deduction
 * > std::move and std::forward
 * > auto
 * > std::initialize_list
 * > universal reference vs rvalue reference
 * > reference collapse
 * > capture modes
 * > const member function thread safe
 *
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <typeinfo>
#include <string_view>
#include <random>

int main()
{
    /*
     * LVALUE
     * > Represents things that may not be moved from
     * > It has address
     * > has or could have more than one way to access a variable
     * > objects that are accessible from more than one point in the source code
     * > Ex: int x; x= 10; , x is lvalue
     * RVALUE
     * > Its everything thats not lvalue
     * > May be moved from
     * > can be accessible only from one point in the source code
     * > unnamed temporary objects, to which * or & cant be got
     * > this is used to perform optimization by moving than copying
     * > ALl numeric built in literal is rvalue
     * > Ex: int x; x= 10; 10 is rvalue
     *
     * TYPE DEDUCTION
     * > in 98: Needed for template
     * > in 11: for auto, references, lambda, decltype and returns
     * > in 14: return type, lambda init capture
     *
     * Universal reference
     * > It is indicated by &&
     * > If type deducted is l then && takes it as l or else r
     * > l value becomes type plus reference
     * > r value become type plus &&
     * > ...
     *
     * By Value:
     * > It makes its own copy, so it ignores all thats passed and removes const or references
     * >
     *
     * Initializer list should have "=" to be safe due to confusion between compliers
     */

}

/*
 * OUTPUT

 */
