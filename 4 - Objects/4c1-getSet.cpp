/************
Let's see another objects example.

In this case, we will use countries.
************/

#include <iostream>
#include <string>

class country_c{
	private:
		int population;
		int GDP;
		std::string name;

	public:
		void fillInformation(); // we can prototype here also
		void printInformation();

		// get functions (or accessor functions) return private variables from a public function.  This let's other programmers see private values without direct access to them.
		int getPopulation(){return population;}  
		int getGDP(){return GDP;}
		std::string getName(){return name;}

		// set functions (or mutator functions) set the private variables from a public functions; it is also a good idea to add input checking here, but is not required; in this case, we won't do that checking
		void setPopulation(int p){population = p;}
		void setGDP(int g){GDP = g;}
		void setName(std::string n){name = n;}


};

int main(){
	country_c firstCountry;
	firstCountry.fillInformation();

	country_c anotherCountry;
	anotherCountry.fillInformation();

	firstCountry.printInformation();
	anotherCountry.printInformation();

	int newGDP = 0;
	std::cout << "The country of " << firstCountry.getName() << " just discovered a large pile of vibranium (a fake, expensive metal). Enter their new GDP: ";
	std::cin >> newGDP;
	firstCountry.setGDP(newGDP);
	firstCountry.printInformation();

}


void country_c::fillInformation(){ // When we do the function definition, we need to give it the correct namespace
	std::cout << "Enter the name of the country, the population, and the GDP (in US dollars)\n";
	std::cin >> name >> population >> GDP;
			// note you don't need to call the namespace here for the class, because it is identified in the function header
	return;
}


void country_c::printInformation(){
	std::cout << "The country of " << name << " has " << population << " people and produces approximately " << GDP << " in US dollars\n";

}