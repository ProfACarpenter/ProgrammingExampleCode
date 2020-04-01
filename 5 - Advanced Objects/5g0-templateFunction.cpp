/*********
Templates are an advanced version of function overloading, so we will start from our level-3 3i0-functionOverload.cpp file.

In this case, we are replacing the int/float/double versions with a single version.  The type of the variable is implicit or explicit, depending on your need.

We can now use any type, although some will have strange outputs (char) or run-time errors (string/complex data types).
*********/
#include <iostream>
#include <string>

template <class T> T cubed(T); // prototype for the function template


int main(){

	int integer = 10;
	float floating = 22.2;
	double doublePrec = 33.33;

	// can hope the compiler knows what T is implicitly like this
	std::cout << integer << " cubed = " << cubed(integer) << std::endl;

	//can specify the type of T like this
	std::cout << floating << " cubed = " << cubed<float>(floating) << std::endl; 

	std::cout << doublePrec << " cubed = " << cubed<double>(doublePrec) << std::endl;


	return 0;
}

// The compiler knows which function to match to based on the input type, since the names are the same

template <class T> 
T cubed(T num){
	return num*num*num;
}
