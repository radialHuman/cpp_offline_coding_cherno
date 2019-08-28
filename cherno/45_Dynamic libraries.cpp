// https://www.youtube.com/watch?v=pLy69V2F_8M&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=51&t=0s
/* Dynamic library
Static ones are combined and run at complie time
due to this they are avaialable for linker and can be optimized
while dynamic ones executed at run time, so it might throw up an error staying some thing is missing
it can be in the middle of the running the executable file
they have their own use cases
*/
#include <iostream>
#include <GLFW/glfw3.h> // had to be installed


int main()
{
	int a = glfwInit();
	std::cout << a << std::endl;
	
}


/*
* OUTPUT

*/