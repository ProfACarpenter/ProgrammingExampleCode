/*************
An object is a complex a data type also, but one that can include functions for the data.  We will build from 4a0 and 4a1 to make a class and multiple objects.
*************/



#include <iostream>
#include <string> 

class person_c {  // Instead of struct, we need the keyword "class"
	private: // private means only functions within the class definition can directly access the values of the variable
		std::string firstName;  // you can't initialize in a struct
		std::string lastName;
		int birthYear;
		bool YankeesFan;

	public: //public means anyone can access the values as long as the object is within the scope of the call
		void createAPerson(){ // because the function is now encapsulated or grouped with the private section of the class, there is no need to pass in the variable, as it is already in the scope

			std::cout << "Enter a first name: ";
			std::cin >> firstName; // the variable belongs to the class, so no need to give the . notation

			std::cout << "Enter a last name: ";
			std::cin >> lastName;

			std::cout << "Enter a birth year: ";
			std::cin >> birthYear;

			std::cout << "Are you a Yankees Fan? Yes (1), No (0)";
			std::cin >> YankeesFan;

			return; 
		}

		void printAPerson(){ // because the function is now encapsulated or grouped with the private section of the class, there is no need to pass in the variable, as it is already in the scope
			// same code as before, just with a local variable name
			std::cout << firstName << " " << lastName << ", born in " << birthYear << ", is ";

			if(!YankeesFan)
				std::cout << "not "; 

			std::cout << "a fan of the New York Yankees\n";
				return;
		}
};

int main(){

	person_c firstPerson;  // you instantiate an object by giving the definition name and a local variable name, similar to "int x" which is a type then a local name

	firstPerson.createAPerson();
	firstPerson.printAPerson(); 

	
	return 0;
}