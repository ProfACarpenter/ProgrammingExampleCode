#include <iostream> 
#include <fstream> 

int main(){   

	std::ifstream inputFile("2c2-inputTest.txt");

	std::ofstream outputFile("2c2-outputTest.txt");

	// Let's say I want to take in the whole name at once instead of separately
	// the >> operator looks for spaces/enters/tabs, but not the whole line

	std::string name, school, email;
	getline(inputFile, name);
	getline(inputFile, school);
	getline(inputFile, email);
	

	outputFile << "For help, contact: \n";
	outputFile << "\t Name: " << name << std::endl;
	outputFile << "\t School: " << school << std::endl;
	outputFile << "\t Email: " << email << std::endl;
				// \t is used as a way to tab words over

	inputFile.close(); //close the file to disconnect it from the program
	outputFile.close();

	return 0; 
} // end of main
