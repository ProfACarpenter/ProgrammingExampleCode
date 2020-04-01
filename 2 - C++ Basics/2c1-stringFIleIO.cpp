#include <iostream> 
#include <fstream> // To use files, we need to include a new library "fstream"

int main(){   

	// Open/read files
	std::ifstream inputFile("2c1-inputTest.txt");

	std::ofstream outputFile("2c1-outputTest.txt");

	// Strings are words are adjacent characters
	// Here we take a strings from separate lines and put into a new file

	std::string first, last, school, email;
	inputFile >> first >> last >> school >> email;
	//each input is separated by an enter or a space

	outputFile << "For help, contact: \n";
	outputFile << "\t Name: " << first << " " << last << std::endl;
	outputFile << "\t School: " << school << std::endl;
	outputFile << "\t Email: " << email << std::endl;
				// \t is used as a way to tab words over

	inputFile.close(); //close the file to disconnect it from the program
	outputFile.close();

	return 0; 
} // end of main
