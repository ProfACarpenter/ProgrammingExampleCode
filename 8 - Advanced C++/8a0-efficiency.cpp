/************
Efficiency in code is about how many lines of code, how much memory, and how complex the operations are.  We will talk about overall performance in terms of just time for now.
************/
// Thanks to www.pluralsight.com for the pieces of code regarding the timing

#include <iostream>
#include <chrono> //high-resolution clock

int main(){

	auto start = std::chrono::high_resolution_clock::now(); 
	// Code to time:
	int array[4] = {0};

	for(int i = 0; i < 4; i++){
		array[i] = 2*i+1;

	}

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedSmall = finish - start;
	std::cout << "Elapsed time for array of 4: " << elapsedSmall.count() << " s\n";

	// Code to time (part 2)

	start = std::chrono::high_resolution_clock::now(); 
	// Code to time:
	int largeArray[4000] = {0};

	for(int i = 0; i < 4000; i++){
		largeArray[i] = 2*i+1;

	}
	finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedLarge = finish - start;
	std::cout << "Elapsed time for array of 4000: " << elapsedLarge.count() << " s\n";

	std::cout << "The 4000 element array sweep is " << (float)elapsedLarge.count()/elapsedSmall.count() << "x longer than the 4 element array.\n";

	return 0;
}


/**
$./a.out
Elapsed time for array of 4: 6.224e-06 s
Elapsed time for array of 4000: 1.3856e-05 s
The 4000 element array sweep is 2.22622x longer than the 4 element array.
**/