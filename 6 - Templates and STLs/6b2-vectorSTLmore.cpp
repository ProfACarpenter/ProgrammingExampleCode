/*************
STLs (Standard Template Libraries) allow us to reuse previously created code. They include various algorithms, data structures, and more.
Here will do an example with the vector STLs.
This time, with structs, instead of a standard variable type. It could also be a class.
*************/

#include <vector> // library file for std::vector
#include <algorithm> 
#include <iostream>

struct person_s {  
	std::string name; 
	int birthYear;
	bool YankeesFan;
};

void printAPerson(person_s *tempPerson); 

int main(){

	std::vector<person_s *> vectorOfPersonPointers;

	int another = 1;
	do{
		person_s *personPointer = new person_s;
		std::cout << "Give a name and year: ";
		std::cin >> personPointer->name >> personPointer->birthYear;
		personPointer->YankeesFan = true;

		vectorOfPersonPointers.push_back(personPointer);

		for(std::vector <person_s *> :: iterator it = vectorOfPersonPointers.begin(); 
					it != vectorOfPersonPointers.end(); 
					it++){
			printAPerson(*it);
		}

		std::cout << "Another (0 for no, 1 for yes)? ";
		std::cin >> another;
	}while(another);

	std::string tempName;
	std::cout << "Choose a name to delete (you only get one chance): ";
	std::cin >> tempName;
	// can search for members of the struct to match
	for(std::vector <person_s *> :: iterator it = vectorOfPersonPointers.begin(); 
					it != vectorOfPersonPointers.end(); 
					it++){
		// need to do *it, because it is a pointer to the elements in the vector which are themselves pointers.  So we need to dereference the iterator pointer to get to the struct pointer
		if((*it)->name == tempName){
			std::cout << (*it)->name << " is being erased.\n";
			vectorOfPersonPointers.erase(it);
			break; // if you don't break, it will likely result in a seg fault
		}
	}	
	std::cout << "Now these people remain: \n";
	for(std::vector <person_s *> :: iterator it = vectorOfPersonPointers.begin(); 
					it != vectorOfPersonPointers.end(); 
					it++){
			printAPerson(*it);
	}


	return 0;
}

void printAPerson(person_s *tempPerson){ //in order to not make a copy, we can do this by reference	
	// same code as before, just with a local variable name
	std::cout << tempPerson->name << ", born in " << tempPerson->birthYear << ", is ";

	if(!tempPerson->YankeesFan)
		std::cout << "not "; 

	std::cout << "a fan of the New York Yankees\n";
	return;
}