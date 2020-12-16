/*************
We will take the bubble sort algorithm and implement it.
*************/

#include <iostream>

const int size = 5;

int main(){

	int array[5] = {10, 4, 3, 8, 1}; 	// random 5 numbers

	for(int j = 0; j < size; j++)
		std::cout << "\t" << array[j] << " ";
	std::cout << std::endl;

	// the outer loop will start at the first element
	// the inner loop will then iterate through the remainder of the list, only going up in index
	// once the inner loop reaches the end, the current element from the outer (scan) loop will 
	// swap with the inner (minimumIndex) loop
	for(int scan = 0; scan < size-1; scan++){
		std::cout << "Moving to the " << scan << " element.\n";
		int minimumIndex = scan;
		int minimumValue = array[scan];
		for(int searchIndex = scan+1; searchIndex < size; searchIndex++){
			if(array[searchIndex] < minimumValue){
				minimumValue = array[searchIndex];
				minimumIndex = searchIndex;
			}
		}
		int temp = array[minimumIndex];
		array[minimumIndex] = array[scan];
		array[scan] = temp;
		std::cout << "Swapping " << array[minimumIndex] << " and " << array [scan] << std::endl;
		for(int j = 0; j < size; j++)
			std::cout << "\t" << array[j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Done now.\n";
	return 0;
}

/**********
$./a.out
	10 	4 	3 	8 	1 
Moving to the 0 element.
Swapping 10 and 1
	1 	4 	3 	8 	10 
Moving to the 1 element.
Swapping 4 and 3
	1 	3 	4 	8 	10 
Moving to the 2 element.
Swapping 4 and 4
	1 	3 	4 	8 	10 
Moving to the 3 element.
Swapping 8 and 8
	1 	3 	4 	8 	10 
Done now.

************/