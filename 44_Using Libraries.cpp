//https://www.youtube.com/watch?v=or1dAmUO8k0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=50&t=0s

#include <iostream>
#include <string>
#include <vector>

#include "C:\Users\RAHULDAMANI\CLionProjects\try2\dependencies\GLFW\include\GLFW\glfw3.h"

extern "C" int glfwInit();

int main()
{
     /*
      * this guy does not use any package manager and keeps all the library files in the project
     this one is for linking it to the binaries and not making a source code
     ex: GLFW library. via binary for windows
     library has two parts
     Includes: has header files, with functions to binaries
     lib: has the binaries
     libs can be both dynamic and static but it might not be available always
     static linking:lib is put into the executable into exe file, faster cso of  link time optimization
     dynamic file: linked during run time  dll -> dynamic link library

      */

     // for linking, all the lib and include files are placed in dependencies folder

    int a  = glfwInit(); // trying a function from header files function declaration
    // nothing is linked yet, sicne the fucntion used needs the definition
    std::cout << a  << std::endl;
}

/*
 *
 *
 */

/*


 */