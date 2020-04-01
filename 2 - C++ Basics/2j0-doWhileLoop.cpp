#include <iostream> 

int main(){   

	// A do-while loop is a while loop that does one iteration unconditionally
	// The first iteration will happen no matter what
	// After the first iteration, it checks the condition, similar to a while loop

	int array[4] = {100, 200, 300, 400};

	// do-while loops don't have initialization or updates, so these would need to be done manually if you want them
	int i = 0;
	do{
		std::cout << "Array[" << i << "] is " << array[i] << std::endl;
		i++;
	}while(i < 4); //notice the semicolon

	std::cout << "We will now add values to each array element: \n";

	int j = 0;
	int k = 100;
	do{
		array[j] += k;
		std::cout << "Array[" << j << "] is now " << array[j] << std::endl;
		j++;
		k-=5;
	}while(j < 4);

	return 0; 
} // end of main
