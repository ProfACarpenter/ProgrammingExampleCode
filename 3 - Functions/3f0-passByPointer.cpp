#include <iostream>
#include <string>

// If we wanted to use pointers, we could pass those into functions also
// This is more direct and syntactically difficult compared to pass by value or reference

// We will use 3e2 as the starting point

#include <iostream>
#include <string>

// Let's create a struct
struct person_s{
	std::string first, last;
	int birthYear;
	int ageIfAlive;
};

// This function will actually get access to the personA, B, C from main by reference, as opposed to making a copy

void printPerson(person_s *);

int main(){

	person_s personA, personB, personC;

	personA.first = "Ada";
	personA.last = "Lovelace";
	personA.birthYear = 1815; // note we are not initializing the "ageIfAlive"

	personB.first = "John";
	personB.last = "von Neumann";
	personB.birthYear = 1903;

	personC.first = "Katherine";
	personC.last = "Johnson";
	personC.birthYear = 1918;

	printPerson(&personA); // a pointer is a memory address, so we must pass the address of the structure (& should be read in this case as "the address of")
	printPerson(&personB);
	printPerson(&personC);

	return 0;
}


// At the function, we now have a pointer "localPerson" that contains a memory address to the structure.  In itself, it is not a structure, just the address of one
// To use it, we can dereference the pointer first
void printPerson(person_s *localPerson){
	(*localPerson).ageIfAlive = 2020 - (*localPerson).birthYear;
	std::cout << (*localPerson).first << " " << (*localPerson).last << " would be " << (*localPerson).ageIfAlive << " years old, if they were still alive today \n";
}

// We could also use the -> which is * . combined
/*
void printPerson(person_s *localPerson){
	localPerson->ageIfAlive = 2020 - localPerson->birthYear;
	std::cout << localPerson->first << " " << localPerson->last << " would be " << localPerson->ageIfAlive << " years old, if they were still alive today \n";
}
*/