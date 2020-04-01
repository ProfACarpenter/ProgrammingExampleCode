/****** 
This program will demonstrate use of a function;
******/
#include <iostream>
#include <ctime>
#include <cstdlib>

// A function is a way to offload parts of your code to a resuable, modular space
// This is a trivial version, just to show you syntax
// The function has no inputs or outputs, but does contain useful code within it
void printTheTime(){
	time_t localTime = time(0); // this is a time variable for system time
	std::cout << asctime(localtime(&localTime)) << std::endl; //this is how you print system time in a human readable format
}

int main(){

	std::cout << "The current system time is: ";
	printTheTime();


	return 0;
}