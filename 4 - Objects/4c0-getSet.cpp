/*************
We can also use objects in arrays, or create them separately.  The class is still the same, but the objects are individual
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
		void printAPerson();
		void createAPerson();

		// set functions (or mutator functions) set the private variables from a public functions; it is also a good idea to add input checking here, but is not required; in this case, we won't do that checking
		void setFirst(std::string f){firstName = f;}
		void setLast(std::string l){lastName = l;}
		void setFandom(bool y){YankeesFan = y;}

		// It is a good idea to do input checking on some set functions in case the usage is incorrect;
		bool setYear(int year){
			if(year > 2021){
				std::cout << "Impossible to be born after the current year\n";

				return 0;
			}
			else{
				birthYear = year;
				return 1;
			}
		} 
	
		// get functions (or accessor functions) return private variables from a public function.  This let's other programmers see private values without direct access to them.
		std::string getFirst(){return firstName;}
		std::string getLast(){return lastName;}
		int getYear(){return birthYear;}
		bool getFandom(){return YankeesFan;}
		
};

int main(){

	person_c people[2]; // can be used as array also

	for(int i = 0; i < 2; i++){
		people[i].createAPerson();
	}

	for(int i = 0; i < 2; i++){
		people[i].printAPerson(); 
	}

	person_c newPerson;
	int year;
	bool worked;
	do{		// this will use the set year feedback/return to determine if the input was in the correct format/bounds
		std::cout << "Give a new year for the birth year:";
		std::cin >> year;
		worked = newPerson.setYear(year);
		if(worked)
			std::cout << "The year worked!\n";
		else
			std::cout << "The year didn't work!\n";
	}while(!worked);
	
	return 0;
}

void person_c::createAPerson(){ // because the function is now encapsulated or grouped with the private section of the class, there is no need to pass in the variable, as it is already in the scope

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

void person_c::printAPerson(){ // because the function is now encapsulated or grouped with the private section of the class, there is no need to pass in the variable, as it is already in the scope
	// same code as before, just with a local variable name
	std::cout << firstName << " " << lastName << ", born in " << birthYear << ", is ";

	if(!YankeesFan)
		std::cout << "not "; 

	std::cout << "a fan of the New York Yankees\n";
		return;
}