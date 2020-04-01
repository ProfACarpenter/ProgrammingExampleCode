/****** 
This program will demonstrate use of a function;
******/
#include <iostream>
#include <string>

// A function is a way to offload parts of your code to a resuable, modular space
// This is a trivial version, just to show you syntax
float equation(float a, float b, float c){
	float result = a*a+b*c/2;
	return result;

}

int main(){
	std::cout << "Give three floats: ";
	float a, b, c; //variables in the main and the function CAN, but don't have to share a name
	std::cin >> a >> b >> c;

	float result = equation(a,b,c);
	std::cout << "The result is " << result << std::endl;

	return 0;
}