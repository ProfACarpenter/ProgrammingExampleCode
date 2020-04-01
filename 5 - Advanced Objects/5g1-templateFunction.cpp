/*********
You can have multiple types in a template also.  In this case, it may look strange
*********/
#include <iostream>
#include <string>

template <class T, class U> T cubed(U); // prototype for the function template


int main(){

	int integer = 10;
	float floating = 22.2;
	double doublePrec = 33.33;

	// when you have multiple types, it is a good idea to specify the type, rather than make it implicit
	// Note, we changed the previous file, so the answers printed may look strange
	std::cout << integer << " cubed = " << cubed<int, int>(integer) << std::endl;
	std::cout << floating << " cubed = " << cubed<int, float>(floating) << std::endl; 

	std::cout << doublePrec << " cubed = " << cubed<char, double>(doublePrec) << std::endl;

	// try changing the types and inputs and see what happens

	return 0;
}

// The compiler knows which function to match to based on the input type, since the names are the same

template <class T, class U> 
T cubed(U num){
	return num*num*num;
}
