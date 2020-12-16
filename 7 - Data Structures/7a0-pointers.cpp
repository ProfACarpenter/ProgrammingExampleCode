/*****************
A pointer is a variable that holds a memory location of another variable.  It does not have a value the same way that an int/double/float would, but instead points to (or contains the location of) another variable.

*****************/

#include <iostream>

int main(){
	// These are just to give some variables
	int intVar = 100;
	double doubleVar = 1.11;
	std::string stringVar = "A";

	int *intPtr = &intVar;
	double *doublePtr = &doubleVar;
	std::string *stringPtr = &stringVar;

	std::cout << "The value " << intVar << " is held at memory location " << intPtr << std::endl;
	// it could also be:
	// std::cout << "The value " << intVar << " is held at memory location " << &intVar << std::endl;

	std::cout << "The value " << doubleVar << " is held at memory location " << doublePtr << std::endl;
	
	std::cout << "The value " << stringVar << " is held at memory location " << stringPtr << std::endl;
	
	std::cout << "---------\n";
	// Let's say you only have a pointer, you can change/read the values by dereferencing

	std::cout << "When you dereference intPtr " << intPtr <<", you get the value back: " << *intPtr << std::endl;
	std::cout << "When you dereference doublePtr " << doublePtr <<", you get the value back: " << *doublePtr << std::endl;
	std::cout << "When you dereference stringPtr " << stringPtr <<", you get the value back: " << *stringPtr << std::endl;

	std::cout << "---------\n";
	std::cout << "When you get * and & next to each other, they cancel: " << *(&intVar) << std::endl;

}