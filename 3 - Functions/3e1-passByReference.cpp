#include <iostream>
#include <fstream>

// This function takes in an output file by reference
// We wouldn't want to make a copy of the file access, so we pass the address to the file instead.
// Then there are still two integer inputs that pass by value
void printStarsInFile(std::ofstream &, int , int );

int main(int argc, char *argv[]){ // Let's use argc/argv again

	if(argc != 4){
		std::cout << "Usage: ./a.out outputFileName #ofRows #ofColumns \n";
		return 0;
	}
	// This asks the user to specify the output file name
	std::string filename = argv[1];
	std::ofstream outputFile(filename.c_str());

	// atoi convert the ascii input to an integer for our row/col variables
	printStarsInFile(outputFile, atoi(argv[2]), atoi(argv[3]));

	return 0;
}

void printStarsInFile(std::ofstream &file, int row, int col){
	std::cout << row << col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			file << "# ";
		}
		file << std::endl;
	}

}