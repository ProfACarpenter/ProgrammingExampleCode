#include <iostream>
#include <string>

int cubed(int);
float cubed(float);
double cubed(double);

int main(){

	int integer = 10;
	float floating = 22.2;
	double doublePrec = 33.33;

	std::cout << integer << " cubed = " << cubed(integer) << std::endl;
	std::cout << floating << " cubed = " << cubed(floating) << std::endl;
	std::cout << doublePrec << " cubed = " << cubed(doublePrec) << std::endl;


	return 0;
}

// The compiler knows which function to match to based on the input type, since the names are the same

int cubed(int num){
	return num*num*num;
}

float cubed(float num){
	return num*num*num;
}

double cubed(double num){
	return num*num*num;
}