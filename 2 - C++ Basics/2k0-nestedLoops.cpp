#include <iostream> 

int main(){   

	// Loops can exist inside of each other, as if-statements could
	// This would be nesting loops

	// This is particularly useful if you have multidimensional arrays

	int array[2][2];

	// First, we will use nested loops to populate
	for(int i = 0; i < 2; i++){ // i is the row
		for(int j = 0; j < 2; j++){ // j is the column
			array[i][j] = i*10+j;
			std::cout << array[i][j] << "\t"; 
		}
		std::cout << std::endl; //this will do a new line for each row
	}

	return 0; 
} // end of main
