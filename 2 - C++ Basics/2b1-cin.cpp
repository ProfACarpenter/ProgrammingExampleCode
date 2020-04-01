#include <iostream> 

int main(){   

	// cin is how the user can give inputs to the program

	string name; // a string is a sequence of characters 

	std::cout << "Please enter your name: "; //display instructions to the user

	std::cin >> name; 

	// this will take the characters typed by the user
	// with this structure, it will capture the characters until they reach a white space (return/enter key, space, tab)
	// the user input will then be in the name variable

	std:cout << "Hello, " << name << std::endl;
	//std:endl is another way to create a new line

	return 0; 
} // end of main