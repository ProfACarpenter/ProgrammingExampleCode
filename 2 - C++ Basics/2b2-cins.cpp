#include <iostream> 

int main(){   

	// creating three integer (non-fractional) number variables and setting them to 0
	int x = 0;
	int y = 0;
	int z = 0;

	std::cout << "Please enter three numbers, separated by spaces, and hit enter: \n";
	std::cin >> x >> y >> z;

	std::cout << "You entered " << x << " " << y << " and " << z << std::endl;
	// Note you must enter spaces and new lines manually, but can do it all in one line
	// You can also do operators directly in the line
	std::cout << x+y+z << " = " << x << " + " << y << " + " << z << std::endl;

	// I have written this way to show the way c++ will do equations, evaluating from right to left

	return 0; 
} // end of main