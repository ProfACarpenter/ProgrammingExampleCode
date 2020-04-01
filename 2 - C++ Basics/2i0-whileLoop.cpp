#include <iostream> 

int main(){   

	// You can essentially write all loops with for/while/do-while
	// The convention is to use while loops when you have a less predictable iteration count and just need a flag to turn off the loop
	// In this case, we will show the same code as the for loop but with a while loop
	int array[4] = {100, 200, 300, 400};

	// while loops don't have initialization or updates, so these would need to be done manually if you want them
	int i = 0;
	while(i < 4){
		std::cout << "Array[" << i << "] is " << array[i] << std::endl;
		i++;
	}

	/***** another way to write a while loop for the above using a flag
	int i = 0;
	bool flag = true;
	while(flag){
		std::cout << "Array[" << i << "] is " << array[i] << std::endl;
		i++;
		if(i>=4)
			flag = false;
	}

	*****************************************************/

	std::cout << "We will now add values to each array element: \n";

	int j = 0;
	int k = 100;
	while(j < 4){
		array[j] += k;
		std::cout << "Array[" << j << "] is now " << array[j] << std::endl;
		j++;
		k-=5;
	}

	return 0; 
} // end of main
