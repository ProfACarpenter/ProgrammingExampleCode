/**********
Let's expand on the previous example, and add functions
**********/

#include <iostream>
#include <string> 

struct person_s {  // I often use "_s" as a way to identify struct data types
	std::string firstName;  // you can't initialize in a struct
	std::string lastName;
	int birthYear;
	bool YankeesFan;
};

void printAPerson(person_s &tempPerson); 
person_s createAPerson(); //structs can be inputs and outputs of a function

int main(){

	person_s people[4]; // can be used as array also

	for(int i = 0; i < 4; i++){
		people[i] = createAPerson();
	}

	for(int i = 0; i < 4; i++){
		printAPerson(people[i]); 
	}

	return 0;
}

person_s createAPerson(){ //structs can be inputs and outputs of a function
	person_s tempPerson;  // just make a temporary space that will copy things back at the end

	std::cout << "Enter a first name: ";
	std::cin >> tempPerson.firstName; 

	std::cout << "Enter a last name: ";
	std::cin >> tempPerson.lastName;

	std::cout << "Enter a birth year: ";
	std::cin >> tempPerson.birthYear;

	std::cout << "Are you a Yankees Fan? Yes (1), No (0)";
	std::cin >> tempPerson.YankeesFan;

	return tempPerson; // this will return a struct filled with all the things we added here in the function
}

void printAPerson(person_s &tempPerson){ //in order to not make a copy, we can do this by reference	
	// same code as before, just with a local variable name
	std::cout << tempPerson.firstName << " " << tempPerson.lastName << ", born in " << tempPerson.birthYear << ", is ";

	if(!tempPerson.YankeesFan)
		std::cout << "not "; 

	std::cout << "a fan of the New York Yankees\n";
	return;
}