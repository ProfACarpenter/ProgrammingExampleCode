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

};

int main(){
	country_c firstCountry;
	firstCountry.fillInformation();

	country_c anotherCountry;
	anotherCountry.fillInformation();

	firstCountry.printInformation();
	anotherCountry.printInformation();

}

void country_c::fillInformation(){ // When we do the function definition, we need to give it the correct namespace
	std::cout << "Enter the name of the country, the population, and the GDP (in US dollars)\n";
	std::cin >> name >> population >> GDP;
			// note you don't need to call the namespace here for the class, because it is identified in the function header
	return;
}

void country_c::printInformation(){
	std::cout << "The country of " << name << " has " << population << " people and produces approximately " << GDP << " in US dollars\n";
	return;
}