/*************
We will take the bubble sort algorithm and implement it.
*************/

#include <iostream>

const int size = 5;

int main(){

	int array[5] = {10, 4, 3, 8, 1}; 	// random 5 numbers
	int flag;							// flag will track if any swaps have happened; 
										// if not, loop will stop
	int temp = 0; 
	do{
		std::cout << "Start of new pass from beginning to end. \n";
		flag = 0;
		for(int i = 0; i < size-1; i++){
			if(array[i] > array [i+1]){
				// swap the values because they are out of order
				temp = array[i];
				array[i] = array[i+1];
				array[i + 1] = temp;
				flag = 1;
				std::cout << "Swapping " << array[i] << " and " << array [i+1] << std::endl;
				for(int j = 0; j < size; j++)
					std::cout << "\t" << array[j] << " ";
				std::cout << std::endl;
			}
		}
	} while (flag);
	std::cout << "Done now.\n";
	return 0;
}

/**********
$./a.out
Start of new pass from beginning to end. 
Swapping 4 and 10
	4 	10 	3 	8 	1 
Swapping 3 and 10
	4 	3 	10 	8 	1 
Swapping 8 and 10
	4 	3 	8 	10 	1 
Swapping 1 and 10
	4 	3 	8 	1 	10 
Start of new pass from beginning to end. 
Swapping 3 and 4
	3 	4 	8 	1 	10 
Swapping 1 and 8
	3 	4 	1 	8 	10 
Start of new pass from beginning to end. 
Swapping 1 and 4
	3 	1 	4 	8 	10 
Start of new pass from beginning to end. 
Swapping 1 and 3
	1 	3 	4 	8 	10 
Start of new pass from beginning to end. 
Done now.
************/