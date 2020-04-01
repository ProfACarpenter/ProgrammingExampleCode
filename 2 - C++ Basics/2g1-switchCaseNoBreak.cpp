#include <iostream> 

int main(){   

	// Note this is the same as the previous example, but with no breaks
	// if you type in a number it will print each statement starting from the one that it matchs, all the way until a break or the end of the statement

	int number;

	std::cout << " To print my name, choose 1 \n To print my office, choose 2 \n To print my email, choose 3 \n To print my school, choose 4\n";
	std::cin >> number;

	switch(number){
		case 1: std::cout << "Name: Prof. Carpenter\n"; 
		case 2: std::cout << "Office: Dobbs 220\n"; 
		case 3: std::cout << "Email: carpentera1@wit.edu\n"; 
		case 4: std::cout << "School: Wentworth Institute of Technology\n"; 
		default: std::cout << "Invalid input\n"; 

	} //end switch

	return 0; 
} // end of main
