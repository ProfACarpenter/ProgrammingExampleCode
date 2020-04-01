/*************
Initialization Lists are used in constructors to simplify the body of the code, and will be used more later for inheritance.
*************/

#include <iostream>
#include <string> 

class person_c { 
	private: 
		std::string firstName;  
		std::string lastName;
		int birthYear;
		bool YankeesFan;

	public: 
		
		person_c(){	
			std::cout << "A new person was created with the following default values. Values can be changed if you call the set functions later.\n";
			firstName = "TemporaryFirstName";
			lastName = "TemporaryLastName";
			birthYear = 0;
			YankeesFan = true;
			printAPerson(); 
		}
		person_c(std::string f, std::string l, int by, bool yf):firstName(f),lastName(l),birthYear(by),YankeesFan(yf){
			std::cout << "A new person was created with the following input values.\n";
			printAPerson(); 
			// note the file initializations are now in the list
		}
		
		~person_c(){
			std::cout << "The object of person: " << firstName << " " << lastName << " has been destructed.\n";
		}

		void printAPerson();
		void createAPerson();

		void setFirst(std::string f){firstName = f;}
		void setLast(std::string l){lastName = l;}
		void setFandom(bool y){YankeesFan = y;}

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
	
		std::string getFirst(){return firstName;}
		std::string getLast(){return lastName;}
		int getYear(){return birthYear;}
		bool getFandom(){return YankeesFan;}
		
};

int main(){

	person_c emptyPerson; 
	std::cout << "Let's fill in the details:\n";
	emptyPerson.createAPerson();
	emptyPerson.printAPerson();

	person_c fullPerson("Ada", "Lovelace", 1815, true); 
	fullPerson.printAPerson();
	
	return 0;
}

void person_c::createAPerson(){ 

	std::cout << "Enter a first name: ";
	std::cin >> firstName; 

	std::cout << "Enter a last name: ";
	std::cin >> lastName;

	std::cout << "Enter a birth year: ";
	std::cin >> birthYear;

	std::cout << "Are you a Yankees Fan? Yes (1), No (0)";
	std::cin >> YankeesFan;

	return; 
}

void person_c::printAPerson(){ 
	
	std::cout << firstName << " " << lastName << ", born in " << birthYear << ", is ";

	if(!YankeesFan)
		std::cout << "not "; 

	std::cout << "a fan of the New York Yankees\n";
		return;
}