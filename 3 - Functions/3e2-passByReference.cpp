#include <iostream>
#include <string>

// Let's create a struct
struct person_s{
	std::string first, last;
	int birthYear;
	int ageIfAlive;
};

// This function will actually get access to the personA, B, C from main by reference, as opposed to making a copy

void printPerson(person_s &);

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

	printPerson(personA);
	printPerson(personB);
	printPerson(personC);

	return 0;
}

void printPerson(person_s &localPerson){
	localPerson.ageIfAlive = 2020 - localPerson.birthYear;
	std::cout << localPerson.first << " " << localPerson.last << " would be " << localPerson.ageIfAlive << " years old, if they were still alive today \n";
}