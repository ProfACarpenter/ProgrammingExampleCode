/****************************
The purpose of this file is to demonstrate how to compile C++ using command line Linux/Unix OS

Create the code files with the file extension .cpp
If the code file was named myCode, it would be myCode.cpp
Within command line, you can use nano, vim, or emacs to create the files

$ nano myCode.cpp
will open a new file of the name myCode.cpp
If the file already exists, it will open the existing file
nano is simpler to use, but vim is more powerful
emacs is powerful, also, but less used (in my experience)

Once you have typed the code and saved it and existed...
$ g++ -g myCode.cpp
This will compile the code using the compiler g++.  -g is an optional flag that will help later with debugging.  The final executable will be called a.out
If you want to name the output executable something else:
$ g++ -g -o myCode.out myCode.cpp
will compile the executable to myCode.out (or whatever you name it)

If there are errors, it will give them on the screen.  You will need troubleshoot.  If no errors print, your executable is there.

$ ./a.out will run the code

****************************/
// There are plenty of includes
#include <iostream>    	// for user I/O
#include <fstream> 		// for file I/O
#include <cmath>		// for mathematical functions beyond operators
#include <string>		// for string manipulation
#include <cstdlib> 		// for random, memory, other C libraries
// There are more: https://en.cppreference.com/w/cpp/header
// Can also include other header files that the programmer defines, but use quotes
// #include "headerFiles.h"


int main(){   

	std::cout << "Use nano and vim to create/edit text files \n";
	std::cout << "Use \"g++ -g filename.cpp\" to compiled \n";
	std::cout << "Use \"./a.out\" to execute \n";

	return 0; 
} // end of main