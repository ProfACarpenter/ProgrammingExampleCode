#include <iostream> 

int main(){   

	// break stops a loop immediately and goes to the line after the loop (note ONLY that loop; in the case of nested loops)
	// continue ends the ITERATION of the loop, but continues to the NEXT iteration

	const int size = 10; // this size value won't change anywhere, so I can make it const

	int sum = 0;
	int choice = 0;

	int numbers[size] = {4, 2, 1, 4, 0, -1, 4, 7, 9, -3};

	for(int i = 0; i < size; i++){
		if(numbers[i] < 0){
			std::cout << "Skipping a negative number\n";
			continue; // I don't want to add a negative numbers, so this will skip this iteration and jump to the next iteration/array number
		}

		std::cout << "The current number is " << numbers[i] << " and sum is " << sum << std::endl;
		sum += numbers[i];
		std::cout << "The sum is now: " << sum << std::endl;
		std::cout << "Do you want to keep summing (1 for yes, 0 for no)? ";
		std::cin >> choice;
		if(choice == 0){
			break; // This will exit the loop and go directly to the final sum print
		}

	}
	std::cout << "The final sum is " << sum << std::endl;

	return 0; 
} // end of main
