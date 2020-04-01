#include <iostream> 

int main(int argc, char * argv[]){   

	//argc counts the number of inputs (separated by spaces) in the command line
	//argv is an array of the actual inputs

	for(int i = 0; i < argc; i++){
		std::cout << "Input " << i << " " << argv[i] << std::endl;
	}
	// Note the first input in argv is the executable call

	// After compiling, use ./a.out input0 input1 input2
	// e.g. 
	// $./a.out First 2 3rd

	return 0; 
} // end of main
