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

		// Constructors don't have return, but can have inputs.
		// They are called when the object is instantiated, and then not again.
		// They are useful in initializing object variables and other "one time" operations that happen when the object is created. 
		// Here we have two versions
		person_c(){	
			std::cout << "A new person was created with the following default values. Values can be changed if you call the set functions later.\n";
			firstName = "TemporaryFirstName";
			lastName = "TemporaryLastName";
			birthYear = 0;
			YankeesFan = true;
			printAPerson(); // the constructors can call other functions
		}
		person_c(std::string f, std::string l, int by, bool yf){
			std::cout << "A new person was created with the following input values.\n";
			firstName = f;
			lastName = l;
			birthYear = by;
			YankeesFan = yf;
			printAPerson(); // the constructors can call other functions
		}
		// Destructors are called when an object is destroyed.  That could be at the end of the scope of the function, at the end of the program, or if you used the new function (more later) when you use the delete function (more later)
		~person_c(){
			std::cout << "The object of person: " << firstName << " " << lastName << " has been destructed.\n";
		}

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

	person_c emptyPerson; // this calls the empty constructor; note there are no ()
	std::cout << "Let's fill in the details:\n";
	emptyPerson.createAPerson();
	emptyPerson.printAPerson();

	person_c fullPerson("Ada", "Lovelace", 1815, true); // this calls the constructor that has inputs (inputs can be hardcoded or given as user/file inputs)
	fullPerson.printAPerson();
	
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