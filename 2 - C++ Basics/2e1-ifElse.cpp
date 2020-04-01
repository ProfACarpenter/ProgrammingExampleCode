#include <iostream> 

int main(){   

	// If statements are used to make a decision of whether to run a piece of code or not
	// If-else can be used to do an either-or
	// If the if's condition is true, it will run the "if block"
	// If the if's condition is not true, it will skip the if block and go to the else
	// Here is the same code as 2e0, but with an else

	int number;

	std::cout << "Pick a number (integers only): ";
	std::cin >> number;

	int evenOrOdd = number % 2; 
	
	if(evenOrOdd){  
		std::cout << number << " is odd\n";
	}
	else{  // note that the else has no parentheses or conditions.  It is unconditional after the if part is read as false 
		std::cout << number << " is even\n";
	}

	//only the if OR the else can run, but not both.

	return 0; 
} // end of main
