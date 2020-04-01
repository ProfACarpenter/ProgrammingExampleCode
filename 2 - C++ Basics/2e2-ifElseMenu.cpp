#include <iostream> 

int main(){   

	// If-else can also be chained together

	int number;

	std::cout << " To print my name, choose 1 \n To print my office, choose 2 \n To print my email, choose 3 \n To print my school, choose 4\n";
	std::cin >> number;

	// because the if/elses are chained, only one can happen
	// it is also goo practice to have an else statement
	if(number == 1){
		std::cout << "Name: Prof. Carpenter\n";
	}
	else if(number == 2){
		std::cout << "Office: Dobbs 220\n";
	}
	else if(number == 3){
		std::cout << "Email: carpentera1@wit.edu\n";
	}
	else if(number == 4){
		std::cout << "School: Wentworth Institute of Technology\n";
	}
	else{
		std::cout << "Invalid input\n";
	}

	return 0; 
} // end of main
