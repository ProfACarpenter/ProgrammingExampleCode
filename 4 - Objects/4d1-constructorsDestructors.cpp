/************
We will build more constructors/destructors here.
************/

#include <iostream>
#include <string>

class country_c{
	private:
		int population;
		int GDP; //let's do this per capita, just for smaller numbers
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


		// Constructors and destructor
	public:
		~country_c(){ std::cout << "This country object is being destructed: " << name << std::endl; }

		country_c(){ 
			std::cout << "Country with no name/info created.\n";
			name = "Unknown";
			population = 0;
			GDP = 0;
		}
		country_c(std::string n){ 
			name = n;
			std::cout << name << " was created, but we don't know the population or GDP.\n";
			population = 0;
			GDP = 0;
		}
		country_c(std::string n, int p, int g){ 
			name = n;
			std::cout << name << " was created with a population of " << p << " and per capita GDP of " << g << std::endl;
			population = p;
			GDP = g;
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