#include <iostream>
#include <string>

// Function prototypes/declarations must have a return, a name, and the inputs

float equation(float, float, float);

int main(){
	std::cout << "Give three floats: ";
	float a, b, c; //variables in the main and the function CAN, but don't have to share a name
	std::cin >> a >> b >> c;

	float result = equation(a,b,c);
	std::cout << "The result is " << result << std::endl;

	return 0;
}

//Function definitions can be done later, since the prototypes are declared prior to the function call. These can also be done in a separate file (typically another cpp with the prototypes in a header file)

float equation(float a, float b, float c){
	float result = a*a+b*c/2;
	return result;

}