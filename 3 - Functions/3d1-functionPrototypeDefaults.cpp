#include <iostream>


// With defaults, the prototype should list them (no names are necessary)
void printGrid(int = 8, int = 8);


int main(){

	std::cout << "printGrid(4, 4); \n";
	printGrid(4, 4);
	std::cout << "printGrid(); --> defaults of 8: \n";
	printGrid();
	std::cout << "printGrid(2); --> default of 8 for col, but 2 for row:\n";
	printGrid(2);
	std::cout << "printGrid(,2); --> not possible:\n";

	return 0;
}

// The function signature (inputs, return, name) must match the prototype
void printGrid(int row = 8, int col = 8){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			std::cout << "\t" << i << ", "<< j;
		}
		std::cout << std::endl;
	}

}