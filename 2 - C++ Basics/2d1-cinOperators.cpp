#include <iostream> 

int main(){   

	int x, y;
	
	std::cout << "Enter two integers: ";
	std::cin >> x >> y;

	// We can use cin to get numbers
	// We can also chain operations together, which will be done sequentially from top to bottom
	int sum = x + y;
	int diff = x - y;
	int productOfBoth = sum*diff;

	std::cout << x << " plus " << y << " is " << sum << std::endl;
	std::cout << x << " minus " << y << " is " << diff << std::endl;
	std::cout << sum << " times " << diff << " is " << productOfBoth << std::endl;
	
	return 0; 
} // end of main
