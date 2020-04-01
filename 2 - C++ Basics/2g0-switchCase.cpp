#include <iostream> 

int main(){   

	// as an alternative to if-else, we can use switch-case statements
	// inside the case, you put a variable you want to compare
	// then each case is compared against that variable
	// the one that matches starts execution of that block
	// you then need to put a "break," which will exit the switch block
	// if you don't put a break, it will continue to the next section
	// default is used as a catch-all in case no case value matches

	int number;

	std::cout << " To print my name, choose 1 \n To print my office, choose 2 \n To print my email, choose 3 \n To print my school, choose 4\n";
	std::cin >> number;

	switch(number){
		case 1: std::cout << "Name: Prof. Carpenter\n"; break;
		case 2: std::cout << "Office: Dobbs 220\n"; break;
		case 3: std::cout << "Email: carpentera1@wit.edu\n"; break;
		case 4: std::cout << "School: Wentworth Institute of Technology\n"; break;
		default: std::cout << "Invalid input\n"; break;

	} //end switch

	return 0; 
} // end of main
