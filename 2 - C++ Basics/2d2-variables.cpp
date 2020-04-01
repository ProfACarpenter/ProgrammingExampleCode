#include <iostream> 

int main(){   

	// There are a lot of types of variables
	// Here we list the high value of each

	int integer = 2147483647;
	short shortInteger = 32767;
	unsigned unsignedInteger = 4294967295;
	
	char character = char(255);  
	//Characters are saved as number values, and can be operated on as numbers, but print as characters from the ASCII table (google it)
	std::string bunchOfCharacters = "Hello, World";
	
	float floatingPoint = 3.40282e+038;
	double doubleFloatingPoint = 1.79769e+308;

	bool eitherTrueOrFalse = true;
	
	std::cout << "The highest value for an integer: " << integer << std::endl;
	std::cout << "The highest value for an short: " << shortInteger << std::endl;
	std::cout << "The highest value for an unsigned: " << unsignedInteger << std::endl;

	std::cout << "The highest value for a char: " << character << std::endl;
	std::cout << "The highest value for a float: " << floatingPoint << std::endl;
	std::cout << "The highest value for a double: " << doubleFloatingPoint << std::endl;

	std::cout << "A bool can be: " << eitherTrueOrFalse << " or " << !eitherTrueOrFalse << std::endl;

	return 0; 
} // end of main
