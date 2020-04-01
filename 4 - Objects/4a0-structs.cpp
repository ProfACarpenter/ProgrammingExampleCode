/**********
Struct - a struct is a complex data type.  We explored it a bit with operator overloading in 3i2-operatorOverload.cpp at the end of the last section.

Now we will explore structs further.

A struct is a grouping of multiple variables into a single entity.  We then use that structure to create multiple instantiations of the same type.  
**********/

#include <iostream>
#include <string> 

struct person_s {  // I often use "_s" as a way to identify struct data types
	std::string firstName;  // you can't initialize in a struct
	std::string lastName;
	int birthYear;
	bool YankeesFan;
};

// now with a globally created data type of "person_s," we can create real versions and manipulate the variables

int main(){

	person_s firstPerson;  // you instantiate a struct by giving the definition name and a local variable name, similar to "int x" which is a type then a local name

	// Not we don't need intermediate variable here and go straight to the variables within the struct.  Remember each struct instantiation has all the variables 

	std::cout << "Enter a first name: ";
	std::cin >> firstPerson.firstName; // you access parts of a struct with the .
									   // so to read/write the variable it is:
									   // structDefinitionName.variableName
	std::cout << "Enter a last name: ";
	std::cin >> firstPerson.lastName;

	std::cout << "Enter a birth year: ";
	std::cin >> firstPerson.birthYear;

	std::cout << "Are you a Yankees Fan? Yes (1), No (0)";
	std::cin >> firstPerson.YankeesFan;

	std::cout << firstPerson.firstName << " " << firstPerson.lastName << ", born in " << firstPerson.birthYear << ", is ";

	if(!firstPerson.YankeesFan) // this will be either 0 or 1
								// You can use the variables within a struct as you would a typical variable, just with an extra level of hierarchy
		std::cout << "not "; 

	std::cout << "a fan of the New York Yankees\n";

	
	return 0;
}