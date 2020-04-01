#include <iostream> 

int main(){   

	// You can place if statements inside of other if statements
	// This is called "nesting"

	int numberA = 0, numberB = 0;

	std::cout << "Type two integers between 1 and 100, separated by a space: ";
	std::cin >> numberA >> numberB;

	if(numberA <= 100 && numberA >= 1){
		if(numberB <= 100 && numberB >= 1){
			std::cout << "These numbers are within the range.  As a reward, enjoy this picture\n";
			std::cout << "\t  o  	o\n\n";
			std::cout << "\t     o\n\n";
			std::cout << "\too      oo\n";
			std::cout << "\t  oo  oo\n";
			std::cout << "\t    oo\n";
		}
	}

	if(numberA > 100 && numberA < 1){
		if(numberB > 100 && numberB < 1){
			std::cout << "These numbers are outside of the specified range (1-100)\n";
		}
	}



	return 0; 
} // end of main
