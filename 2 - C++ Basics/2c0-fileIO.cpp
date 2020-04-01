#include <iostream> 
#include <fstream> // To use files, we need to include a new library "fstream"

int main(){   

	// Open/read files
	std::ifstream inputFile("2c0-inputTest.txt");
	/******* or 
	std::ifstream inputFile;
	inputFile.open("2c0-inputTest.txt");
	*******/

	std::ofstream outputFile("2c0-outputTest.txt");
	/******* or 
	std::ofstream outputFile;
	outputFile.open("2c0-outputTest.txt");
	*******/

	// To connect your program to an input file (read-only), you use ifstream
	// ifstream is treated as a data type, so you create a variable with any name (in this case we used inputFile)
	// You then connect it to the existing file in the directory in quotes

	// For output files, it is the same, except you use ofstream
	// If the file already exists, it will write over it
	// Note you can open a file to read AND write by using fstream as the data type

	// Once the file is open, you treat it the same way as you treat cout and cin

	int num1, num2, num3, num4;
	inputFile >> num1 >> num2 >> num3 >> num4;

	outputFile << num1 << " + " << num2 << " - " << num3 << " * " << num4 << " is: ";
	outputFile << num1+num2-num3*num4 << std::endl;

	inputFile.close(); //close the file to disconnect it from the program
	outputFile.close();

	return 0; 
} // end of main