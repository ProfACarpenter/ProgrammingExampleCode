#include <iostream> 

int main(){   

	// There are a lot of operators in C++
	// To operate, you typically save the operators from the right into a single variable on the left side of the equation
	// result = variables and operators

	int x = 7, y = 10;
	// there are arithmetic
	std::cout << x << " + " << y << " = " << (x+y) << std::endl;

	// boolean bitwise logic (does this as binary lined up bit by bit then results a number where each bit was and-ed, or-ed, etc. )
	std::cout << x << " & " << y << " = " << (x&y) << std::endl;

	// boolean logic (treats anything non-zero as a 1) and returns 1 or 0
	std::cout << x << " && " << y << " = " << (x&&y) << std::endl;


	return 0; 
} // end of main
