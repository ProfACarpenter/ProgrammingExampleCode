#include <iostream>
#include <string>

int multiply(int, int);
int multiply(int, int, int);
int multiply(int, int, int, int);

int main(){

	int number[4] = {0};
	int times;


	std::cout << "How many numbers do you want to multiply together (2-4)? ";
	std::cin >> times;
	std::cout << "Enter the numbers: ";
	for(int i = 0; i < times; i++){
		std::cin >> number[i];
	}

	if(times == 2){
		std::cout << multiply(number[0], number[1]) << std::endl;
	}else if(times == 3){
		std::cout << multiply(number[0], number[1], number[2]) << std::endl;
	}else if(times == 4){
		std::cout << multiply(number[0], number[1], number[2], number[3]) << std::endl;
	}else
		std::cout << "Must be between 2 and 4";

	return 0;
}

// The compiler knows which function to match to based on the input type, since the names are the same

int multiply(int a, int b){
	return a*b;
}

int multiply(int a, int b, int c){
	return a*b*c;
}

int multiply(int a, int b, int c, int d){
	return a*b*c*d;
}