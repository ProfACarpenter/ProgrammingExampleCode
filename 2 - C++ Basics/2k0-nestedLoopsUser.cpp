#include <iostream> 

int main(){   

	// You can use the array elements, each with its own index, as you would a variable
	// You can also fill the values from the user or file I/O

	int array[2][2];

	// First, we will use nested loops to populate
	for(int i = 0; i < 2; i++){ // i is the row
		for(int j = 0; j < 2; j++){ // j is the column
			std::cout << "Enter a number for the " << i << " " << j << " element:";
			std::cin >> array[i][j];
		}
	}

	for(int i = 0; i < 2; i++){ // i is the row
		for(int j = 0; j < 2; j++){ // j is the column
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "The sum of the top row is: " << (array[0][0] + array[0][1]) << std::endl;
	std::cout << "The sum of the bottom row is: " << (array[1][0] + array[1][1]) << std::endl;

	return 0; 
} // end of main
