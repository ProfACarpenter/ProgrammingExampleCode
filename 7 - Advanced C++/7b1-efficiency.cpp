/************
Efficiency in code is about how many lines of code, how much memory, and how complex the operations are.  We will talk about overall performance in terms of just time for now.
************/
// Thanks to www.pluralsight.com for the pieces of code regarding the timing

#include <iostream>
#include <chrono> //high-resolution clock


void slowerFunc(){
	int a, b, c, d, e, f, g, h;
	a = 1; 
	b = 2;
	c = 3;
	d = 4;
	e = 5;

	f = a + b;
	g = c + d;
	h = f + g;
	h = h + e;

	std::cout << "h = " << h << std::endl;
}

void fasterFunc(){
	int a = 1, b = 2, c = 3, d = 4, e = 5;

	std::cout << "h = " << (a+b+c+d+e) << std::endl;
}

int main(){

	auto start = std::chrono::high_resolution_clock::now(); 
	// Code to time:
	
	slowerFunc();

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedSmall = finish - start;
	std::cout << "Elapsed time for multi-line addition: " << elapsedSmall.count() << " s\n";
	start = std::chrono::high_resolution_clock::now(); 

	// Code to time (part 2)
	fasterFunc();
	
	finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedLarge = finish - start;
	std::cout << "Elapsed time for single-line addition: " << elapsedLarge.count() << " s\n";

	std::cout << "The first run takes " << (float)elapsedSmall.count()/elapsedLarge.count() << "x longer than the second run.\n";

	return 0;
}

/**
$./a.out
h = 15
Elapsed time for multi-line addition: 9.0523e-05 s
h = 15
Elapsed time for single-line addition: 2.057e-06 s
The first run takes 44.0073x longer than the second run.
**/