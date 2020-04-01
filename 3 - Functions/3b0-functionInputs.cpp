#include <iostream>
#include <string>

// function declarations must be done earlier in the code than the function call
void printString(std::string localString){
	std::cout << "String entered is: " << localString << std::endl;
}

void printInt(int localInt){
	std::cout << "Int entered is: " << localInt << std::endl;
}

void printFloat(float localFloat){
	std::cout << "Float entered is: " << localFloat << std::endl;
}

void functionCall(std::string functionString, int functionInt, float functionFloat){

	printString(functionString);
	printInt(functionInt);
	printFloat(functionFloat);

	return;
}

int main(){
	std::string stringVar;
	int intVar;
	float floatVar;

	// inputs can take many numbers and forms, and can also pass along to other functions
	std::cout << "Give a string, an int, and a float: \n";
	std::cin >> stringVar >> intVar >> floatVar;
	functionCall(stringVar, intVar, floatVar);

	std::cout << "Give another string, an int, and a float: \n";
	std::cin >> stringVar >> intVar >> floatVar;

	printString(stringVar);
	printInt(intVar);
	printFloat(floatVar);

	return 0;
}