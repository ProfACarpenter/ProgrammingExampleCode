#include <iostream> 

int main(){   

	// for loops are ideal for traversing through an array or repeating tasks in a predictable number (you know how many iterations you need and/or you need indices)
	// an array is simply a "table" of values of the same type, more efficiently written

	// note that while the size of this array is 4, the elements are indexed 0, 1, 2, 3
	// array indices are always 0 to size-1
	int array[4] = {100, 200, 300, 400};

	// for loops consist of three parts:
	// initialization: happens one time before any iterations of the loop occur; can have more than 1 statement, separated by commas; initialization ends when a semicolon is reached
	// condition for further iteration: when this condition is true, the loop will continue to iterate; when false, the loop ends
	// update/increment: this happens at the end of each iteration; you can have more than 1 statement, separated by commas

	for(int i = 0; i < 4; i++){
		std::cout << "Array[" << i << "] is " << array[i] << std::endl;
	}

	std::cout << "We will now add values to each array element: \n";
	for(int j = 0, k = 100; j < 4; j++, k-=5){
		array[j] += k;
		std::cout << "Array[" << j << "] is now " << array[j] << std::endl;
	}

	return 0; 
} // end of main
