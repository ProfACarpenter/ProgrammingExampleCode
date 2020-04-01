#include <iostream> 

int main(){   

	// If statements are used to make a decision of whether to run a piece of code or not

	int number;

	std::cout << "Pick a number (integers only): ";
	std::cin >> number;

	int evenOrOdd = number % 2; 
	// the modulus function returns the remainder of a division. In this case it tells us if the number if divisible by 2 (hence even or odd)


	//if evenOrOdd is 1, it means it had a remainder of 1, hence odd
	if(evenOrOdd){  // could also be written: if(evenOrOdd == 1){
		std::cout << number << " is odd\n";
	}

	if(!evenOrOdd){ // could also be written: if(evenOrOdd == 0){
		std::cout << number << " is even\n";
	}

	return 0; 
} // end of main
