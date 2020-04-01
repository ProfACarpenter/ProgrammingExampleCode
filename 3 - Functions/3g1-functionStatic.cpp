#include <iostream>
#include <string>

int runningSumWithoutStatic(int num){
	int sum = 0;
	sum += num;
	return sum;
}

int runningSumWithStatic(int num){
	static int sum = 0; // this line is only read/initialized the FIRST time the function is called
						// In subsequent function calls, it retains the previous value
	sum += num;
	return sum;
}

int main(){

	int number = 0;
	
	do{
		std::cout << "Give a number to add to the total, enter -1 to exit: ";
		std::cin >> number;
		if(number == -1)
			break;
		std::cout << "Without Static: " << runningSumWithoutStatic(number) << std::endl;
		std::cout << "With Static: " << runningSumWithStatic(number) << std::endl;

	} while(number != -1);


	return 0;
}