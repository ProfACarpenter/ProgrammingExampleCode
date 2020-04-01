/*************
Initialization Lists are used in constructors to simplify the body of the code, and will be used more later for inheritance.
*************/

#include <iostream>
#include <string>

class country_c{
	private:
		int population;
		int GDP; //let's do this per capita, just for smaller numbers
		std::string name;

	public:
		void fillInformation(); 
		void printInformation();

		int getPopulation(){return population;}  
		int getGDP(){return GDP;}
		std::string getName(){return name;}

		void setPopulation(int p){population = p;}
		void setGDP(int g){GDP = g;}
		void setName(std::string n){name = n;}

	public:
		~country_c(){ std::cout << "This country object is being destructed: " << name << std::endl; }

		// initialization lists can be filled with hardcoded or filled by variables from the input
		country_c():name("Unknown"),population(0), GDP(0){ 
			std::cout << "Country with no name/info created.\n";
		}
		country_c(std::string n):name(n),population(0),GDP(0){ 
			std::cout << name << " was created, but we don't know the population or GDP.\n";
		}
		country_c(std::string n, int p, int g):name(n),population(p),GDP(g){ 
			std::cout << name << " was created with a population of " << p << " and per capita GDP of " << g << std::endl;
		}

};

int main(){
	country_c unknownCountry; // calls the constructor with no inputs
	 
	country_c justTheNameCountry("USA"); // calls the constructor with just a name

	country_c fullyInformedCountry("Canada",37590000,45447); // calls the constructor with name and other information
	
	std::cout << "--------------------------------\n";
	unknownCountry.printInformation();
	justTheNameCountry.printInformation();
	fullyInformedCountry.printInformation();

	

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