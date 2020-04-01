/*****************
A pointer is a variable that holds a memory location of another variable.  It does not have a value the same way that an int/double/float would, but instead points to (or contains the location of) another variable.

You can also access and traverse arrays with pointers

*****************/

#include <iostream>

int main(){
	int intArray[4] = {1,2,3,4};
	double doubleArray[4] = {1.1,2.2,3.3,4.4};

	int *intArrayPtr = &intArray[0];
	double *doubleArrayPtr = &doubleArray[3];

	// When you have an array (or guaranteed contiguous blocks), you can use ++ to go to the next element and -- to go the previous (you can use any arithmetic)
	std::cout << "intArray values from 0 to 3, doubleArray value from 3 to 0\n";
	for(int i = 0; i < 4; i++, intArrayPtr++, doubleArrayPtr--){
		std::cout << *intArrayPtr << " " << *doubleArrayPtr << std::endl;
	}
	// now the intArrayPtr is pointing at the last element
	// The doubleArrayPtr is pointing at the first

	intArrayPtr = &intArray[0];
	doubleArrayPtr = &doubleArray[0];
	// You can also change the values, treating *intArrayPtr as a full name of a variable
	for(int i = 0; i < 4; i++, intArrayPtr++, doubleArrayPtr++){
		(*intArrayPtr) *= 3;
		(*doubleArrayPtr) += 100;
	}
	std::cout << "After changes, intArray values from 0 to 3, doubleArray value from 3 to 0\n";
	intArrayPtr = &intArray[0];
	doubleArrayPtr = &doubleArray[3];
	for(int i = 0; i < 4; i++, intArrayPtr++, doubleArrayPtr--){
		std::cout << *intArrayPtr << " " << *doubleArrayPtr << std::endl;
	}

	std::cout << "Trying to read values from 0 to 7, beyond the boundary\n";
	// you can accidentally go outside the bounds of the array this way.  Let's start the array at 0 and go to 8 and see what prints
	intArrayPtr = &intArray[0];
	doubleArrayPtr = &doubleArray[0];
	for(int i = 0; i < 8; i++, intArrayPtr++, doubleArrayPtr++){
		std::cout << *intArrayPtr << " " << *doubleArrayPtr << std::endl;
	}



}