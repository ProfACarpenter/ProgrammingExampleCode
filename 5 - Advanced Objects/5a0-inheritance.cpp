/*********
Inheritance takes a base class and creates new derived classes based off of it.  The derived classes add and adapt that base class.  
*********/

#include <iostream>
#include <string>

class item_c{
	protected: //instead of using private, when we do inheritance, we want to use protected, which will let us use the variables in derived classes as though they are public, but the variables are still private to the outside
		std::string name;
		float price;
	public:
		void setName(std::string n){name = n;}
		void setPrice(bool p){price = p;} 
		std::string getName(){return name;}
		float getPrice(){return price;}

		void printAll(){
			std::cout << name << ": " << "$" << price << std::endl;
		}
		
		item_c():name("empty"),price(0.0){
			std::cout << "Empty item created.\n";
		}
		item_c(std::string n, float p):name(n), price(p){
			std::cout << name << " created.\n";
		}
		~item_c(){
			std::cout << name << " destructed.\n";
		}

		void printItem(){
			std::cout << name << " cost(s) $" << price << std::endl;
		}
};

class produce_c:public item_c{
	protected:
		float pickDate;
		float weight;

	public:
		float getPickDate(){return pickDate;}
		float getWeight(){return weight;}
		void setPickDate(float pd){pickDate = pd;}
		void setWeight(float w){weight = w;}

		bool isFresh(float today){
			if(today < pickDate)
				return false;
			else
				return true;
		}

		produce_c():pickDate(0.0),weight(0.0),item_c("empty",0.0){
			std::cout << "Empty produce created.\n";
		}
		produce_c(std::string n, float p, float pd, float w):item_c(n,p),pickDate(pd),weight(w){
			std::cout << name << " created.\n";
		}
		~produce_c(){
			std::cout << name << " destructed.\n";
		}

		void printProduce(){
			std::cout << weight << " grams of " << name << ", picked on " << pickDate << " costs $" << price << std::endl;
		}

};

class bulkItems_c:public item_c{
	protected:
		float weight;

	public:
		void setWeight(float w){weight = w;}
		float getWeight(){return weight;}

		bulkItems_c():weight(0.0),item_c("empty",0.0){
			std::cout << "Empty produce created.\n";
		}
		bulkItems_c(std::string n, float p, float w):item_c(n,p),weight(w){
			std::cout << name << " created.\n";
		}
		~bulkItems_c(){
			std::cout << name << " destructed.\n";
		}

		float pricePerGram(){
			return price/weight;
		}

		void printBulk(){
			std::cout << weight << " grams of " << name << " costs $" << price << std::endl;
		}
};

int main(){

	item_c item("Cheez-its", 2.49);
	produce_c produce("Broccoli", 1.99, 4.01, 1.1);
	bulkItems_c bulk("Nuts", 7.99, 2.5);

	std::cout << "-------" << std::endl;
	item.printItem();
	produce.printProduce();
	bulk.printBulk();

	float today = 7.18;
	if(produce.isFresh(today))
		std::cout << produce.getName() << " is fresh.\n";
	else
		std::cout << produce.getName() << " is expired. Don't eat it!\n";

	std::cout << "-------" << std::endl;

	
}