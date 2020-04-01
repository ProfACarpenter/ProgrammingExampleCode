/****** 
This program will demonstrate use of a function;
******/
#include <iostream>
#include <string>

// A function is a way to offload parts of your code to a resuable, modular space
// This is a trivial version, just to show you syntax
void printSomething(std::string something){
	std::cout << "You asked me to print " << something << ", so there you go. \n";
	return;
}

int main(){
	std::string stringInput;
	std::cout << "Give something to print: ";
	std::cin >> stringInput;

	printSomething(stringInput);

	return 0;
}