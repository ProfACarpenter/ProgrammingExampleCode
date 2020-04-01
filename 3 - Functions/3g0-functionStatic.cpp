#include <iostream>
#include <string>

int functionCall(){
	int counter = 0;
	counter++;
	return counter;
}

int functionCallCounter(){
	static int counter = 0; // this line is only read/initialized the FIRST time the function is called
							// In subsequent function calls, it retains the previous value
	counter++;
	return counter;
}

int main(){

	std::cout << "With static: \n";
	for(int i = 0; i < 10; i++){
		std::cout << functionCallCounter() << std::endl;
	}
	std::cout << "Without static: \n";
	for(int i = 0; i < 10; i++){
		std::cout << functionCall() << std::endl;
	}
	return 0;
}