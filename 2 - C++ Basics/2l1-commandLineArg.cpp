#include <iostream> 

int main(int argc, char * argv[]){   

	// argc counts the number of inputs (separated by spaces) in the command line
	// argv is an array of the actual inputs
	// It is important if you are expecting a certain number of inputs that you check for them
	if(argc <= 2){
		std::cout << "Usage: ./a.out <name> <score1> <score2> ... <scoreN> \n";
		std::cout << "example: $./a.out Aaron 4.1 100 9.1 2.3 \n"
		return 0;
	}

	std::cout << argv[1] << "\'s average is: ";

	float sum = 0;
	for(int i = 2; i < argc; i++){
		sum += atof(argv[i]);
	}
	std::cout << sum/(argc-2) << std::endl;




	return 0; 
} // end of main
