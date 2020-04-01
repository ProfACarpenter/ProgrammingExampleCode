/*************
STLs (Standard Template Libraries) allow us to reuse previously created code. They include various algorithms, data structures, and more.
Here will do an example with the vector STLs
*************/

#include <iostream>
#include <vector> // library file for std::vector
#include <algorithm> //gives us a suite of algorithms that interact with the std::vector<>

int main(){

	// a vector (or any stl) can include any type
	// it is a template class, so we must give it a t ype an use it's interface

	std::vector<int> vectorOfNumbers; // instead of int, could use string, char, double, ...

	int another = 1;
	do{

		int num;
		std::cout << "Add a number: ";
		std::cin >> num;

		vectorOfNumbers.push_back(num);

		// need to make an iterator that matches the type
		// .begin and .end mark the beginning and end of the vector (sort of like head and tail)
		// the iterator will be a pointer to your data, so we need to dereference it
		for(std::vector <int> :: iterator it = vectorOfNumbers.begin(); 
					it != vectorOfNumbers.end(); 
					it++){
			std::cout << *it << " ";
		}
		std::cout << std::endl;
				

		std::cout << "Another (0 for no, 1 for yes)? ";
		std::cin >> another;
	}while(another);

	std::cout << "Now sort them: \n";
	sort(vectorOfNumbers.begin(), vectorOfNumbers.end());
	for(std::vector <int> :: iterator it = vectorOfNumbers.begin(); 
					it != vectorOfNumbers.end(); 
					it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Can also pop or erase \n";

	vectorOfNumbers.pop_back();
	
	for(std::vector <int> :: iterator it = vectorOfNumbers.begin(); 
					it != vectorOfNumbers.end(); 
					it++){
		std::cout << *it << " ";
	}

}
