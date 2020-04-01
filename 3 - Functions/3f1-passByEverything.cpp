#include <iostream>
#include <string>

// Let's compare the different passing options: value, reference, pointer

void valueFunc(int local){
	local -= 50;
	std::cout << "The value inside of the pass by value function is " << local << std::endl;
}

void referenceFunc(int &local){
	local -= 50;
	std::cout << "The value inside of the pass by reference function is " << local << std::endl;
}

void pointerFunc(int *local){
	*local -= 50;  // need to dereference the pointer 
	std::cout << "The value inside of the pass by pointer function is " << *local << std::endl;
}


int main(){

	int valueArg, referenceArg, pointerArg;
	valueArg = 100;
	referenceArg = 777;
	pointerArg = 3;

	std::cout << "valueArg before the function call is " << valueArg << std::endl;
	valueFunc(valueArg);
	std::cout << "valueArg after the function call is STILL " << valueArg << std::endl << std::endl;

	std::cout << "referenceArg before the function call is " << referenceArg << std::endl;
	referenceFunc(referenceArg);
	std::cout << "referenceArg after the function call is NOW " << referenceArg << std::endl << std::endl;

	std::cout << "valueArg before the function call is " << pointerArg << std::endl;
	pointerFunc(&pointerArg); // need the &
	std::cout << "valueArg after the function call is NOW " << pointerArg << std::endl;
	std::cout << "The memory location of pointerArg is " << &pointerArg << std::endl;


	return 0;
}